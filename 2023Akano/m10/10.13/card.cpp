#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 3e5 + 1018 + 1108;

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
BIT<ll,MAXN> bit;

int n,m,v;
ll atk[MAXN],hp[MAXN],Eatk[MAXN],Ehp[MAXN],now = 0,tot;
vector<int> tags[MAXN];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m>>v;
	for(int i = 1;i <= n;i++){
		cin>>atk[i]>>hp[i];
	}
	for(int i = 1;i <= m;i++){
		cin>>Eatk[i]>>Ehp[i];
		if(Eatk[i] != Eatk[i-1]){//重构
			tot = 0;
			for(int nowval = 1;nowval <= v;nowval += Eatk[i]){
				tot += ((nowval-1) / Eatk[i] + 1) * bit.Query(nowval,min(nowval + Eatk[i] - 1,ll(v)));
			}
		}
		while(tot < Ehp[i] && now+1 <= n){
			now++;
			tot += ((hp[now]-1) / Eatk[i] + 1) * atk[now];
			bit.Change(hp[now],atk[now]);
		}
		if(tot >= Ehp[i]){
			cout<<now<<'\n';
		}else{
			cout<<-1<<'\n';
		}
	}
	return not(Akano loves pure__Elysia);
}
