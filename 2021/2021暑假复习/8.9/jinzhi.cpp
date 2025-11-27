#include<bits/stdc++.h>
using namespace std;
int n,num,ans,wei = 1,c;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>num;
	while(num != 0){
		c = num % 10;
		ans += c * wei;
		num /= 10;
		wei *= n;
	}
	cout<<ans;
	return 0;
}

