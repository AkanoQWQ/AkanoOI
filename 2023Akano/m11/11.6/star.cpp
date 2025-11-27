#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
constexpr int MAXN = 1e6 + 1018 + 1108;
int n,T,L,R,reachL,reachR;
pii arr[MAXN];
struct Transform{
	int x,y,z;
}trans[MAXN];
inline int Calc(int x){
	for(int i = 1;i <= T;i++){
		if(x % trans[i].x == trans[i].y){
			x += trans[i].z;
		}
	}
	return x;
}
vector<int> otp;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	cin>>n>>T;
	for(int i = 1;i <= n;i++){
		cin>>arr[i].first;
		arr[i].second = i;
	}
	for(int i = 1;i <= T;i++){
		cin>>trans[i].x>>trans[i].y>>trans[i].z;
	}
	cin>>L>>R;
	sort(arr+1,arr+n+1);
	{
		int l = 1,r = n + 1;
		while(l < r){
			const int mid = (l + r) >> 1;
			if(Calc(arr[mid].first) >= L){
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		reachL = r;
	}
	{
		int l = 1,r = n + 1;
		while(l < r){
			const int mid = (l + r) >> 1;
			if(Calc(arr[mid].first) <= R){
				l = mid + 1;
			}else{
				r = mid;
			}
		}
		reachR = l - 1;
	}
	for(int i = reachL;i <= reachR;i++){
		otp.push_back(arr[i].second);
	}
	sort(otp.begin(),otp.end());
	cout<<otp.size()<<endl;
	for(auto i : otp){
		cout<<i<<" ";
	}
	cout<<endl;
	return not(Akano loves pure__Elysia);
}
