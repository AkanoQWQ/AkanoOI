#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,d,e,f,ans = 1<<30;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	cin>>a>>b>>c>>d>>e>>f;
	if(n%a == 0){
		ans = min(ans,(n/a)*b);
	}else{
		ans = min(ans,(n/a+1)*b);
	}
	if(n%c == 0){
		ans = min(ans,(n/c)*d);
	}else{
		ans = min(ans,(n/c+1)*d);
	}
	if(n%e == 0){
		ans = min(ans,(n/e)*f);
	}else{
		ans = min(ans,(n/e+1)*f);
	}
	cout<<ans;
	return 0;
}

