#include<bits/stdc++.h>
using namespace std;
int n,l,mn = 0,mx = 0;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>l>>n;
	for(int i = 1;i <= n;i++){
		int c;
		cin>>c;
		mn = max(mn,min(c,l-c));
		mx = max(mx,max(c,l-c));
	}
	cout<<mn<<" "<<mx;
	return 0;
}
