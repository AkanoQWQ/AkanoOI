#pragma once
#include<bits/stdc++.h>
using namespace std;

namespace Container{
	
	//MyAllocator : 内存分配器,预留整块的内存分配,增加分配速度减少碎片内存
	//T : 需要分配的类型种类
	//BlockNum : 每个大块包含了多少个小块,一个小块对应一个 T 的内存,也就是说一次预留多少个 T 的内存
	//Allocate() : 分配一个 T 的内存,返回指针
	//Deallocate(T* del) : 回收之前分配出去的内存,可以重复利用,传入 T指针
	//operator() : 同Allocate()
	//operator[] : 同Deallocate()
	template<typename T,int BlockNum = 10>  
	class MyAllocator{
	private:
		using Tp = T*;
		struct Block{
			unsigned char data[sizeof(T)];
			Block* next;
			Block(){
				next = nullptr;
				return ;
			}
		};
		struct Chunk{
			Block blocks[BlockNum];
			Chunk* next;
			Chunk(){
				next = nullptr;
				return ;
			}
		};
		Block* blockHead;
		Chunk* chunkHead;
		
		inline void GetMemory(){
			//创建新的Chunk
			Chunk* newChunk = new Chunk;
			blockHead = &(newChunk->blocks[0]);
			
			//把Chunk内部的后继节点设置好
			for(int i = 1;i < BlockNum;i++){
				newChunk->blocks[i - 1].next = &(newChunk->blocks[i]);
			}
			
			if(chunkHead == nullptr){
				chunkHead = newChunk;
			}else{
				newChunk->next = chunkHead;
				chunkHead = newChunk;
			}
			return ;
		}
		inline void* AllocateBlock(){//使用单块的空间
			if(blockHead == nullptr){
				GetMemory();
			}
			void* returnPointer = blockHead;
			blockHead = blockHead->next; 
			
			return returnPointer;
		}
	public:
		inline Tp Allocate(){
			int n = sizeof(T) / sizeof(T);
			Tp p = Tp(AllocateBlock());
			for(int i = 2;i <= n;i++){
				AllocateBlock();
			}
			return p;
		}
		inline void Deallocate(Tp p){
			Block* block = (Block*)(p);
			block->next = blockHead;
			blockHead = block;
			return ;
		}
		Tp operator()(){
			return Allocate();
		}
		inline void operator[](Tp p){
			Deallocate(p);
			return ;
		}
		MyAllocator(){
			blockHead = nullptr;
			chunkHead = nullptr;
			return ;
		}
		~MyAllocator(){//就是要删Chunk,无论内存怎么分配,都只有Chunk那几块
			Chunk* saveNext;
			while(chunkHead != nullptr){
				saveNext = chunkHead->next;
				delete chunkHead;
				chunkHead = saveNext;
			}
			return ;
		}
	};
	
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
			inline void Clear(){
				memset(val,0,sizeof(val));
				return ;
			}
			BIT(){Clear();}
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
	
