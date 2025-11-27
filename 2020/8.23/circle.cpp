#include<bits/stdc++.h>
using namespace std;
long long n,cache,zj = 100003,zhuo[200006],i,ji = 100003,jii = 1,lr,ans,ls,rs,l = 200000,r = 10;
priority_queue <long long> a;
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		scanf("%lld",&cache);
		a.push(cache);
	} 
	for(i = 0;i < n;i++){
		cache = a.top();
		a.pop();
		//cout<<cache<<endl;
		zhuo[ji] = cache;
		ls = zhuo[ji-1];
		rs = zhuo[ji+1];
		if(zhuo[ji-1] == 0){
			ls = zhuo[r];
		}
		if(zhuo[ji+1] == 0){
			rs = zhuo[l];
		}
		if(ls > rs){
			ans += rs;
		}else{
			ans += ls;
		}
		//cout<<i<<":"<<ls<<" "<<rs<<" "<<ans<<endl;
		if(ji < l){
			l = ji;
		}
		if(ji > r){
			r = ji;
		}
		if(lr){
			lr = 0;
			ji -= jii;
			jii++;
		}else{
			lr = 1;
			ji += jii;
			jii++;
		}
	}
	cout<<ans;
	return 0;
}
