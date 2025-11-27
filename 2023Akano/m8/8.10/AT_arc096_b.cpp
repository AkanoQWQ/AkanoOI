#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
struct rice{
	ll l,r,v;
}r[MAXN];
ll n,c,ans,f[MAXN],g[MAXN],sumv[MAXN];
inline void Solve(){
	for(int i = n;i >= 1;i--){
		sumv[i] = sumv[i+1] + r[i].v;
		f[i] = sumv[i] - r[i].l;
		g[i] = max(f[i],g[i+1]);
//		cout<<i<<" f "<<f[i]<<" g "<<g[i]<<" l "<<r[i].l<<" r "<<r[i].r<<endl;
	}
	for(int i = 1;i <= n;i++){
		sumv[i] = sumv[i-1] + r[i].v;
//		cout<<i<<" res "<<sumv[i] - r[i].r<<" and "<<g[i+1]<<endl;
		ans = max(ans,sumv[i] - r[i].r);
		ans = max(ans,sumv[i] - 2 * r[i].r + g[i+1]);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>c;
	for(int i = 1;i <= n;i++){
		cin>>r[i].r>>r[i].v;
		r[i].l = c - r[i].r;
	}
	Solve();
	for(int i = 1;i <= n;i++){
		swap(r[i].l,r[i].r);
	}
	reverse(r+1,r+n+1);
	Solve();
	cout<<ans;
	return 0;
}

