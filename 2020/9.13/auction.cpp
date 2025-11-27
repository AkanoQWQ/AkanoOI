#include<bits/stdc++.h>
using namespace std;
int n,m,p[2006],i,j,mmax,mmin = 1000000,c,k,cans,ans,ians,nai;
short ha[1000006];
int main(){
	freopen("auction.in","r",stdin);
	freopen("auction.out","w",stdout);
	cin>>n>>m;
	k = m-1;
	for(i = 0;i < m;i++){
		scanf("%lld",&p[i]);
		ha[p[i]]++;
		if(p[i] > mmax){
			mmax = p[i];
		}
		if(p[i] < mmin){
			mmin = p[i];
		}
	}
	for(i = 0;i < m;i++){
		for(j = i;j < m;j++){
			if(p[i] > p[j]){
				c = p[i];
				p[i] = p[j];
				p[j] = c;
			}
		} 
	}
	for(i = mmax;i > mmin; ){
		cans = 0;
		for(j = i;j <= mmax;j++){
			cans += ha[j] * i;
		}
		if(cans > ans){
			ans = cans;
			ians = i;
		}
		i = p[k];
		k--;
	}
	cout<<ians<<" "<<ans; 
	return 0;
}
