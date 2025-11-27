## 正文

一个很哲学的问题，到底是先有空节点还是先有节点（）  

在这几天~~摸鱼~~写指针平衡树的时候，遇到了一些有趣的事情。  

在写指针时我们经常遇到空指针/野指针，需要进行特判或者在父节点写一个安泉访问的函数（也是特判）。不过一个很好的方法是把所有原本应该是空指针的地方赋值给一个 `siz,tot,val,key` 都为   [katex]  0  [/katex]  ,把这个空节点视为“空指针对应的节点”。  

然而如果你想在构造函数处填入这个空节点的指针，会发生 `invalid use of non-static data member 'MAIN::emp'` 的错误（当然你得提前声明，不然就是声明方面的先有鸡还是先有蛋了）。  

按照提示把空节点的指针改为 `static`，需要初始化，在平衡树的构造函数处进行初始化，产生奇怪的 `(一堆因为转义会导致博客显示很奇怪的文字): undefined reference to MAIN::emp` 错误（这是什么鬼），查了下说需要提到外面去，结果又因为模板的问题各种报错。  

放弃了，真的难写。突然发现其实只需要在新建节点的时候把它的儿子赋值为空节点指针就行......想麻烦了。  

而且写了这么久其实泉是白忙活，最后手写了一个 `allocator` 分配内存，也就没用到 `new` 了，之前折腾了这么久构造函数啊（）  

总归是写完这个大东西了，效率出乎意料的还可以，在仍有卡常空间的情况下只比它的原版平衡树，也是咱最快的平衡树——普通 `Treap` 慢了   [katex]  20ms  [/katex]  （总共   [katex]  166ms  [/katex]  ）。不过效率比起 `set` 要慢挺多的，毕竟 `Treap` 天生不如红黑树嘛，而且实现可能也比较丑陋。唯一但是很重要的优点就是支持查询排名吧。  

| 插入 | 删除 | 前驱后继 | 遍历 | 查排名 | 查值 | `begin/end` |
| :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: |
|    [katex]  \space \log n \space  [/katex]    |    [katex]  \space \log n \space  [/katex]    |    [katex]  \space \log n \space  [/katex]    |    [katex]  \space 1/n^{[1]} \space  [/katex]    |    [katex]  \space \log n \space  [/katex]    |    [katex]  \space \log n \space  [/katex]    |    [katex]  \space 1 \space  [/katex]    |

  [katex]  [1]  [/katex]  ：均摊   [katex]  O(1)  [/katex]  ，总复杂度   [katex]  O(n)  [/katex]  

话说原来有旋 `Treap` 要比 `FHQ Treap` 快咩，咱一直以为是反过来的。

## 代码

