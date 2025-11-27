//Treap 模板类 
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

template<typename Val>
struct TreapNode{
	int weight,l,r,tot,sz;
	Val val;
	TreapNode(Val _val){
		val = _val;
		weight = rand();//是否考虑其他随机方式
		l = r = 0;
		tot = sz = 1;
		return ;
	}
	TreapNode(){
		val = Val();
		weight = rand();
		l = r = 0;
		tot = sz = 1;
		return ;
	}
};
template<typename Val,Val INF,Val fINF,int SIZE>
class Treap{
	typedef TreapNode<Val> Node;
	private:
		Node node[SIZE+3];//加三是0,INF,-INF 
		int root,tot;
		inline int& L(int p){
			return node[p].l;
		}
		inline int& R(int p){
			return node[p].r;
		}
		inline void PushUp(int p){
			node[p].sz = node[L(p)].sz + node[R(p)].sz + node[p].tot;
			return ;
		}
		inline void Zag(int &p){//左旋 
			int q = R(p);
			R(p) = L(q);
			L(q) = p;
			p = q;
			PushUp(p);
			PushUp(L(p));
			return ;
		}
		inline void Zig(int &p){//右旋 
			int q = L(p);
			L(p) = R(q);
			R(q) = p;
			p = q;
			PushUp(p);
			PushUp(R(p));
			return ;
		}
		void Insert(int &p,Val val){
			if(!p){
				p = ++tot;
				node[tot] = Node(val);
				return ;
			}
			if(val == node[p].val){
				node[p].tot++;
			}else if(val < node[p].val){
				Insert(L(p),val);
				if(node[p].weight < node[L(p)].weight){
					Zig(p);
				}
			}else{
				Insert(R(p),val);
				if(node[p].weight < node[R(p)].weight){
					Zag(p);
				}
			}
			PushUp(p);
			return ;
		}
		void Delete(int &p,Val val){
			if(!p)return ;
			if(node[p].val == val){
				if(node[p].tot >= 2){
					--node[p].tot;
				}else if(L(p) + R(p)){
					if(node[L(p)].weight > node[R(p)].weight){
						Zig(p);
						Delete(R(p),val);
					}else{
						Zag(p);
						Delete(L(p),val);
					}
				}else{
					//需要这一句吗? 
					node[p] = Node(Val());
					p = 0;
				}
			}else if(val < node[p].val){
				Delete(L(p),val); 
			}else if(val > node[p].val){
				Delete(R(p),val);
			}
			PushUp(p);
			return ;
		}
		int GetRank(int p,Val val){
			if(!p)return 1;
			if(val == node[p].val){
				return node[L(p)].sz + 1;
			}else if(val < node[p].val){
				return GetRank(L(p),val);
			}else if(val > node[p].val){
				return GetRank(R(p),val) + node[p].tot + node[L(p)].sz;
			}
			return 10181108;
		}
		Val GetVal(int p,int k){
			cerr<<"find "<<k<<" in "<<p<<endl;
			if(k <= node[L(p)].sz){
				return GetVal(L(p),k);
			}else if(k <= node[L(p)].sz + node[p].tot){
				return node[p].val;
			}
			return GetVal(R(p),k - node[L(p)].sz - node[p].tot);
		}
		Val GetPre(int p,Val val){
			if(!p)return fINF;
			if(val < node[p].val || val == node[p].val){
				return GetPre(L(p),val);
			}else{
				return max(node[p].val,GetPre(R(p),val));
			}
		}
		Val GetNext(int p,Val val){
			if(!p)return INF;
			if(val < node[p].val){
				return min(node[p].val,GetNext(L(p),val));
			}else{
				return GetNext(R(p),val);
			}
		}
	public:
		inline void Init(){
			tot = 0;
			node[0].sz = node[0].tot = 0;
			Insert(root,INF);
			Insert(root,fINF);
			return ;
		}
		inline void Insert(Val val){
			Insert(root,val);
			return ;
		}
		inline void Delete(Val val){
			Delete(root,val);
			return ;
		}
		inline int GetRank(Val val){
			return GetRank(root,val)-1;//INF影响 
		}
		inline Val GetVal(int k){
			return GetVal(root,k+1);//INF影响 
		}
		inline Val GetPre(Val val){
			return GetPre(root,val);
		}
		inline Val GetNext(Val val){
			return GetNext(root,val);
		}
		Treap(){
			Init();
			return ;
		}
};
const int MAXN = 1e5 + 5;
Treap<int,INT_MAX,INT_MIN,MAXN> tr;
int n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P3369_4.in","r",stdin);
	cin>>n;
	for(int i = 1;i <= n;i++){
		int opt,x;
		cin>>opt>>x;
		if(opt == 1){
			tr.Insert(x);
		}else if(opt == 2){
			tr.Delete(x);
		}else if(opt == 3){
			cout<<tr.GetRank(x)<<'\n';
		}else if(opt == 4){
			cout<<tr.GetVal(x)<<'\n';
		}else if(opt == 5){
			cout<<tr.GetPre(x)<<'\n';
		}else{
			cout<<tr.GetNext(x)<<'\n';
		}
	}
	return not(Akano loves pure__Elysia);
}
