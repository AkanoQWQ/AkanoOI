#include<bits/stdc++.h>
using namespace std;

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
			iterator operator++(int){//¿ÉÒÔÕâÃ´Ð´Âð?? 
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
		inline void Zag(NodeItor& p){//×óÐý 
			NodeItor q = p->r;
			p->r = q->l;
			q->l = p;
			p = q;
			PushUp(p);
			PushUp(p->l);
			return ;
		}
		inline void Zig(NodeItor& p){//ÓÒÐý 
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
		inline iterator begin(){//logn ¸´ÔÓ¶È! 
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
Treap<int> tr;
int n,q,lastans,ans;
inline int Read(){//no f
	int ret = 0;
	char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar(); 
	}
	return ret;
}
int main(){
	n = Read(),q = Read();
	for(int i = 1;i <= n;i++){
		int x = Read();
		tr.Insert(x);
	}
	while(q--){
		int opt = Read(),x = Read();
		x ^= lastans;
		if(opt == 1){
			tr.Insert(x);
		}else if(opt == 2){
			tr.Delete(x);
		}else if(opt == 3){
			lastans = tr.GetRank(x);
			ans ^= lastans;
		}else if(opt == 4){
			lastans = *tr.GetVal(x);
			ans ^= lastans;
		}else if(opt == 5){
			lastans = *tr.GetPre(x);
			ans ^= lastans;
		}else if(opt == 6){
			lastans = *tr.GetNext(x);
			ans ^= lastans;
		}
		cerr<<"lastans "<<lastans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
