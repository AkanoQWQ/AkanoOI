#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

template<typename T>
class Treap{
public:
	struct Node;
	using Nodep = Node*;
	Node emptyNode;
	Nodep emptyp = &emptyNode;
	
	struct Node{
		int key;
		size_t tot,sz;
		T val;
		Nodep l,r,fa;
		Node(T _val,int _key){
			val = _val;
			key = _key;
			tot = sz = 1;
			l = r = fa = &emptyNode;
		}
		Node(){
			key = tot = sz = 0;
			val = T();
			l = r = fa = &emptyNode;
		}
	};
	struct iterator;
	iterator rend,begin,end;
	struct iterator{
		Node* node;
		Treap* source;
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
			Nodep pos = node;
			while(pos != emptyp){
				if(pos->r != emptyp){
					node = pos->r;
					return *this;
				}
				pos = pos->fa;
			}
			if(pos == emptyp)pos = end;
			return *this;
		}
		iterator operator++(int){//可以这么写吗?? 
			iterator old = *this;
			operator++();
			return old;
		}
		iterator(Node* _node,Treap* _source){
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
private:
	const static int keyINF = 1e9;
	mt19937 rander;
	
	Nodep root;
	
	inline void PushUp(Nodep& p){
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
	void Insert(Nodep& p,T val){
		if(p == emptyp){
			p = new Node(val,rander() % keyINF);
			return ;
		}
		if(val == p->val){
			p->tot++;
		}else if(val < p->val){
			Insert(p->l,val);
			if(p->key < p->l->key){
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
				delete p;
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
	size_t GetRank(Nodep p,T val){
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
		return GetVal(p->r,k - p->Lsize() - p->tot);
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
	Treap(){
		rander.seed(time(0));
		return ;
	}
};

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	return not(Akano loves pure__Elysia);
}
