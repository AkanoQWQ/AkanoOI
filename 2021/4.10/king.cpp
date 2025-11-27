#include<bits/stdc++.h>
using namespace std;
long long n,x[106],y[106],t[106],s,d,i,j;
int main(){
	freopen("king.in","r",stdin);
	freopen("king.out","w",stdout);
	cin>>n>>s>>d;
	for(i = 0;i < n;i++){
		cin>>x[i]>>y[i];
		t[i] = ((d/x[i])) * y[i];
		//cout<<(d/x[i])<<" "<<y[i]<<endl;
	}
	for(i = 0;i < n;i++){
		//cout<<t[i]<<" ";
		if(t[i] > d){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}
/*3 691 273
691 997
593 273
691 273*/

