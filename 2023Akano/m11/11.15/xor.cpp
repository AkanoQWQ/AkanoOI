#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using uint = unsigned int;
using ll = long long;
constexpr int MAXN = 1e5 + 1018 + 1108;
constexpr int LG = 21;
int n,q,b[MAXN];
uint a[MAXN];
ll ans;
struct Trie{
	struct Node{
		int lcnt,rcnt,l,r;
	}node[MAXN * LG];
	ll value[36];
	int root = 1,tot = 1;
	inline void Insert(uint x){
		int u = root;
		for(int i = 31;i >= 0;i--){
			if(x & (1<<i)){
				if(node[u].r == 0)node[u].r = ++tot;
				node[u].rcnt++;
				value[i] += node[u].lcnt;
				u = node[u].r;
			}else{
				if(node[u].l == 0)node[u].l = ++tot;
				node[u].lcnt++;
				value[i] -= node[u].rcnt;
				u = node[u].l;
			}
		}
		return ;
	}
	inline ll Query(uint x){
		ll ret = 0;
		for(int i = 31;i >= 0;i--){
			if(x & (1<<i)){
				ret += value[i];
			}
		}
		return ret;
	}
}tr;
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
BIT<int,MAXN> bit;
inline void Discretize(){
	vector<uint> vec;
	for(int i = 1;i <= n;i++){
		vec.push_back(a[i]);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(int i = 1;i <= n;i++){
		b[i] = lower_bound(vec.begin(),vec.end(),a[i]) - vec.begin() + 1;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		tr.Insert(a[i]);
	}
	Discretize();
	for(int i = 1;i <= n;i++){
		ans += (i-1) - bit.Query(1,b[i]);
		bit.Change(b[i],1);
	}
	while(q--){
		uint x;
		cin>>x;
		cout<<ans + tr.Query(x)<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
