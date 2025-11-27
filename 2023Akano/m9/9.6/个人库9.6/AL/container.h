#pragma once
#include<bits/stdc++.h>
using namespace std;

namespace Container{
	
	//SegmentTree : 支持区间加减,查询区间和的线段树 
	//T : 数值种类,只能是数字类型
	//SIZE : 线段树的大小 
	//Build() : 初始化并置初值为 0
	//Build(T arr) : 以数组为初始内容初始化
	//Change(int l,int r,int val) : 对 [l,r] 区间加上 val 的区间操作
	//Query(int l,int r) : 询问 [l,r] 区间的和
	//SegmentTree() : 初始化空的线段树
	//SegmentTree(T arr) : 以数组为初始内容初始化线段树 
	template<typename T>
	struct SegmentTreeNode{
		T val,lazy;
		int len;
		SegmentTreeNode(){val = lazy = len = 0;}
	};
	template<typename T,int SIZE>
	class SegmentTree{
		private:
			SegmentTreeNode<T> node[(SIZE + 4) * 4];
			int OBJL,OBJR,_val;
			T* arr;
			inline void PushUp(int p){
				node[p].val = node[p*2].val + node[p*2+1].val;
				return ;
			}
			inline void PushDown(int p){
				if(node[p].lazy == 0)return ;
				node[p*2].val += node[p*2].len * node[p].lazy;
				node[p*2+1].val += node[p*2+1].len * node[p].lazy;
				node[p*2].lazy += node[p].lazy,node[p*2+1].lazy += node[p].lazy;
				node[p].lazy = 0;
				return ;
			}
			void Build(int p,int l,int r){
				node[p].len = r - l + 1;
				if(l == r){
					if(arr != nullptr){
						node[p].val = arr[l];
					}
					return ;
				}
				const int mid = (l + r) >> 1;
				Build(p*2,l,mid),Build(p*2+1,mid+1,r); 
				PushUp(p);
				return ;
			}
			void ChangeInner(int p,int l,int r){
				if(OBJL <= l && r <= OBJR){
					node[p].val += _val * node[p].len;
					node[p].lazy += _val;
					return ;
				}
				const int mid = (l + r) >> 1;
				PushDown(p);
				if(mid >= OBJL)ChangeInner(p*2,l,mid);
				if(mid < OBJR)ChangeInner(p*2+1,mid+1,r);
				PushUp(p);
				return ;
			}
			T Query(int p,int l,int r){
				if(OBJL <= l && r <= OBJR){
					return node[p].val;
				}
				const int mid = (l + r) >> 1;
				T ret = 0;
				PushDown(p);
				if(mid >= OBJL)ret = Query(p*2,l,mid);
				if(mid < OBJR)ret += Query(p*2+1,mid+1,r);
				return ret;
			}
		public:
			inline void Build(){
				Build(1,1,SIZE);
				return ;
			}
			inline void Build(T* _arr){
				arr = _arr;
				Build(1,1,SIZE);
				arr = nullptr;
				return ;
			}
			inline void Change(int l,int r,int inval){
				OBJL = l,OBJR = r,_val = inval;
				ChangeInner(1,1,SIZE);
				return ;
			}
			inline T Query(int l,int r){
				OBJL = l,OBJR = r;
				return Query(1,1,SIZE);
			}
			SegmentTree(){
				Build();
				return ;
			}
			SegmentTree(T* _arr){
				Build(_arr);
				return ;
			}
	};
	
	//BIT : 支持单点修改,区间查询的树状数组
	//T : 内容的种类,要求是数字
	//SIZE : 容器大小
	//Change(int x,T val) : 给 x 位置加上 val
	//Query(int l,int r) : 询问 [l,r] 区间和 
	template<typename T,int SIZE>
	class BIT{
		private:
			T val[SIZE];
			inline int Lowbit(int x){
				return x & (-x);
			}
			inline T QueryPre(int x){
				T ret = 0;
				while(x){
					ret += val[x];
					x -= Lowbit(x);
				}
				return ret;
			}
		public:
			inline void Change(int x,T _val){
				while(x <= SIZE){
					val[x] += _val;
					x += Lowbit(x);
				}
				return ;
			}
			inline T Query(int l,int r){
				return QueryPre(r) - QueryPre(l-1);
			}
	};
	
	//ClearableArray : 支持清空操作过的元素的可清空数组
	//T : 内容类型,无限制
	//SIZE : 容器大小
	//operator[x] : 以下标访问内容
	//at(int x) :  代检查越界的以下标访问内容
	//Clear() : 清空从上次清空以来操作过的内容,调用 T 的构造函数 
	template<typename T,int SIZE>
	class ClearableArray{
		private:
			T _content[SIZE];
			bool _vis[SIZE];
			queue<int> clearQueue;
		public:
			T& operator[](int _x){
				if(!_vis[_x]){
					_vis[_x] = true,clearQueue.push(_x);
				}
				return _content[_x];
			}
			inline T& at(int _x){
				assert(_x < SIZE && _x >= 0);
				return operator[](_x);
			}
			inline void Clear(){
				while(!clearQueue.empty()){
					const int _u = clearQueue.front();
					clearQueue.pop();
					_vis[_u] = false;
					_content[_u] = T();
				}
				return ;
			}
			inline int Size(){
				return clearQueue.size();
			}
	};
	