	//新版本迭代器Treap
	//更新注释:比起上个版本灾难性的史山Treap好一万倍的Treap,真正意义上支持了迭代器,效率更高
	//效率相比 set 来说,保守估计2倍常数,实际1.5倍左右(但它可以查排名啊)
	//Treap::iterator 类
	//注释 : 目前为 private 类,无法通过 Treap::iterator 获取,只能使用 auto 接受
	//operator *() : 解引用值,然而虽然返回的是引用但是如果修改值的话会破坏 Treap 性质,并不支持修改(可以在之后加上Update的机制)
	//operator ++/--(前后自加减) : 获得该迭代器位置的前驱和后继,有均摊复杂度 O(1) 的特性,单次最坏 O(log n)
	//operator ==/!= : 判等
	//Treap 成员函数
	//begin() / end() 获得 STL 同意义的 begin/end,因此支持 for(auto) 范围for
	//Insert(T val) : 插入值,如果元素已存在则挂载一个副本在原元素上,共享一个迭代器
	//Delete(T val) : 删除值,如果存在多个只删除一个
	//GetRank(T val) : 获取某值的排名(从小到大第几个),从 1 开始
	//GetVal(int k) : 获得第 k 大的值
	//Find(T val) : 获得 val 的迭代器,不存在返回 end()
	//GetPre(T val) : 获得 val 的严格前驱(val 对应的节点不一定存在,不然推荐使用 iterator--)(实现较为暴力,常数较大)
	//GetNext(T val) : 获得 val 的严格后继
	template<typename T>
	class Treap{
	private:
		const static int keyINF = 1e9;
		const static int chunkSize = 100;//可能导致容器最小大小变大,要默认大小为 100个T 的大小
		struct Node;
		struct iterator;
		using Nodep = Node*;
		Nodep emptyp;
		struct Node{
			int key,tot,sz;
			T val;
			Nodep l,r,fa;
			Node(){//不提供带参数的构造函数了,反正也没用
				key = tot = sz = 0;
				val = T();
				l = r = fa = nullptr;//注意,不应该使用默认构造函数!!!
			}
		};
		iterator beginItor,endItor;
		class iterator{
		private:
			friend class Treap;
			Node* node;
			Treap* source;
			iterator(){
				source = nullptr;
				node = nullptr;
				return ;
			}
			iterator(Nodep _node,Treap* _source){
				source = _source;
				node = _node;
				return ;
			}
		public:
			T& operator*(){
				return node->val;
			}
			bool operator==(iterator it){
				return source == it.source && node == it.node;
			}
			bool operator!=(iterator it){
				return !(*this == it);
			}
			iterator& operator++(){
				//需要模拟中序遍历
				Nodep pos = node,last = node->l;
				//现在遍历完左子树,尝试遍历右子树
				if(pos->r != source->emptyp){
					pos = pos->r;
					while(pos->l != source->emptyp){
						pos = pos->l;
					}
					node = pos;
					return *this;
				}
				//遍历完了(没找到),往父亲跳
				last = node,pos = node->fa;
				while(pos != source->emptyp){
					if(last == pos->l){//中序遍历遍历到自己
						node = pos;
						return *this;
					}
					//last == node->r : 中序遍历完了该节点,放回父亲
					last = pos,pos = pos->fa;
				}
				if(pos == source->emptyp)*this = source->endItor;
				return *this;
			}
			iterator operator++(int){//可以这么写吗?? 
				iterator old = *this;
				operator++();
				return old;
			}
			iterator& operator--(){
				//反向模拟中序遍历
				Nodep pos = node,last = node->l;
				//尝试遍历左子树
				if(pos->l != source->emptyp){
					pos = pos->l;
					while(pos->r != source->emptyp){
						pos = pos->r;
					}
					node = pos;
					return *this;
				}
				//遍历完了(没找到),往父亲跳
				last = node,pos = node->fa;
				while(pos != source->emptyp){
					if(last == pos->r){//中序遍历遍历到自己
						node = pos;
						return *this;
					}
					last = pos,pos = pos->fa;
				}
				if(pos == source->emptyp)*this = source->endItor;
				return *this;
			}
			iterator operator--(int){
				iterator old = *this;
				operator--();
				return old;
			}
		};
		
		mt19937 rander;
		Nodep root;
		MyAllocator<Node,chunkSize> myAllocator;
		
