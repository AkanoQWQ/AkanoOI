#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 1018 + 1108;
ll n,m,seed,vmax,a[MAXN];
inline ll rnd(){
	ll ret = seed;
	seed = (seed * 7 + 13) % MOD;
	return ret;
}
struct ChothollyNode{
	mutable ll l,r,v;
	ChothollyNode(ll _l,ll _r,ll _v){l = _l,r = _r,v = _v;}
	ChothollyNode(ll _l){l = _l,r = _l,v = _l;}
};
bool operator<(ChothollyNode n1,ChothollyNode n2){
	return n1.l < n2.l;
}
bool CmpByVal(ChothollyNode n1,ChothollyNode n2){
	return n1.v < n2.v;
}
inline ll KSM(ll a,ll b,ll mod){
	a %= mod;
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}
class ChthollyTree{
	private:
		typedef ChothollyNode Node;
		typedef set<Node>::iterator itor;
		set<Node> st;
		inline itor Split(int pos){
			auto it = st.lower_bound(Node(pos));
			if(it != st.end() && (*it).l == pos){
				return it;
			}
			it--;
			if((*it).r < pos)return st.end();
			Node node = *it;
			st.erase(it);
			st.insert(Node(node.l,pos-1,node.v));
			itor ret = st.insert(Node(pos,node.r,node.v)).first;
			return ret;
		}
	public:
		inline void Init(ll arr[],int n){
			for(int i = 1;i <= n;i++){
				st.insert(Node(i,i,arr[i]));
			}
			return ;
		}
		inline void Add(ll l,ll r,ll val){
			itor itr = Split(r+1),itl = Split(l);
			for(auto it = itl;it != itr;it++){
				(*it).v += val;
			}
			return ;
		}
		inline void Assign(ll l,ll r,ll val){
			itor itr = Split(r+1),itl = Split(l);
			st.erase(itl,itr);
			st.insert(Node(l,r,val));
			return ;
		}
		inline ll Kth(ll l,ll r,ll k){
			itor itr = Split(r+1),itl = Split(l);
			vector<Node> vec;
			for(auto it = itl;it != itr;it++){
				vec.push_back(*it);
			}
			sort(vec.begin(),vec.end(),CmpByVal);
			for(auto i : vec){
				if(i.r - i.l + 1 >= k){
					return i.v;
				}
				k -= i.r - i.l + 1;
			}
			cerr<<"ERR"<<endl;
			return 10181108;
		}
		inline ll Pow(ll l,ll r,ll p,ll mod){
			ll ret = 0;
			itor itr = Split(r+1),itl = Split(l);
			for(auto it = itl;it != itr;it++){
				const ll delta = (((*it).r - (*it).l + 1) * KSM((*it).v,p,mod)) % mod;
				ret = (ret + delta) % mod;
			}
			return ret % MOD;
		}
}ctr;
inline void MakeData(){
	for(int i = 1;i <= n;i++){
		a[i] = (rnd() % vmax) + 1;
	}
	return ;
}
inline void Execute(){
	ctr.Init(a,n);
	for(int i = 1;i <= m;i++){
		int opt = (rnd() % 4) + 1;
		int l = (rnd() % n) + 1;
		int r = (rnd() % n) + 1;
		int x = 0,y = 0;
		if(l > r)swap(l,r);
		if(opt == 3){
			x = (rnd() % (r - l + 1)) + 1;
		}else{
			x = (rnd() % vmax) + 1;
		}
		if(opt == 4){
			y = (rnd() % vmax) + 1;
		}
		if(opt == 1){
			ctr.Add(l,r,x);
		}else if(opt == 2){
			ctr.Assign(l,r,x);
		}else if(opt == 3){
			cout<<ctr.Kth(l,r,x)<<endl;
		}else if(opt == 4){
			cout<<ctr.Pow(l,r,x,y)<<endl;
		}else{
			cerr<<"ERR"<<endl;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>seed>>vmax;
	MakeData();
	Execute();
	return 0;
}
