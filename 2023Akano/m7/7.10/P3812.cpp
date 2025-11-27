#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MAXW = 77;
ll p[MAXW],n,ans;
inline bool Insert(ll x){
	for(int i = 60;i >= 0;i--){
		if(!(x >> i))continue;
		if(p[i] == 0){
			p[i] = x;
			return true;
		}
		x ^= p[i];
	}
	return false;
}
vector<pll> vec;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		ll inf,ins;cin>>inf>>ins;
		vec.push_back(make_pair(-ins,inf));
	}
	sort(vec.begin(),vec.end());
	for(auto i : vec){
		i.first = -i.first;
		if(Insert(i.second))ans += i.first;
	}
	cout<<ans<<flush;
	return 0;
}
