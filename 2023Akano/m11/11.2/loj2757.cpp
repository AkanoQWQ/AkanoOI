#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e4 + 1018 + 1108;
int n,m,p[MAXN],f[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>m>>n;
	for(int i = 1;i <= m;i++){
		cin>>p[i];
		f[i] = 1e9;
	}
	for(int i = 1,c,e;i <= n;i++){
		cin>>c>>e;
		for(int j = m;j >= 0;j--){
			f[min(j + c,m)] = min(f[min(j + c,m)],f[j] + e);
		}
	}
	for(int i = m-1;i >= 0;i--){
		f[i] = min(f[i],f[i+1]);
	}
	sort(p+1,p+m+1,greater<int>());
	int ans = 0;
	for(int i = 1;i <= m;i++){
		p[i] += p[i-1];
		ans = max(ans,p[i] - f[i]);
//		cerr<<i<<" price "<<p[i]<<" cost "<<f[i]<<endl;
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
