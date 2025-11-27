#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
constexpr int MAXN = 506;
int dis[MAXN];
int n,q,d,a[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("firebig.in","r",stdin);
	freopen("firebig.out","w",stdout);
	cin>>n>>q>>d;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		for(int i = l;i <= r;i++){
			dis[i] = MAXN;
		}
		dis[l] = 0;
		for(int i = l;i <= r;i++){
			vector<pii> vec;
			for(int j = i+1;j <= r;j++){
				vec.emplace_back(-a[j],j);
			}
			sort(vec.begin(),vec.end());
			for(int j = 0;j < min(int(vec.size()),d);j++){
				dis[vec[j].second] = min(dis[vec[j].second],dis[i] + 1);
			}
		}
		cout<<dis[r]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
