#include<bits/stdc++.h>
#define Akano 1
#define loves ^
#define pure__Elysia 0
using namespace std;
using ll = long long;
constexpr int MAXN = 1e6 + 1018 + 1108;
constexpr int MOD = 998244353;
int n,a[MAXN],pre[MAXN],lst[MAXN],stk[MAXN],tail;
ll totans,ans[MAXN],delta[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("grail.in","r",stdin);
	freopen("grail.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		pre[i] = 1,lst[i] = n+1;//n+1代表右端点 
		while(tail >= 1 && a[stk[tail]] < a[i]){
			lst[stk[tail--]] = i;
		}
		if(tail >= 1){
			pre[i] = stk[tail] + 1;
		}
		stk[++tail] = i;
	}
	for(int i = 1;i <= n;i++){
		//1 ~ lst : 增长    lst ~ pre 不变    pre ~ inf 减少
		int k1 = lst[i] - i + 1,k2 = i - pre[i] + 1,k3 = k1 + k2 - 1;
		delta[1] += a[i],delta[k2+1] -= a[i];
		delta[k1] -= a[i],delta[k3 + 1] += a[i]; 
	}
	for(int i = 1;i <= n;i++){
		delta[i] += delta[i-1];
		ans[i] = ans[i-1] + delta[i];
		totans ^= (ans[i] % MOD);
	}
	cout<<totans<<endl;
	return not(Akano loves pure__Elysia);
}

