#include<bits/stdc++.h>
using namespace std;
long long h,i,cache,ans,n,m;
int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	cin>>n>>m;
	for(i = 0;i < m;i++){
		cin>>cache;
		h += cache;
	}
	if(h > n){
		ans = -1;
	}else{
		ans = n - h;
	}
	cout<<ans;
	return 0;
}
