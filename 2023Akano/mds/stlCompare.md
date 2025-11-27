## 介绍
因为有时候无聊~就想造一下轮子（刻在程序员 DNA 里的本能）  

因为好奇STL效率到底怎么样，所以就尝试手写STL试一下到底有没有很大的效率提升  

并不是很严谨的研究，图个乐子   

虽说不是很严谨，基本的控制变量，枚举环境什么的还是要有的  

## vector

众 VP 最喜欢的 STL 容器，也确实好用  

据说在没有 O2 的时代它的效率很让人诟病，我们手写一个对比一下  

测试数据为插入 $10^8$ 个 `int`，在没有 `resize` 的情况下是 `push_back`，有 `resize`的情况下直接访问(调用 `operator[]`)

除去 `-O2` 外，其余编译选项为 `-lm -std=c++14 -Wl,--stack=998244353 -Wall -Wextra -Wshadow` (意味着版本为 c++14)

cpu 为 Intel(R) Core(TM) i3-4170 CPU @ 3.70GHz  

内存 4 GB

### O2 - 无 reserve  

`手写Vector` : $0.50 s$  

`STL vector` : $0.57 s$  

人工组略胜一筹 $ 15 \% $

### O2 - 有 reserve

`手写Vector` : $0.24 s$  

`STL vector` : $0.35 s$  

人工组大胜 $ 45 \% $

### O2 - 有 resize

`手写Vector` : $0.19 s$  

`STL vector` : $0.28 s$  

人工组大胜 $ 47 \% $

### 无O2 - 无 reserve  

`手写Vector` : $0.74 s$  

`STL vector` : $1.31 s$  

人工组大获全胜 $ 74 \% $

### 无O2 - 有 reserve

`手写Vector` : $0.52 s$  

`STL vector` : $1.14 s$  

人工组赢麻了 $ 119 \% $

### 无O2 - 有 resize

`手写Vector` : $0.40 s$  

`STL vector` : $0.58 s$  

人工组大胜 $ 45 \% $

### 总结

手写 vector 效率提升不止一点，但最重要的是开 `O2`，以及要善用 `reverse`  

如果有闲心的话去手写 `vector` 吧少年，其实也不麻烦，就几十行（一个线段树的码量？）    

卡常且一定要用 `vector` 时建议手写!  

### 代码

```cpp
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
			SetCapacity(capacity * 2); 
		}
		content[++size] = newContent;
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
```
## unordered_map

咱最喜欢用的容器，因为很懒，可以用它来干很多事情（或者骗分，用于存储被访问过的状态进行玄学剪枝）  

然而虽然说理论复杂度 $O(1)$ 但是常数巨大而且最坏复杂度 $O(n)$ 并且会在 CF 上被卡，有时甚至不如 `map`

测试数据为使用 `operator[]` 访问 $5 \times 10^7$ 个 `int` (访问 $10^8$ 个数据炸内存了......才发现 `unordered_map` 内存使用巨大)  

那么顺便测试一下内存使用情况吧!（就不测无 O2 情况了）  

哈希函数都是系统默认的 `hash<int>`

### 有 O2

`STL unordered_map` : 内存使用 $2.05 GB$ (!!!!!)，时间使用 $5.15$ 秒

因为我的手写哈希表有一个参数 `size` 表示哈希表头大小，所以有很多组数据。  

**size == 1e6**

`手写 HashMap` : 内存使用 $0.60 GB$，时间使用 $13.53s$

**size == 5e6**

`手写 HashMap` : 内存使用 $0.62 GB$，时间使用 $1.03s$

### 无 O2

`STL unordered_map` : 内存使用 $2.06 GB$，时间使用 $15.44$ 秒

**size == 1e6**

`手写 HashMap` : 内存使用 $0.68 GB$，时间使用 $22.54s$

**size == 5e6**

`手写 HashMap` : 内存使用 $0.86 GB$，时间使用 $5.08s$

### 总结

......这个应该不需要比较了吧......  

除了如果书写哈希表的表头大小分配不好的话可能会导致很慢以外（这个不是越大越好的，需要调参，当然能自动动态调参最好），手写哈希表各个方面薄纱 `unordered_map`  

时间方面快了整整四倍（还是说五倍？小学数学白学了），内存使用只有不到三分之一......  

`unordered_map` 就是垃圾!  

顺带一提,`unordered_set` 应该同理，就不测试了  

如果用到 `unordered_x` 需要卡常也要手写，提升很大  

### 代码
```cpp
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
```

## deque

传说中的史山代码 `deque`，据说有过 100万 `deque` 爆内存的神人  

发现自己写的 `Deque` 也好费内存啊，数据范围调整到 $5 \times 10^7$ 了（不然炸内存）  

一个需要说明的点是，`STL deque` 的内存貌似是很多段破碎的连续区间，咱的 `Deque` 的内存则完泉不连续（其实是只能访问两端的双向链表......）。可能在某些情景下访问要低效一些?  

测试分为间隔着 `push_front`,`push_back`（仅插入）和加上间隔着删除`pop_front`,`pop_back`，因为懒都启动 `O2` 了

### 仅插入

`STL deque` : 用时 $0.20s$  内存 $0.21 GB$

`手写 Deque` ： 用时 $2.00s$  内存 $1.51 GB$

### 带删除

懒得做了，你看这个数据已经说明一切了。

### 总结

?????这么不给咱的手写链表情面的吗  

原来连续内存的威力这么大啊，难怪 `deque` 要写成这样??!!  

对不起 `deque`，道歉！原来咱一直唾弃的容器是最好用的容器。`deque` 永远滴神！  

咱直接删掉咱的史山 `Deque`，写的太烂了

### 代码

突然发现这个代码其实还有 bug，显然把东西删完后它还不为空......致命 bug......懒得管了

```cpp
template<typename T>
class Deque{
private:
	struct Node{
		Node *lst,*nxt;
		T key;
		Node() = default;
		Node(Node* _lst,Node* _nxt,const int& _key){
			lst = _lst,nxt = _nxt,key = _key;
			return ;
		}
	};
	Node *begin,*end;
public:
	inline bool Empty(){
		return (begin == nullptr || end == nullptr);
	}
	inline void Init(const T& val){
		Node* newNode = new Node(nullptr,nullptr,val);
		begin = end = newNode;
		return ;
	}
	inline void PushFront(const T& val){
		if(Empty()){
			Init(val);
			return ;
		}
		Node* newNode = new Node(nullptr,begin,val);
		if(begin != nullptr)begin->lst = newNode;
		begin = newNode;
		return ;
	}
	inline void PushBack(const T& val){
		if(Empty()){
			Init(val);
			return ;
		}
		Node* newNode = new Node(end,nullptr,val);
		if(end != nullptr)end->nxt = newNode;
		end = newNode;
		return ;
	}
	inline void PopFront(){
		Node* newNode = begin->nxt;
		if(newNode != nullptr)newNode->lst = nullptr;
		delete begin;
		begin = newNode;
		return ;
	}
	inline void PopBack(){
		Node* newNode = end->lst;
		if(newNode != nullptr)newNode->nxt = nullptr;
		delete end;
		end = newNode;
		return ;
	}
	inline T& Front(){
		return begin->key;
	}
	inline T& Back(){
		return end->key;
	}
};
```
