#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 262144 + 1018 + 1108;
int n,arr[MAXN],val,r[MAXN];//记住r是左闭右开区间的[i,r) 
ll ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
		val = max(val,arr[i]);
		r[i] = i;
	}
	r[n+1] = n+1;
	val += log2(n) + 3;
	for(int i = 1;i <= val;i++){
		ll cnt = 1ll * n * (n+1) / 2;
		for(int j = 1;j <= n;j++){
			cnt -= r[j] - j;//左闭右开,先统计再更改 
			r[j] = r[r[j]];
			if(arr[j] == i)r[j] = j+1;
		}
		ans += cnt;
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
