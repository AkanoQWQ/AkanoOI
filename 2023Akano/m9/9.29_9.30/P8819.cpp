#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ull = unsigned long long;
const int MAXN = 5e5 + 1018 + 1108;
ull val[MAXN],in[MAXN],tot[MAXN],sum,now;
mt19937_64 rng(time(0));
int n,m,q;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		val[i] = rng();
		sum += val[i];
	}
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		in[v] += val[u];
		tot[v] += val[u];
		now += val[u];
	}
	cin>>q;
	for(int i = 1;i <= q;i++){
		int opt,u,v;
		cin>>opt;
		if(opt == 1){
			cin>>u>>v;
			in[v] -= val[u];
			now -= val[u];
		}else if(opt == 2){
			cin>>u;
			now -= in[u];
			in[u] = 0;
		}else if(opt == 3){
			cin>>u>>v;
			now += val[u];
			in[v] += val[u];
		}else if(opt == 4){
			cin>>u;
			now += tot[u] - in[u];
			in[u] = tot[u];
		}
		if(now == sum){
			cout<<"YES"<<'\n';
		}else{
			cout<<"NO"<<'\n';
		}
	}
	return not(Akano loves pure__Elysia);
}