	//HashMap : 哈希表,实现 unordered_map 的效果,虽然貌似少量数据情况下效率还不如 unordered_map 
	//Key : 键值,即下标的类型
	//Val : 值,存储值得类型  两者都不限
	//HashClass : 使用仿函数形式传进来的哈希函数
	//SIZE : 容器哈希值的大小,意思是说哈希值的取值范围
	//SIZE越大,越不容易产生哈希碰撞,然而并不是越大越好
	//operator[key] : 访问对应键值的值,如果没有则新建
	//HashMap(int size) : 创建一个空的 HashMap,并预留出 size 大小的空间 
	template<typename Key,typename Val>
	struct HashMapNode{
		Key key;
		Val val;
		int nxt;//索引范围int,也许需要使用更规范的类型
		HashMapNode(){key = Key(),val = Val(),nxt = 0;}
		HashMapNode(Key _key){key = _key,val = Val(),nxt = 0;}
	};
	template<typename Key,typename Val,typename HashClass,int SIZE>//SIZE一定是小于int的,索引需要装得下 
	class HashMap{
		typedef HashMapNode<Key,Val> Node;
		typedef typename vector<Node>::iterator iterator;//为了和普通容器保持一致 
		private:
			HashClass hasher = HashClass();
			int head[SIZE],tot;
			vector<Node> content;
			inline int FindIndex(const Key& key){
				const int hashVal = hasher(key) % SIZE;
				for(int i = head[hashVal];i;i = content[i].nxt){
					if(content[i].key == key)return i;
				}
				return 0;
			}
			inline int Insert(const Key& key){
				const int hashVal = hasher(key) % SIZE;
				int lst = head[hashVal];
				head[hashVal] = ++tot;
				content.emplace_back(key);
				content[tot].nxt = lst;
				return tot;
			}
		public:
			iterator begin(){//方便 for(auto) 遍历 
				return ++content.begin();//初始是0,要加一个元素 
			}
			iterator end(){
				return content.end();
			}
			Val& operator[](const Key& key){
				int idx = FindIndex(key);
				if(idx == 0)idx = Insert(key);
				return content[idx].val;
			}
			HashMap(){//初始一个空元素,下标为0,非常重要 
				content.emplace_back();
				return ;
			}
			HashMap(int initVal){
				content.reserve(initVal);
				content.emplace_back();
				return ;
			}
	};
	
	//HashSet : 哈希表,实现 unordered_set 的功能
	//Val,HashClass,SIZE : 同 HashMap 
	//Insert(Val val) : 插入值,返回插入是否成功(是否已有该元素) 
	//Find(Val val) : 查询是否已有该元素
	template<typename Val>
	struct HashSetNode{
		Val val;
		int nxt;
		HashSetNode(){val = Val(),nxt = 0;}
		HashSetNode(Val _val){val = _val,nxt = 0;}
	};
	template<typename Val,typename HashClass,int SIZE>
	class HashSet{
		typedef HashSetNode<Val> Node;
		typedef typename vector<Node>::iterator iterator;
		private:
			HashClass hasher = HashClass();
			int head[SIZE],tot;
			vector<Node> content;
			inline int FindIndex(const Val& val){
				const int hashVal = hasher(val) % SIZE;
				for(int i = head[hashVal];i;i = content[i].nxt){
					if(content[i].val == val)return i;
				}
				return 0;
			}
			inline int InsertContent(const Val& val){
				const int hashVal = hasher(val) % SIZE;
				int lst = head[hashVal];
				head[hashVal] = ++tot;
				content.emplace_back(val);
				content[tot].nxt = lst;
				return tot;
			}
		public:
			iterator begin(){//方便 for(auto) 遍历 
				return ++content.begin();//初始是0,要加一个元素 
			}
			iterator end(){
				return content.end();
			}
			inline bool Insert(const Val& val){
				int idx = FindIndex(val);
				if(idx)return false;
				InsertContent(val);
				return true;
			}
			inline bool Find(const Val& val){
				int idx = FindIndex(val);
				return (idx != 0);
			}
			HashSet(){//初始一个空元素,下标为0,非常重要 
				content.emplace_back();
				return ;
			}
			HashSet(int initVal){//初始一个空元素,下标为0,非常重要 
				content.reserve(initVal);
				content.emplace_back();
				return ;
			}
	};
}
