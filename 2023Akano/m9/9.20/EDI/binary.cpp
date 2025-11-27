#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1018 + 1108;
int n,a[MAXN];
ll m,ans;
inline bool Judge(ll x){
	
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	{//原来不用写一个很煞笔的	if(true)...... 
		ll l = 1,r = m + 1;
		while(l < r){
			const ll mid = (l + r) >> 1;
			if(Judge(mid)){
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		ans = r;
	}
	
	return not(Akano loves pure__Elysia);
}
