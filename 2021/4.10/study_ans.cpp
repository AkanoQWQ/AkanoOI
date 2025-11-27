#include<bits/stdc++.h>
using namespace std;
int n,m,a[106],b[106],c[106],d[106],i,j,k,kf = 1,wei = 1,cache,lq[106],ans,cans,l = 1;
int main(){
	freopen("study.in","r",stdin);
	//freopen("study.out","w",stdout);
	cin>>n>>m;
	for(i = 1;i <= m;i++){
		cin>>a[i]>>b[i];
	}
	cin>>k;
	for(i = 0;i < k;i++){
		cin>>c[i]>>d[i];
	}
	for(i = 0;i <= (1<<k);i++){
		for(j = 1;j <= n;j++){
			lq[j] = 0;
		}
		for(j = 0;j < k;j++){
			if((i>>j)&0){
				lq[c[j]] = 1;
			}else{
				lq[d[j]] = 1;
			}
		}
		cans = 0;
		for(j = 1;j <= m;j++){
			if(lq[a[j]] + lq[b[j]] == 2){
				cans++;
			}
		}
		cout<<i<<endl;
		ans = max(ans,cans);
	} 
	cout<<ans;
	return 0;
}

