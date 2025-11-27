#include<bits/stdc++.h>
using namespace std;
using ll = long long;
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
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		ll inx;cin>>inx;
		cout<<Insert(inx)<<"!"<<endl;
	}
	for(int i = 60;i >= 0;i--){
		if((ans ^ p[i]) > ans)ans ^= p[i];
	}
	cout<<ans<<flush;
	return 0;
}
