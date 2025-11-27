#include<bits/stdc++.h>
using namespace std;//6000000
int n,q,x,y,a[4000006],k,ns[4000006],ts[4000006],tail,i,j,Q,ans;
bool FOUND;
int main(){
	freopen("count.in","r",stdin);
	freopen("count2.out","w",stdout);
	cin>>n>>Q;
	for(i = 1;i <= n;i++){
		cin>>a[i];
		FOUND = 0;
		for(j = 0;j < tail;j++){
			if(ns[j] == a[i]){
				FOUND = 1;
				break;
			}
		}
		if(!FOUND){
			ns[tail] = a[i];
			tail++;
		}
	}
	Q = 100;
	for(i = 0;i < Q;i++){
		cin>>x>>y;
		ans = 0;
		memset(ts,0,sizeof(ts));
		for(j = x;j <= y;j++){
			for(k = 0;k < tail;k++){
				if(ns[k] == a[j]){
					ts[k]++;
					break;
				}
			}
		}
		for(j = 0;j < tail;j++){
			if(ts[j] == ns[j])ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

