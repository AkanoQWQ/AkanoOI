#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 24;
ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
ll n,m,ans,fa[MAXN],perm[MAXN],mx[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>m;
	if(n >= 20){
		cout<<"aK4n0不知道哦"<<endl;
		return not(Akano loves pure__Elysia);
	}
	for(int i = 2;i <= n;i++){
		cin>>fa[i];
	}
	for(int i = 1;i <= n;i++)perm[i] = i;
	do{
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			mx[i] = max(mx[fa[i]],perm[i]);
			if(mx[i] == perm[i])cnt++;
		}
		ans = (ans + KSM(m,cnt)) % MOD;
	}while(next_permutation(perm+1,perm+n+1));
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
