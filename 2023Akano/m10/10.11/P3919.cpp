#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
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
class PersistentSegmentTree{
private:
	struct Node;
	using Nodep = Node*;
	struct Node{
		Nodep l,r;
//		int val;
		Node(){
			l = r = nullptr;
			return ;
		}
	};
	MyAllocator<Node,int(5e5 + 4)> alloc;
	void Change(Nodep& p,int l,int r,int OBJ,int _val){
		Nodep oldp = p;
		p = alloc();
		if(oldp != nullptr)(*p) = (*oldp);
		if(l == r){
			unsigned long long _v = _val;
			p->l = reinterpret_cast<Nodep>(_v);
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)Change(p->l,l,mid,OBJ,_val);
		if(mid < OBJ)Change(p->r,mid+1,r,OBJ,_val);
		return ;
	}
	int Query(Nodep p,int l,int r,int OBJ){
		if(l == r){
			return reinterpret_cast<unsigned long long>(p->l);
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)return Query(p->l,l,mid,OBJ);
		if(mid < OBJ)return Query(p->r,mid+1,r,OBJ);
		return 10181108;
	}
public:
	int size;
	friend class Reference;
	class PersistentArray{
	private:
		friend class PersistentSegmentTree;
		PersistentSegmentTree* source;
		Nodep root;
		PersistentArray(PersistentSegmentTree* _source,Nodep _root){
			source = _source,root = _root;
			return ;
		}
		
		class Reference{
		private:
			friend class PersistentArray;
			PersistentArray* source;
			int pos;
			Reference() = default;
			Reference(PersistentArray* _source,int _pos){
				source = _source,pos = _pos;
				return ;
			}
		public:
			operator int(){
				return source->source->Query(source->root,1,source->source->size,pos);
			}
			Reference& operator=(int val){
				source->source->Change(source->root,1,source->source->size,pos,val);
				return *this;
			}
		};
	public:
		PersistentArray(){
			root = nullptr,source = nullptr;
			return ;
		}
		PersistentArray& operator==(const PersistentArray& other){
			root = other.root,source = other.source;
			return *this;
		}
		Reference operator[](int pos){
			return Reference(this,pos);
		}
	};
	inline PersistentArray NewArray(){
		return PersistentArray(this,nullptr);
	}
}tr;
using Array = PersistentSegmentTree::PersistentArray;
const int MAXN = 1e6 + 4;
Array arrs[MAXN];
int n,q;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	tr.size = n;
	arrs[0] = tr.NewArray();
	for(int i = 1;i <= n;i++){
		int val;
		cin>>val;
		arrs[0][i] = val;
	}
	for(int i = 1;i <= q;i++){
		int ver,opt,pos,val;
		cin>>ver>>opt;
		arrs[i] = arrs[ver];
		if(opt == 1){
			cin>>pos>>val;
			arrs[i][pos] = val;
		}else if(opt == 2){
			cin>>pos;
			cout<<arrs[i][pos]<<'\n';
		}
	}
	return not(Akano loves pure__Elysia);
}