		inline void PushUp(Nodep p){
			p->sz = p->l->sz + p->r->sz + p->tot;
			p->l->fa = p->r->fa = p;
			return ;
		}
		inline void Zag(Nodep& p){//左旋 
			Nodep q = p->r;
			p->r = q->l;
			q->l = p;
			p = q;
			PushUp(p);
			PushUp(p->l);
			return ;
		}
		inline void Zig(Nodep& p){//右旋 
			Nodep q = p->l;
			p->l = q->r;
			q->r = p;
			p = q;
			PushUp(p);
			PushUp(p->r);
			return ;
		}
		iterator Insert(Nodep& p,T val){
			if(p == emptyp){
				p = myAllocator.Allocate();
				p->val = val,p->key = rander() % keyINF,p->l = p->r = p->fa = emptyp;
				p->tot = p->sz = 1;
				//更新beginItor,最小值一定插入在前最小值的左儿子
				if(beginItor.node == emptyp || p == beginItor.node->l){
					beginItor.node = p;
				}
				return iterator(p,this);
			}
			iterator ret;
			if(val == p->val){
				p->tot++;
				ret = iterator(p,this);
			}else if(val < p->val){
				ret = Insert(p->l,val);
				if(p->key < p->l->key){
					Zig(p);
				}
			}else{
				ret = Insert(p->r,val);
				if(p->key < p->r->key){
					Zag(p);
				}
			}
			PushUp(p);
			return ret;
		}
		void Delete(Nodep& p,T val){
			if(p == emptyp)return ;
			if(p->val == val){
				if(p->tot >= 2){
					--p->tot;
				}else if(p->l != emptyp || p->r != emptyp){
					if(p->l->key > p->r->key){
						Zig(p);
						Delete(p->r,val);
					}else{
						Zag(p);
						Delete(p->l,val);
					}
				}else{
					//更新beginItor,新最小值一定是现最小值的父亲
					if(p == beginItor.node){
						beginItor.node = p->fa;
					}
					myAllocator.Deallocate(p);
					p = emptyp;
				}
			}else if(val < p->val){
				Delete(p->l,val); 
			}else if(val > p->val){
				Delete(p->r,val);
			}
			PushUp(p);
			return ;
		}
		int GetRank(Nodep p,T val){
			if(p == emptyp)return 1;
			if(val == p->val){
				return p->l->sz + 1;
			}else if(val < p->val){
				return GetRank(p->l,val);
			}else if(val > p->val){
				return GetRank(p->r,val) + p->tot + p->l->sz;
			}
			return 10181108;
		}
		iterator GetVal(Nodep p,T k){
			if(k <= p->l->sz){
				return GetVal(p->l,k);
			}else if(k <= int(p->l->sz + p->tot)){
				return iterator(p,this);
			}
			return GetVal(p->r,k - p->l->sz - p->tot);
		}
		iterator Find(Nodep p,T val){
			if(p == emptyp)return endItor;
			if(p->val == val)return iterator(p,this);
			if(val < p->val){
				return Find(p->l,val);
			}else{
				return Find(p->r,val);
			}
			return endItor;
		}
	public:
		inline iterator begin(){
			return beginItor;
		}
		inline iterator end(){
			return endItor;
		}
		inline iterator Insert(T val){
			return Insert(root,val);
		}
		inline void Delete(T val){
			Delete(root,val);
			return ;
		}
		inline int GetRank(T val){
			return GetRank(root,val); 
		}
		inline iterator GetVal(int k){
			return GetVal(root,k);
		}
		inline iterator Find(T val){
			return Find(root,val);
		}
		inline iterator GetPre(T val){
			auto itor = Insert(val);
			--itor;
			Delete(val);
			return itor;
		}
		inline iterator GetNext(T val){
			auto itor = Insert(val);
			++itor;
			Delete(val);
			return itor;
		}
		Treap(){
			emptyp = new Node();
			emptyp->sz = emptyp->tot = 0;
			emptyp->l = emptyp->r = emptyp;//自指没问题吧
			root = emptyp;
			beginItor = iterator(emptyp,this);
			endItor = iterator(emptyp,this);
			rander.seed(time(0));
			return ;
		}
		~Treap(){
			//DeleteDFS(root);
			//貌似不用DeleteDFS,因为Alloc分配的内存无论如何都会被删掉
			//并不要求需要Deallocate回去才可以回收
			delete emptyp;//只有这个可以直接delete,也需要delete
			return ;
		}
	};
	
	//Trmap : treap : map
	//极其简陋的 treap 封装实现 map 功能
	//目前功能较少,稳定性未知
	//operator[] : map式的访问
	template<typename keyT,typename valT>
	class Trmap{
	private:
		struct Node{
			keyT key;
			valT val;
			bool operator==(Node oth){
				return key == oth.key;
			}
			bool operator<(Node oth){
				return key < oth.key;
			}
		};
		Treap<Node> treap;
	public:
		valT& operator[](const keyT& _key){
			Node node = {_key,valT()};
			auto it = treap.Find(node);
			if(it == treap.end())it = treap.Insert(node);
			return (*it).val;
		}
	};
}
