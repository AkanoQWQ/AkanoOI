#include<bits/stdc++.h>
using namespace std;
int i,m,n,ans;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>m>>n;
	for(i = m;i <= n;i++){
		if(i%17 == 0){
			ans+=i;
		} 
	}
	printf("%d",ans);
	return 0;
}
