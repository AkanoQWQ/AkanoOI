#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1006;
int T,n,a[MAXN],d[MAXN],k;
bool bg(int _a,int _b){
	return _a > _b;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		int ans = 0;
		cin>>n>>k;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			d[i] = abs(a[i] - a[i-1]);
		}
		d[1] = 0;
		sort(d+1,d+n+1,bg);
		for(int i = k;i <= n;i++){
			ans += d[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

