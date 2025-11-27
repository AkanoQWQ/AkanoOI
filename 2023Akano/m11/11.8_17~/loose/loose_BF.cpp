#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
constexpr int MAXN = 1e6 + 1018 + 1108;
mt19937 rng(time(0));
int n,m,a[MAXN];
bool OK[MAXN];
inline int Calc(){
	int ret = 0;
	for(int l = 1;l <= n;l++){
		int mx = a[l],mn = a[l];
		for(int r = l;r <= n;r++){
			mx = max(mx,a[r]),mn = min(mn,a[r]);
			if(mx + mn > r - l + 1){
				ret = max(ret,r - l + 1);
				OK[r - l + 1] = true;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		cerr<<OK[i];
	}
	cerr<<endl;
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("loose5.in","r",stdin);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	cout<<Calc()<<'\n';
	for(int i = 1,k;i <= m;i++){
		cin>>k;
		for(int j = 1,x,y;j <= k;j++){
			cin>>x>>y;
			swap(a[x],a[y]);
		}
		cout<<Calc()<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
