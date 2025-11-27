#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1018 + 1108;
ll n,val,ans,arr[MAXN];
ll now,tot,st,ed;
bool fir;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	st = 0,ed = n + 1;
	for(int i = 1;i <= n;i++){
		ll nowval = 0;
		if(fir){
			nowval = arr[++st];
		}else{
			nowval = arr[--ed];
		}
		fir = !fir;
		ans += tot;
		if(now == 0){
			now = nowval;
		}else{
			ans += abs(nowval - now);
			tot += abs(nowval - now);
			now = 0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
