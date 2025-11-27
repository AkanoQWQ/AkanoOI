#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
ll n,d,a[MAXN],x[MAXN],s[MAXN];
double ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>d;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>x[i];
		s[i] = s[i-1] + a[i];
		double y = 0;
		double upperi = s[i],loweri = x[i] + i * d;
		for(int j = i;j >= 1;j--){
			y = max(y,double(upperi - s[j-1]) / double(loweri - d * j));
		}
		ans += y;
	}
	cout<<fixed<<setprecision(0)<<ans<<endl;
	return 0;
}
