#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 626;
const ll INF = 1e14;
ll id,T,n;
struct Pop{
	ll a,b,c,v;
}pop[MAXN];
bool Cmp(Pop pop1,Pop pop2){
	if(pop1.v != pop2.v)return pop1.v < pop2.v;
	return pop1.a < pop2.a;
}
ll f[2][MAXN][MAXN],trans[MAXN][MAXN],sumb[MAXN],sumc[MAXN];
inline void Clear(){
	for(int i = 0;i <= n+1;i++){
		for(int j = 0;j <= n+1;j++){
			trans[i][j] = -INF;
		}
	}
	return ;
}
inline ll GetB(int l,int r){
	return sumb[r] - sumb[l-1];
}
inline ll GetC(int l,int r){
	return sumc[r] - sumc[l-1];
}
inline ll Solve(){
	ll ret = -INF;
	cin>>n;
	Clear();
	for(int i = 1;i <= n;i++){
		cin>>pop[i].a>>pop[i].b>>pop[i].c>>pop[i].v;
	}
	sort(pop+1,pop+n+1,Cmp);
	for(int i = 1;i <= n;i++){
		sumb[i] = sumb[i-1] + pop[i].b;
		sumc[i] = sumc[i-1] + pop[i].c;
	}
	int now = 0,pre = 1;
	memset(f,254,sizeof(f));
	f[now][0][0] = 0;
	for(int l = 1;l <= n;l++){
		swap(pre,now);
		memset(f[now],254,sizeof(f[now]));
		int r = l;
		while(r+1 <= n && pop[r+1].v == pop[r].v){
			r++;
		}
		for(int i = 0;i <= n;i++)trans[l-1][i] = -INF;
		trans[l-1][0] = 0;
		for(int i = l;i <= r;i++){
			for(int j = 0;j <= n;j++){
				trans[i][j] = max(trans[i][j],trans[i-1][j] + pop[i].b);
				trans[i][j+1] = max(trans[i][j+1],trans[i-1][j] + pop[i].c);
			}
		}
		ll maxa = 0,tot = r - l + 1;
		for(int i = l;i <= r;i++){
			maxa = max(maxa,pop[i].a);
		}
		for(int i = 0;i <= r;i++){
			for(int j = 0;j <= n;j++){
				if(f[pre][i][j] < 0)continue;
				if(tot + i - 1 >= maxa){
					f[now][i][max(0ll,j - tot)] = max(//泉部为1
						f[now][i][max(0ll,j - tot)],
						f[pre][i][j] + GetB(l,r)
					);
					for(int pos = l;pos <= r-1;pos++){
						for(int use = 0;use <= pos - l;use++){
							ll sec = max(j - tot + use + 1,pop[pos].a - tot + 1);
							sec = max(sec,0ll);
							f[now][i + use + 1][sec] = max(
								f[now][i + use + 1][sec],
								f[pre][i][j] + GetB(pos+1,r) + pop[pos].c + trans[pos-1][use]
							);
						}
					}
				}
				f[now][i + tot][max(ll(j),ll(pop[r].a - tot + 1))] = max(
					f[now][i + tot][max(ll(j),pop[r].a - tot + 1)],
					f[pre][i][j] + GetC(l,r)
				);
				for(int pos = r-1;pos >= l;pos--){
					if(tot + i - 1 >= pop[pos].a){
						for(int use = 0;use <= tot;use++){
							ll sec = max(j - tot + r - pos + use,pop[r].a - tot + 1);
							sec = max(sec,0ll);
							f[now][i + r - pos + use][sec] = max(
								f[now][i + r - pos + use][sec],
								f[pre][i][j] + GetC(pos+1,r) + trans[pos][use]
							);
						}
						break;//WHY??????????
					}
				}
			}
		}
		l = r;
	}
	for(int i = 0;i <= n;i++){
		ret = max(ret,f[now][i][0]);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("fly.in","r",stdin);
	freopen("fly.out","w",stdout);
	cin>>pop[0].a>>T;
	while(T--){
		ll res = Solve();
		if(res < 0){
			cout<<"explode"<<endl;
		}else{
			cout<<res<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}
