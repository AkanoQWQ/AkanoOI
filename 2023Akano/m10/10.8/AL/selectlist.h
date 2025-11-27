#pragma once
#include<bits/stdc++.h>
using namespace std;

//funcP 既是无参数无返回值函数的指针类型
//这东西真的很绕,不容易搞得懂
typedef void (*funcP)();

static string select_list_empty_content = "这是个空列表";
struct SelectList{
	SelectList* father;
	struct Node{
		string content;
		SelectList* next;
		funcP func;
		Node() = default;
		Node(const string& _content,SelectList* _next,funcP _func){
			content = _content,next = _next,func = _func;
			return ;
		}
	};
	typedef vector<Node>::iterator Itor;
	vector<Node> option;
	Itor nowIt;
	inline void CheckInit(){
		return ;
	}
	inline void MoveUp(){
		if(nowIt == option.begin()){
			nowIt = prev(option.end());
		}else{
			nowIt--;
		}
		return ;
	}
	inline void MoveDown(){
		nowIt++;
		if(nowIt == option.end()){
			nowIt = option.begin();
		}
		return ;
	}
	inline void Output(){
		for(auto it = option.begin();it != option.end();it++){
			cout<<it->content;
			if(it == nowIt){
				cout<<" ←";
			}
			cout<<endl;
		}
		return ;
	}
	inline void Push(const string& _content,SelectList* _next,funcP _func){
		if(option.back().content == select_list_empty_content){
			option.pop_back();
		}
		option.emplace_back(_content,_next,_func);
		nowIt = option.begin();
		if(_next != nullptr)_next->father = this;
		return ;
	}
	inline bool DeleteByContent(const string& str){
		bool ret = false;
		for(auto it = option.begin();it != option.end();it++){
			if(it->content == str){
				option.erase(it);
				ret = true;
				break;
			}
		}
		if(option.size() == 0){
			option.emplace_back(select_list_empty_content,nullptr,nullptr);
		}
		nowIt = option.begin();
		return ret;
	}
	SelectList(){
		father = nullptr;
		option.emplace_back(select_list_empty_content,nullptr,nullptr);
		nowIt = option.begin();
		return ;
	}
};

class SelectListRunner{
private:
	SelectList* now;
public:
	inline void Refresh(){
		system("cls");
		now->Output();
		return ;
	}
	inline bool EnterNext(){//返回是否成功
		if(now->nowIt->next != nullptr){
			now = now->nowIt->next;
			return true;
		}
		return false;
	}
	inline bool ExecuteNow(){//马上执行,返回是否成功
		if(now->nowIt->func != nullptr){
			now->nowIt->func();
			return true;
		}
		return false;
	}
	inline funcP Execute(){//返回执行的指针,记住它不会立刻执行,为了防止马上被Refresh掉
		return now->nowIt->func;
	}
	inline funcP Enter(){//只有执行事件返回 指针
		funcP ret = Execute();
		EnterNext();
		return ret;
	}
	inline void EnterFather(){
		if(now->father != nullptr){
			now = now->father;
		}
		return ;
	}
	inline void MoveUp(){
		now->MoveUp();
		return ;
	}
	inline void MoveDown(){
		now->MoveDown();
		return ;
	}
	inline void SetMain(SelectList* _main){
		now = _main;
		return ;
	}
	inline void DefaultController(char ch){
		funcP event = nullptr;
		if(ch == 'a'){
			EnterFather();
		}else if(ch == 'd'){
			event = Enter();
		}else if(ch == 'w'){
			MoveUp();
		}else if(ch == 's'){
			MoveDown();
		}else if(int(ch) == 8){//删除
			EnterFather();
		}else if(int(ch) == 10 || int(ch) == 13){
			event = Enter();
		}
		Refresh();
		if(event != nullptr){
			event();
		}
		return ;
	}
};

