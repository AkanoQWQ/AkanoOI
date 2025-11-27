#pragma once
#include<bits/stdc++.h>
using namespace std;

namespace Container{
	
	//SegmentTree : 支持区间加减,查询区间和的线段树 
	//SIZE : 线段树的大小 
	//T : 数值种类,只能是数字类型
	//Build() : 初始化并置初值为 0
	//BuildArray(T* arr) : 以数组为初始内容初始化
	//Change(int l,int r,T val) : 对 [l,r] 区间加上 val 的区间操作
	//Query(int l,int r) : 询问 [l,r] 区间的和
	//SegmentTree() : 不对线段树进行初始化
	//SegmentTree(bool = true) : 对线段树进行初始化,需要在括号内填入true
	//SegmentTree(T arr) : 以数组为初始内容初始化线段树 
	//operator[] : 传入一个pair表示左右端点,返回这个区间值的 Reference
	//可以进行 +=/-=(区间加减) 或者 作为一个值来用(区间查询)
	//operator() : 原理同上 operator[],不过传入用逗号分隔的两个参数,更符合直觉
	template<int SIZE,typename T = int>
	class SegmentTree{
	private:
		struct SegmentTreeNode{
			T val,lazy;
			int len;
			SegmentTreeNode(){val = lazy = len = 0;}
		};
		SegmentTreeNode node[(SIZE + 4) * 4];
		int OBJL,OBJR;//避免递归重复复制
		T _val;
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
			node[p].len = r - l + 1,node[p].lazy = node[p].val = 0;
			if(l == r)return ;
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r); 
			PushUp(p);
			return ;
		}
		void BuildArray(int p,int l,int r){
			node[p].len = r - l + 1;
			if(l == r){
				node[p].val = arr[l];
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
		class Reference{
		private:
			friend class SegmentTree;
			SegmentTree* source;
			int l,r;
		public:
			Reference& operator+=(T _val){
				source->Change(l,r,_val);
				return *this;
			}
			Reference& operator-=(T _val){
				source->Change(l,r,-_val);
				return *this;
			}
			operator T(){
				return source->Query(l,r);
			}
			Reference() = default;
			Reference(SegmentTree* _source,int _l,int _r){
				source = _source,l = _l,r = _r;
				return ;
			}
		};
	public:
		int realSize;
		inline void Build(){
			Build(1,1,realSize);
			return ;
		}
		inline void BuildArray(T* _arr){
			arr = _arr;
			BuildArray(1,1,realSize);
			return ;
		}
		inline void Change(int l,int r,T inval){
			OBJL = l,OBJR = r,_val = inval;
			ChangeInner(1,1,realSize);
			return ;
		}
		inline T Query(int l,int r){
			OBJL = l,OBJR = r;
			return Query(1,1,realSize);
		}
		SegmentTree(){
			realSize = SIZE;
			return ;
		}
		SegmentTree(bool BuildTag){
			realSize = SIZE;
			if(BuildTag)Build();
			return ;
		}
		SegmentTree(T* _arr){
			realSize = SIZE;
			arr = _arr;
			BuildArray(_arr);
			return ;
		}
		Reference operator[](pair<int,int> lr){
			return Reference(this,lr.first,lr.second);
		}
		Reference operator()(int l,int r){
			return Reference(this,l,r);
		}
	};
	
	//BIT : 支持单点修改,区间查询的树状数组
	//T : 内容的种类,要求是数字
	//SIZE : 容器大小
	//Change(int x,T val) : 给 x 位置加上 val
	//Query(int l,int r) : 询问 [l,r] 区间和 
	//operator() : 传入一个参数返回当前位置引用,支持 +=/-= 进行区间操作,传入两个值返回区间和(查询)
	//operator[] : 同上,传入一个参数就只传入一个参数,传入两个参数就传一个pair<int,int>
	template<int SIZE,typename T = int>
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
		class Reference{
		private:
			friend class BIT;
			BIT* source;
			int pos;
		public:
			Reference& operator+=(T _val){
				source->Change(pos,_val);
				return *this;
			}
			Reference& operator-=(T _val){
				source->Change(pos,-_val);
				return *this;
			}
			Reference() = default;
			Reference(BIT* _source,int _pos){
				source = _source,pos = _pos;
				return ;
			}
		};
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
		inline void Clear(){
			memset(val,0,sizeof(val));
			return ;
		}
		BIT(){Clear();}
		Reference operator[](int x){
			return Reference(this,x);
		}
		Reference operator()(int x){
			return Reference(this,x);
		}
		T operator[](pair<int,int> lr){
			return Query(lr.first,lr.second);
		}
		T operator()(int l,int r){
			return Query(l,r);
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
			ClearableArray(){
				memset(_content,0,sizeof(_content));
				memset(_vis,0,sizeof(_vis));
				return ;
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
			ClearableArray<int,SIZE> head;
			int tot;
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
			inline bool Find(const Key& key){
				int idx = FindIndex(key);
				return (idx != 0);
			}
			inline void Clear(){
				content.clear();
				content.emplace_back();//初始一个空元素,下标为0,非常重要 
				head.Clear();
				tot = 0;
				return ;
			}
			HashMap(){
				Clear();
				return ;
			}
			HashMap(int initVal){
				content.reserve(initVal);
				Clear();
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
			ClearableArray<int,SIZE> head;
			int tot;
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
			inline void Clear(){
				content.clear();
				content.emplace_back();//初始一个空元素,下标为0,非常重要 
				head.Clear();
				tot = 0;
				return ;
			}
			HashSet(){//初始一个空元素,下标为0,非常重要 
				Clear();
				return ;
			}
			HashSet(int initVal){//初始一个空元素,下标为0,非常重要 
				content.reserve(initVal);
				Clear();
				return ;
			}
	};
	
	//自定义Vector,你问咱有什么用?下标从1开始,无了()(硬要说的话更符合咱的代码习惯)
	//PushBack,Empty,Reserve,Resize,Clear,operator[] 同 vector
	//Free = Resize(1),shink_to_fit (释放内存)
	template<typename T>
	class Vector{
		private:
			const static int Exsize = 2;
			T* content;
			inline void SetCapacity(size_t newSize){
				T* newContent = new T[newSize+1];
				memcpy(newContent,content,sizeof(T) * min((size+1),newSize));
				swap(newContent,content);
				delete[] newContent;
				capacity = newSize;
				size = min(size,capacity);
				return ;
			}
			inline void Shift(int x){
				if(size + x > capacity){
					SetCapacity(size + x); 
				}
				if(x > 0){
					for(size_t i = size;i >= 1;i--){
						content[i+x] = content[i];
					}
					for(size_t i = 1;i <= size_t(x);i++)content[i] = T();
					size += x;
				}
				if(x < 0){
					x = -x;
					for(size_t i = size_t(x+1);i <= size;i++){
						content[i-x] = content[i];
					}
					for(size_t i = size_t(size-x+1);i <= size;i++)content[i] = T();
					size -= x;
				}
				return ;
			}
		public:
			size_t capacity,size;
			typedef T* iterator;
			inline iterator begin(){
				return &content[1];
			}
			inline iterator end(){
				return &content[size+1];
			}
			inline void PushBack(const T& newContent){
				if(size + 1 > capacity){
					SetCapacity(capacity * Exsize); 
				}
				content[++size] = newContent;
				return ;
			}
			inline void PopBack(){
				if(size >= 1)size--;
				return ;
			}
			inline void PushFront(const T& newContent){//O(n)......
				Shift(1);
				content[1] = newContent;
				return ;
			}
			inline void PopFront(){//O(n)......
				Shift(-1);
				return ;
			}
			inline bool Empty(){
				return (size == 0);
			}
			inline void Reserve(size_t newSize){
				if(newSize > capacity)SetCapacity(newSize);
				return ;
			}
			inline void Resize(size_t newSize){
				if(capacity < newSize)SetCapacity(newSize);
				size = newSize;
				return ;
			}
			inline void Clear(){
				size = 0;
				return ;
			}
			inline void Free(){
				SetCapacity(1);
				size = 0;
				return ;
			}
			T& operator[](size_t x){
				return content[x];
			}
			Vector(){
				content = new T[2];
				content[0] = T();
				capacity = 1,size = 0;
				return ;
			}
	};
	
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
}
