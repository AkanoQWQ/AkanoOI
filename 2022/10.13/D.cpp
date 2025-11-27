#include<bits/stdc++.h>
using namespace std;
int t,n,a[1006],c;
int gcd(int x,int y){
	if(x%y == 0)return y;
	return gcd(y,x%y);
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int ans = -1;
		memset(a,0,sizeof(a));
		for(int i = 1;i <= n;i++){
			cin>>c;
			a[c] = i;
		}
		for(int i = 1;i <= 1000;i++){
			if(a[i] == 0)continue;
			for(int j = 1;j <= 1000;j++){
				if(a[j] == 0)continue;
				if(gcd(i,j) != 1)continue;
				ans = max(ans,a[i]+a[j]); 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