```cpp
#include&lt;bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

template&lt;typename T,int BlockNum = 10>  
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
		blockHead = &amp;(newChunk->blocks[0]);
		
		//把Chunk内部的后继节点设置好
		for(int i = 1;i &lt; BlockNum;i++){
			newChunk->blocks[i - 1].next = &amp;(newChunk->blocks[i]);
		}
		
		if(chunkHead == nullptr){
			chunkHead = newChunk;
		}else{
			newChunk->next = chunkHead;
			chunkHead = newChunk;
		}
		return ;
	}
public:
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
	inline void* AllocateBlock(){//使用单块的空间
		if(blockHead == nullptr){
			GetMemory();
		}
		void* returnPointer = blockHead;
		blockHead = blockHead->next; 
		
		return returnPointer;
	}
	
	Tp Allocate(){
		int n = sizeof(T) / sizeof(T);
		Tp p = Tp(AllocateBlock());
		for(int i = 2;i &lt;= n;i++){
			AllocateBlock();
		}
		return p;
	}
	
	void Deallocate(Tp p){
		Block* block = (Block*)(p);
		block->next = blockHead;
		blockHead = block;
		return ;
	}
};

template&lt;typename T>
class Treap{
private:
	const static int keyINF = 1e9;
	const static int chunkSize = 100;//可能导致容器最小大小变大,要默认大小为 100个T 的大小
	struct Node;
	struct iterator;
	using Nodep = Node*;
	Nodep emptyp;
	struct Node{
		int key;
		int tot,sz;
		T val;
		Nodep l,r,fa;
		Node(T _val,int _key,Nodep _emp){
			val = _val;
			key = _key;
			tot = sz = 1;
			l = r = fa = _emp;
		}
		Node(){
			key = tot = sz = 0;
			val = T();
			l = r = fa = nullptr;//注意,不应该使用默认构造函数!!!
		}
	};
	iterator beginItor,endItor;
	struct iterator{
		Node* node;
		Treap* source;
		T&amp; operator*(){
			return node->val;
		}
		bool operator==(iterator it){
			return source == it.source &amp;&amp; node == it.node;
		}
		bool operator!=(iterator it){
			return !(*this == it);
		}
		iterator&amp; operator++(){
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
		iterator&amp; operator--(){
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
		iterator(Nodep _node,Treap* _source){
			source = _source;
			node = _node;
			return ;
		}
		iterator(){
			source = nullptr;
			node = nullptr;
			return ;
		}
	};
	
	mt19937 rander;
	Nodep root;
	MyAllocator&lt;Node,chunkSize> myAllocator;
	
	inline void PushUp(Nodep p){
		p->sz = p->l->sz + p->r->sz + p->tot;
		p->l->fa = p->r->fa = p;
		return ;
	}
	inline void Zag(Nodep&amp; p){//左旋 
		Nodep q = p->r;
		p->r = q->l;
		q->l = p;
		p = q;
		PushUp(p);
		PushUp(p->l);
		return ;
	}
	inline void Zig(Nodep&amp; p){//右旋 
		Nodep q = p->l;
		p->l = q->r;
		q->r = p;
		p = q;
		PushUp(p);
		PushUp(p->r);
		return ;
	}
	iterator Insert(Nodep&amp; p,T val){
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
		}else if(val &lt; p->val){
			ret = Insert(p->l,val);
			if(p->key &lt; p->l->key){
				Zig(p);
			}
		}else{
			ret = Insert(p->r,val);
			if(p->key &lt; p->r->key){
				Zag(p);
			}
		}
		PushUp(p);
		return ret;
	}
	void Delete(Nodep&amp; p,T val){
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
		}else if(val &lt; p->val){
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
		}else if(val &lt; p->val){
			return GetRank(p->l,val);
		}else if(val > p->val){
			return GetRank(p->r,val) + p->tot + p->l->sz;
		}
		return 10181108;
	}
	iterator GetVal(Nodep p,T k){
		if(k &lt;= p->l->sz){
			return GetVal(p->l,k);
		}else if(k &lt;= int(p->l->sz + p->tot)){
			return iterator(p,this);
		}
		return GetVal(p->r,k - p->l->sz - p->tot);
	}
	iterator Find(Nodep p,T val){
		if(p == emptyp)return endItor;
		if(p->val == val)return iterator(p,this);
		if(val &lt; p->val){
			return Find(p->l,val);
		}else{
			return Find(p->r,val);
		}
		return endItor;
	}
public:
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
	inline iterator begin(){
		return beginItor;
	}
	inline iterator end(){
		return endItor;
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
		delete emptyp;//只有这个可以直接delete
		return ;
	}
};
int q;
Treap&lt;int> tr;
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch &lt; '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while('0' &lt;= ch &amp;&amp; ch &lt;= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
inline void Write(int x){
	static char buff[1024];
	int tp = 0;
	if(x &lt; 0){
		putchar('-');
		x = -x;
	}else if(x == 0){
		putchar('0');
	}
	while(x){
		buff[++tp] = '0' + x % 10;
		x /= 10;
	}
	for(int i = tp;i >= 1;i--){
		putchar(buff[i]);
	}
	return ;
}
int main(){
	q = Read();
	for(int i = 1;i &lt;= q;i++){
		int opt = Read(),x = Read();
		if(opt == 1){
			tr.Insert(x);
		}else if(opt == 2){
			tr.Delete(x);
		}else if(opt == 3){
			Write(tr.GetRank(x)),putchar('\n');
		}else if(opt == 4){
			auto it = tr.GetVal(x);
			Write(*it),putchar('\n');
		}else if(opt == 5){
			auto it = tr.GetPre(x);
			Write(*it),putchar('\n');
		}else if(opt == 6){
			auto it = tr.GetNext(x);
			Write(*it),putchar('\n');
		}
	}
	return not(Akano loves pure__Elysia);
}
```
