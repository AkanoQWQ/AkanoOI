/*
comp.h
inline void PreCompile(const string name){//预先编译data,std,code三个exe 
	CreateDirectory(pre_file.c_str(),NULL);
	Compile(name+".cpp",pre_file + code_name);
	Compile(name+"_std.cpp",pre_file + std_name);
	Compile(name+"_data.cpp",pre_file + data_name);
	return ;
}

comp.h
inline long long Run(){//执行data,std,code三个exe 
	long long result = 0;
	IO::Write(pre_file + in_name);
	result |= Execute(pre_file + data_name).first;//data
	IO::Open(pre_file + in_name);
	IO::Write(pre_file + out_name);
	result |= Execute(pre_file + code_name).first;//main
	IO::Open(pre_file + in_name);
	IO::Write(pre_file + ans_name);
	result |= Execute(pre_file + std_name).first;//std
	IO::Open("CON");
	IO::Write("CON");
	return result;
}

comp.h
inline pair<int,vector<string> > Compare(auto _ouf[],auto _ans[],int comp_length){//比较两数组内容 
	pair<int,vector<string> > ret;
	//注:GetLength函数貌似有误,详情见basic.h
	//该段代码已废弃 
//	int len = min(GetLength(_ouf),GetLength(_ans));
//	if(len < comp_length){
//		cout<<"WARNING : Your compArray is too short!"<<endl;
//	}
//	comp_length = min(comp_length,len);
	for(int i = 0;i <= comp_length;i++){
		if(_ouf[i] != _ans[i]){
			++ret.first;
			string errInf = "In the "+TransToString(i);
			errInf += " element,read " + TransToString(_ouf[i]);
			errInf += " but expected "+ TransToString(_ans[i]);
			ret.second.push_back(errInf);
		}
	}
	return ret;
}

comp.h
inline void Delete(){//删除data,std,code三个文件 
	DeleteFile((pre_file + code_name).c_str());
	DeleteFile((pre_file + std_name).c_str());
	DeleteFile((pre_file + data_name).c_str());
	DeleteFile((pre_file + in_name).c_str());
	DeleteFile((pre_file + out_name).c_str());
	DeleteFile((pre_file + ans_name).c_str());
	RemoveDirectory(pre_file.c_str());
	return ;
}

原 AOJ.cpp
//Akano Offline Judge Version 2023.8.15
//BASIC ON AL ver2023.8.15
//需要AL ver2023.8.15及以上 
//2023.8.15后放弃维护 
#include<bits/stdc++.h>
#include<AL/comp.h>//需要使用install.cmd安装AL 
using namespace std;
using pivs = pair<int,vector<string> >;
const int ArraySize = 6e6 + 6;//注意比较数组的大小,应该和答案输出的元素个数一致 
int T = 1000;
string ouf[ArraySize],ans[ArraySize];//默认使用string 
string main_name;
bool KEEP_FILE = false;
int main(){
	cin>>main_name>>T;
	PreCompile(main_name);
	for(int turn = 1;turn <= T;turn++){
		cout<<turn<<" CHECK"<<'\n';
		long long result = Run();
		if(result != 0){//Error
			KEEP_FILE = true;
			break;
		}
		int n1 = FileIntoArray(pre_file + out_name,ouf);
		int n2 = FileIntoArray(pre_file + ans_name,ans);
		if(n1 < n2){
			KEEP_FILE = true;
			cout<<"Answer too short"<<'\n';break;
		}
		if(n1 > n2){
			KEEP_FILE = true;
			cout<<"Answer too long"<<'\n';break;
		}
		pivs ret = Compare(ouf,ans,min(n1,n2));
		if(ret.first != 0 || !ret.second.empty()){
			KEEP_FILE = true;
			cout<<ret.first<<" WA in "<<min(n1,n2)<<endl;
			for(auto warn : ret.second){
				cout<<warn<<'\n';
			}
			break;
		}
	}
	if(KEEP_FILE == false)Delete();
	Error::OutputFile("AOJ_err");
	return 0;
}
//可能的BUG
//1.cmd提示你无法正确打开某个exe
//在任务管理器中检查该exe是否正常关闭,是否有一个不明所以的cmd.exe
//发现以上异常,结束对应进程 
//2.__MAIN__文件没有正常删除
//在任务管理器中检查code.exe , std.exe , data.exe 是否正常关闭,是否有一个不明所以的cmd.exe
//发现以上异常,结束对应进程 

原output.h
#pragma once
#include<bits/stdc++.h>
using namespace std;
struct MyOutput{
	
}out;
template<typename T>
MyOutput& operator<<(MyOutput& out,const vector<T>& vec){
	for(auto i : vec){
		cout<<i<<" ";
	}
	return out;
}
template<typename T>
MyOutput& operator<<(MyOutput& out,const set<T>& st){
	for(auto i : st){
		cout<<i<<" ";
	}
	return out;
}
template<typename T>
MyOutput& operator<<(MyOutput& out,priority_queue<T> q){
	while(!q.empty()){
		cout<<q.top()<<" ";
		q.pop();
	}
	return out;
}
template<typename T>
MyOutput& operator<<(MyOutput& out,queue<T> q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	return out;
}
template<typename T>
MyOutput& operator<<(MyOutput& out,stack<T> stk){
	while(!stk.empty()){
		cout<<stk.top()<<" ";
		stk.pop();
	}
	return out;
}
template<typename T1,typename T2>
MyOutput& operator<<(MyOutput& out,const pair<T1,T2>& pr){
	cout<<pr.first<<" "<<pr.second;
	return out;
}
template<typename T>
MyOutput& operator<<(MyOutput& out,const T& content){
	cout<<content;
	return out;
}
container.h 中废弃的旧Treap (极其史山)
//常数巨大的 Treap 平衡树,基本对标 set(实际上是multiste)
//然而常数极其大,有待优化
//Insert 插入某值
//Delete 删除某值 
//GetRank 获得值的排名
//GetVal 获得排名的值 (迭代器) 
//GetPre 获得前驱 (迭代器) 
//GetNext 获得前驱 (迭代器)
//Range 获得树的有序遍历 (等价于 O(n) 的 for auto)
//begin 是 O(logn) 的 
template<typename T>
class Treap{
public:
	struct Node{
		int key;
		size_t tot,sz;
		T val;
		Node *l,*r;
		inline int Lsize(){
			if(l == nullptr)return 0;
			return l->sz;
		}
		inline int Rsize(){
			if(r == nullptr)return 0;
			return r->sz;
		}
		inline int Lkey(){
			if(l == nullptr)return -1;
			return l->key;
		}
		inline int Rkey(){
			if(r == nullptr)return -1;
			return r->key;
		}
		Node(T _val,int _key){
			val = _val;
			key = _key;
			tot = sz = 1;
			l = r = nullptr;
		}
		Node(){
			key = tot = sz = 0;
			val = T();
			l = nullptr,r = nullptr;
		}
	};
	
	struct iterator{
		Node* node;
		Treap* belong;
		T& operator*(){
			return node->val;
		}
		bool operator==(nullptr_t npt){
			return node == npt;
		}
		bool operator!=(nullptr_t npt){
			return !(this == npt);
		}
		bool operator==(iterator it){
			return node == it.node;
		}
		bool operator!=(iterator it){
			return !(*this == it);
		}
		iterator& operator++(){
			node = belong->GetNext(belong->root,node->val).node;
			return *this;
		}
		iterator operator++(int){//可以这么写吗?? 
			iterator old = *this;
			operator++();
			return old;
		}
		iterator(Node* _node,Treap* _belong){
			belong = _belong;
			node = _node;
			return ;
		}
		iterator(){
			belong = nullptr;
			node = nullptr;
			return ;
		}
	};
private:
	const static int keyINF = 1e9;
	mt19937 rander;
	
	typedef Node* NodeItor;
	NodeItor root;
	
	inline void PushUp(NodeItor& p){
		if(p == nullptr)return ;
		p->sz = p->Lsize() + p->Rsize() + p->tot;
		return ;
	}
	inline void Zag(NodeItor& p){//左旋 
		NodeItor q = p->r;
		p->r = q->l;
		q->l = p;
		p = q;
		PushUp(p);
		PushUp(p->l);
		return ;
	}
	inline void Zig(NodeItor& p){//右旋 
		NodeItor q = p->l;
		p->l = q->r;
		q->r = p;
		p = q;
		PushUp(p);
		PushUp(p->r);
		return ;
	}
	void Insert(NodeItor& p,T val){
		if(p == nullptr){
			p = new Node(val,rander() % keyINF);
			return ;
		}
		if(val == p->val){
			p->tot++;
		}else if(val < p->val){
			Insert(p->l,val);
			if(p->key < p->Lkey()){
				Zig(p);
			}
		}else{
			Insert(p->r,val);
			if(p->key < p->Rkey()){
				Zag(p);
			}
		}
		PushUp(p);
		return ;
	}
	void Delete(NodeItor& p,T val){
		if(p == nullptr)return ;
		if(p->val == val){
			if(p->tot >= 2){
				--p->tot;
			}else if(p->l != nullptr || p->r != nullptr){
				if(p->Lkey() > p->Rkey()){
					Zig(p);
					Delete(p->r,val);
				}else{
					Zag(p);
					Delete(p->l,val);
				}
			}else{
				delete p;
				p = nullptr;
			}
		}else if(val < p->val){
			Delete(p->l,val); 
		}else if(val > p->val){
			Delete(p->r,val);
		}
		PushUp(p);
		return ;
	}
	size_t GetRank(NodeItor p,T val){
		if(p == nullptr)return 1;
		if(val == p->val){
			return p->Lsize() + 1;
		}else if(val < p->val){
			return GetRank(p->l,val);
		}else if(val > p->val){
			return GetRank(p->r,val) + p->tot + p->Lsize();
		}
		return 10181108;
	}
	iterator GetVal(NodeItor p,T k){
		if(k <= p->Lsize()){
			return GetVal(p->l,k);
		}else if(k <= int(p->Lsize() + p->tot)){
			return iterator(p,this);
		}
		return GetVal(p->r,k - p->Lsize() - p->tot);
	}
	iterator GetPre(NodeItor p,T val){
		if(p == nullptr)return iterator(nullptr,this);
		if(val <= p->val){
			return GetPre(p->l,val);
		}else{
			iterator ret = GetPre(p->r,val);
			if(ret.node == nullptr)ret = iterator(p,this);
			return ret;
		}
	}
	iterator GetNext(NodeItor p,T val){
		if(p == nullptr)return iterator(nullptr,this);
		if(val < p->val){
			iterator ret = GetNext(p->l,val);
			if(ret.node == nullptr)ret = iterator(p,this);
			return ret;
		}else{
			return GetNext(p->r,val);
		}
	}
	void dfs(NodeItor u,vector<T>& vec){
		if(u->l != nullptr)dfs(u->l,vec);
		vec.push_back(u->val);
		if(u->r != nullptr)dfs(u->r,vec);
		return ;
	}
public:
	inline void Insert(T val){
		Insert(root,val);
		return ;
	}
	inline void Delete(T val){
		Delete(root,val);
		return ;
	}
	inline size_t GetRank(T val){
		return GetRank(root,val); 
	}
	inline iterator GetVal(T k){
		return GetVal(root,k);
	}
	inline iterator GetPre(T val){
		return GetPre(root,val);
	}
	inline iterator GetNext(T val){
		return GetNext(root,val);
	}
	inline iterator begin(){//logn 复杂度! 
		NodeItor itor = root;
		while(itor != nullptr && itor->l != nullptr)itor = itor->l;
		return iterator(itor,this);
	}
	inline iterator end(){
		return iterator(nullptr,this);
	}
	vector<T> Range(){
		vector<T> ret;
		dfs(root,ret);
		return ret;
	}
	Treap(){
		rander.seed(time(0));
		return ;
	}
};

//基础 Treap,更为基础的 Treap......
//相比 Treap 来说常数更小,然而还是很大
//唯一区别是取消了迭代器,前驱后继返回的是 pair<T,bool> 表示前驱后继值和是否找到(有可能没找到) 
template<typename T>
class BasicTreap{
private:
	const static int keyINF = 1e9;
	mt19937 rander;
	struct Node{
		int key;
		size_t tot,sz;
		T val;
		Node *l,*r;
		inline int Lsize(){
			if(l == nullptr)return 0;
			return l->sz;
		}
		inline int Rsize(){
			if(r == nullptr)return 0;
			return r->sz;
		}
		inline int Lkey(){
			if(l == nullptr)return -1;
			return l->key;
		}
		inline int Rkey(){
			if(r == nullptr)return -1;
			return r->key;
		}
		Node(T _val,int _key){
			val = _val;
			key = _key;
			tot = sz = 1;
			l = r = nullptr;
		}
		Node(){
			key = tot = sz = 0;
			val = T();
			l = nullptr,r = nullptr;
		}
	};
	
	typedef Node* iterator;
	iterator root;
	
	inline void PushUp(iterator& p){
		if(p == nullptr)return ;
		p->sz = p->Lsize() + p->Rsize() + p->tot;
		return ;
	}
	inline void Zag(iterator& p){//左旋 
		iterator q = p->r;
		p->r = q->l;
		q->l = p;
		p = q;
		PushUp(p);
		PushUp(p->l);
		return ;
	}
	inline void Zig(iterator& p){//右旋 
		iterator q = p->l;
		p->l = q->r;
		q->r = p;
		p = q;
		PushUp(p);
		PushUp(p->r);
		return ;
	}
	void Insert(iterator& p,T val){
		if(p == nullptr){
			p = new Node(val,rander() % keyINF);
			return ;
		}
		if(val == p->val){
			p->tot++;
		}else if(val < p->val){
			Insert(p->l,val);
			if(p->key < p->Lkey()){
				Zig(p);
			}
		}else{
			Insert(p->r,val);
			if(p->key < p->Rkey()){
				Zag(p);
			}
		}
		PushUp(p);
		return ;
	}
	void Delete(iterator& p,T val){
		if(p == nullptr)return ;
		if(p->val == val){
			if(p->tot >= 2){
				--p->tot;
			}else if(p->l != nullptr || p->r != nullptr){
				if(p->Lkey() > p->Rkey()){
					Zig(p);
					Delete(p->r,val);
				}else{
					Zag(p);
					Delete(p->l,val);
				}
			}else{
				delete p;
				p = nullptr;
			}
		}else if(val < p->val){
			Delete(p->l,val); 
		}else if(val > p->val){
			Delete(p->r,val);
		}
		PushUp(p);
		return ;
	}
	size_t GetRank(iterator p,T val){
		if(p == nullptr)return 1;
		if(val == p->val){
			return p->Lsize() + 1;
		}else if(val < p->val){
			return GetRank(p->l,val);
		}else if(val > p->val){
			return GetRank(p->r,val) + p->tot + p->Lsize();
		}
		return 10181108;
	}
	T GetVal(iterator p,T k){
		if(k <= p->Lsize()){
			return GetVal(p->l,k);
		}else if(k <= int(p->Lsize() + p->tot)){
			return p->val;
		}
		return GetVal(p->r,k - p->Lsize() - p->tot);
	}
	pair<T,bool> GetPre(iterator p,T val){
		if(p == nullptr)return make_pair(T(),false);
		if(val <= p->val){
			return GetPre(p->l,val);
		}else{
			pair<T,bool> ret = GetPre(p->r,val);
			if(ret.second == false){
				ret = make_pair(p->val,true);
			}else if(p->val > ret.first){
				ret = make_pair(p->val,true);
			}
			return ret;
		}
	}
	pair<T,bool> GetNext(iterator p,T val){
		if(p == nullptr)return make_pair(T(),false);
		if(val < p->val){
			pair<T,bool> ret = GetNext(p->l,val);
			if(ret.second == false){
				ret = make_pair(p->val,true);
			}else if(p->val < ret.first){
				ret = make_pair(p->val,true);
			}
			return ret;
		}else{
			return GetNext(p->r,val);
		}
	}
	void dfs(iterator u,vector<T>& vec){
		if(u->l != nullptr)dfs(u->l,vec);
		vec.push_back(u->val);
		if(u->r != nullptr)dfs(u->r,vec);
		return ;
	}
public:
	inline void Insert(T val){
		Insert(root,val);
		return ;
	}
	inline void Delete(T val){
		Delete(root,val);
		return ;
	}
	inline size_t GetRank(T val){
		return GetRank(root,val); 
	}
	inline T GetVal(T k){
		return GetVal(root,k);
	}
	inline pair<T,bool> GetPre(T val){//返回找到的值和是否找到成功(可能根本没有找到) 
		return GetPre(root,val);
	}
	inline pair<T,bool> GetNext(T val){
		return GetNext(root,val);
	}
	vector<T> Range(){
		vector<T> ret;
		dfs(root,ret);
		return ret;
	}
};

未被加入到 container.h 中的 Deque 容器
效率太低咱找不到一个理由去使用它,这已经是第二次写了,加上MyAllocator的加持也没用
template<typename T>
class Deque{
private:
	struct Node;
	using Nodep = Node*;
	using cTr = const T&;
	struct Node{
		Nodep next,last;
		T val;
		Node(){
			next = last = nullptr;
			return ;
		}
	};
	Nodep head,tail;
	MyAllocator<Node> alloc;
public:
	inline void PushFront(cTr val){
		if(head == nullptr){
			head = tail = alloc();
			head->val = val;
			return ;
		}
		Nodep newHead = alloc();
		newHead->val = val;
		newHead->next = head,head->last = newHead;
		head = newHead;
		return ;
	}
	inline void PopFront(){
		if(head == nullptr){
			throw "尝试空Deque进行PopFront!";
			return ;
		}
		if(head == tail)tail = nullptr;//特判,正确?
		head = head->next;
		if(head == nullptr)return ;
		alloc[head->last];
		head->last = nullptr;
		return ;
	}
	inline void PushBack(cTr val){
		if(head == nullptr){
			head = tail = alloc();
			tail->val = val;
			return ;
		}
		Nodep newTail = alloc();
		newTail->val = val;
		newTail->last = tail,tail->next = newTail;
		tail = newTail;
		return ;
	}
	inline void PopBack(){
		if(tail == nullptr){
			throw "尝试空Deque进行PopBack!";
			return ;
		}
		if(head == tail)head = nullptr;//特判,正确?
		tail = tail->last;
		if(tail == nullptr)return ;
		alloc[tail->next];
		tail->next = nullptr;
		return ;
	}
	inline T& Front(){
		if(head == nullptr){
			throw "尝试对空Deque进行Front!";
		}
		return head->val;
	}
	inline T& Back(){
		if(tail == nullptr){
			throw "尝试对空Deque进行Front!";
		}
		return tail->val;
	}
	inline bool Empty(){
		return (head == nullptr);
	}
	Deque(){
		head = tail = nullptr;//重要
		return ;
	}
};
*/
