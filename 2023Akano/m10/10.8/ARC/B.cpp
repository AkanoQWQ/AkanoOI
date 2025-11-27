#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
const ll INF = 3e18 + 2;
ll ans = INF,a,b,c,arr[MAXN],n,now;
vector<pair<ll,int> > ans1,ans2,ans3;
inline ll Near(ll x,ll y){
	ll bs = x / y;
	while(bs * y < x)bs++;
	return bs * y - x;
}
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a % b);
}
inline ll LCM(ll a,ll b){
	return a / gcd(a,b) * b;
}
inline void Execute(){
	ans1.clear(),ans2.clear();
	ll ablcm = LCM(a,b);
	for(int i = 1;i <= n;i++){
		ans1.emplace_back(Near(arr[i],ablcm),i);
		ans2.emplace_back(Near(arr[i],c),i);
	}
	sort(ans1.begin(),ans1.end());
	sort(ans2.begin(),ans2.end());
	for(int i = 0;i < min(100,int(ans1.size()));i++){
		for(int j = 0;j < min(100,int(ans2.size()));j++){
			if(ans1[i].second == ans2[j].second){
				continue;
			}
			ans = min(ans,ans1[i].first + ans2[j].first);
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>a>>b>>c;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	//a,b,c单独
	ans1.clear(),ans2.clear(),ans3.clear();
	for(int i = 1;i <= n;i++){
		ans1.emplace_back(Near(arr[i],a),i);
		ans2.emplace_back(Near(arr[i],b),i);
		ans3.emplace_back(Near(arr[i],c),i);
	}
	sort(ans1.begin(),ans1.end());
	sort(ans2.begin(),ans2.end());
	sort(ans3.begin(),ans3.end());
	for(int i = 0;i < min(12,int(ans1.size()));i++){
		for(int j = 0;j < min(12,int(ans2.size()));j++){
			for(int k = 0;k < min(12,int(ans3.size()));k++){
				if(ans1[i].second == ans2[j].second || ans1[i].second == ans3[k].second || ans2[j].second == ans3[k].second){
					continue;
				}
				ans = min(ans,ans1[i].first + ans2[j].first + ans3[k].first);
			}
		}
	}
	//a,b一起
	Execute();
	//a,c一起
	swap(b,c);
	Execute();
	//b,c一起
	swap(a,c);
	Execute();
	//a,b,c一起
	ll totgcd = LCM(a,LCM(b,c));
	for(int i = 1;i <= n;i++){
		ans = min(ans,Near(arr[i],totgcd));
	}
	assert(ans >= 0);
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
