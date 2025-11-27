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

struct Node;
using Nodep = Node*;
struct NodeBasic{
	Nodep lson,rson;
	int val,lazy;
	int l,r;
	inline void PushUp(){
		val = 0;
		if(lson != nullptr)val += lson->val;
		if(rson != nullptr)val += rson->val;
		return ;
	}
};

class SegmentTree{
private:
	
	Nodep root;
	MyAllocator<Node> alloc;
	
	void DeleteDFS(Nodep p){
		if(p == nullptr)return ;
		DeleteDFS(p->lson),DeleteDFS(p->rson);
		alloc[p];
		return ;
	}
	inline Nodep NewNode(int l,int r){
		Nodep ret = alloc();
		ret->l = l,ret->r = r,ret->val = ret->lazy = 0,ret->lson = ret->rson = nullptr;
		return ret;
	}
	void Build(Nodep& p,int l,int r,T* arr){
		p = NewNode(l,r);
		if(l == r){
			if(arr != nullptr)p->val = arr[l];
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(p->lson,l,mid,arr),Build(p->rson,mid+1,r,arr);
		p->PushUp();
		return ;
	}
public:
	inline void Clear(){
		DeleteDFS(root);
		root = nullptr;
		return ;
	}
	inline void Build(int siz){
		Clear();
		return Build(root,1,siz,nullptr);
	}
	inline void Build(T* arr,int siz){
		Clear();
		return Build(root,1,siz,arr);
	}
	inline void Build(T* st,T* ed){
		return Build(st,distance(st,ed));
	}
	SegmentTree(){
		root = nullptr;
		return ;
	}
};
int a[5],n = 3;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	return not(Akano loves pure__Elysia);
}
