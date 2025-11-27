#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 10000 + 1018 + 1108;
const int INF = 1e9;
int T,n,m,a[MAXN],f[2][MAXN];
inline int P(int x){
	return x * x;
}
inline int Solve(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int now = 0,pre = 1;
	memset(f,0x7f,sizeof(f));
	f[now][0] = 0;
	for(int i = 1;i <= m;i++){
		swap(now,pre);
		memset(f[now],0x7f,sizeof(f[now]));
		for(int j = 0;j <= n;j++){
			for(int k = best[now][j-1];k < best[][];k++){
				f[now][j] = min(f[now][j],f[pre][k] + P(a[j] - a[k+1]));
			}
		}
	}
	return f[now][n];
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	for(int t = 1;t <= T;t++){
		cout<<"Case "<<t<<": "<<Solve()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
