#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1018;
ll n,a[MAXN],ans,l,r,sz,t;
set<int> st;
inline int Rank(int k){
	auto it = st.find(k);
	int ret = 1;
	while(it != st.begin()){
		++ret;
		it--;
	}
	return ret;
}
vector<int> opt; 
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("AT092_c.in","r",stdin);
	cin>>t;
	while(t--){
		ans = -1e9;
		cin>>n;
		bool allf = true;
		ll mx = -1e9;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			mx = max(mx,a[i]);
			if(a[i] >= 0)allf = false;
		}
		if(allf){
			cout<<mx<<endl;
			continue;
		}else{
			for(int i = 1;i <= n;i++){
				a[i] = max(a[i],0ll);
			}
		}
		for(int i = 1;i <= n;i++){
			ll cnt = 0;
			for(int j = i;j <= n;j += 2){
				cnt += a[j];
				if(cnt > ans){
					l = i,r = j;
					ans = cnt;
				}
			}
			cnt = 0;
			for(int j = i+1;j <= n;j += 2){
				cnt += a[j];
				if(cnt > ans){
					l = i+1,r = j;
					ans = cnt;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
