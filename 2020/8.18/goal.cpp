#include<bits/stdc++.h>
using namespace std;
long long zong,cache,ans,k,i,n,m;
int main(){
	freopen("goal.in","r",stdin);
	freopen("goal.out","w",stdout);
	cin>>n>>k>>m;
	for(i = 0;i < n-1;i++){
		cin>>cache;
		zong += cache; 
	}
	ans = n * m - zong;
	if(ans < 0)ans = 0;
	if((zong + k) < (n * m)){
		ans = -1;
	}
	cout<<ans;
	return 0;
}
