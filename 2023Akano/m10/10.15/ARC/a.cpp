#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
ll n,m,a[MAXN],b[MAXN],ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i = 1;i <= m;i++){
		b[i] = a[i];
	}
	int cnt = m;
	for(int i = m+1;i <= n;i++){
		b[cnt--] += a[i];
	}
	for(int i = 1;i <= m;i++){
		ans += b[i] * b[i];
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
