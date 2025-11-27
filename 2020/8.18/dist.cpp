#include<bits/stdc++.h>
using namespace std;
long long  n,d,x,y,i,ans;
int main(){
	freopen("dist.in","r",stdin);
	freopen("dist.out","w",stdout);
	cin>>n>>d;
	for(i = 0;i < n;i++){
		cin>>x>>y;
		x = abs(x);
		y = abs(y);
		if((x*x + y*y) <= (d*d)){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
