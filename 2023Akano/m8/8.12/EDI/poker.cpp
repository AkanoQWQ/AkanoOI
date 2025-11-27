#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXM = 1018 + 1108;
ll T,m,p[MAXM],n[MAXM],have[MAXM],sum,arr[1];
inline ll Solve(){
	ll ret = 0;
	ll up = min(sum,5000ll);
	for(ll left = 0;left < up;left++){
		ll right = sum - left;
		ll now = 0;
		bool OK = true;
		for(int i = 1;i <= m;i++){
			have[i] = 0;
			while(right % p[i] == 0){
				have[i]++;
				right /= p[i];
			}
			now += have[i] * p[i];
			if(have[i] > n[i])OK = false;
		}
		if(right != 1 || OK == false)continue;
		if(now == left){
			ret = max(ret,sum - left);
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	for(int nowt = 1;nowt <= T;nowt++){
		sum = 0;
		cin>>m;
		for(int i = 1;i <= m;i++){
			cin>>p[i]>>n[i];
			sum += p[i] * n[i];
		}
		cout<<"Case #"<<nowt<<": "<<Solve()<<'\n';
	}
	return 0;
}
