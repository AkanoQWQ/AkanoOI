#include<bits/stdc++.h>
using namespace std;
int i,c,n,l,r,x,t,ans;
int a[30006];
int main(){
	freopen("orange.in","r",stdin);
	freopen("orange.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>a[i];
	}
	/*for(i = 0;i < n;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;*/
	for(l = 0;l < n;l++){
		x = 20061108;
		for(r = l;r < n;r++){
			x = min(x,a[r]);
			ans = max((x * (r-l+1)),ans);
			//cout<<"l:"<<l<<",r:"<<r<<",x:"<<x<<",t:"<<(x * (r-l+1))<<endl;
		}
	}
	cout<<ans;
	return 0;
}

