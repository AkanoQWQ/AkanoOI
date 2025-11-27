#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 3006;
int n,m,k;
ll ans,s[MAXN][MAXN];
bool Judge(int x,int y,int delta){
	return !(s[x+delta-1][y+delta-1] - s[x-1][y+delta-1] - s[x+delta-1][y-1] + s[x-1][y-1]);
}
inline ll Query(int x,int y){
	ll ret = 0;
	int l = 1,r = min(m - y + 1,n - x + 1) + 1;
	while(l < r){
		const int mid = (l + r) >> 1;
		if(Judge(x,y,mid)){
			ret = mid;
			l = mid + 1;
		}else{
			r = mid;//correct?
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 1;i <= k;i++){
		int x,y;
		cin>>x>>y;
		s[x][y]++;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			s[i][j] += s[i][j-1] + s[i-1][j] - s[i-1][j-1];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			ans += Query(i,j);
		}
	}
	cout<<ans<<endl;
	return 0;
}

