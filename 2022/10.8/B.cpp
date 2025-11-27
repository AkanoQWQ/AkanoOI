#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100006;
int t,n,a[MAXN];
int gcd(int x,int y){
	if(x%y == 0)return y;
	return gcd(y,x%y);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
			if(i > 1)cout<<gcd(a[i],a[i-1])<<" ";
		}
		cout<<endl;
	}
	return 0;//z2=a2/a1*z3  z4=a3/a2*z5
}
/*
4 2 4


*/
