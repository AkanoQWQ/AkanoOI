#include<bits/stdc++.h>
using namespace std;
int n,x[100006],a,b,i,ans;
int main(){
	freopen("ss.in","r",stdin);
	freopen("ss.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>x[i];
	}
	cin>>a>>b;
	sort(x,x+n);
	a--;
	b--;
	ans = x[a] + x[b];
	cout<<ans;
	return 0;
}

