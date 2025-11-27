#include<bits/stdc++.h>
using namespace std;
int n,k,i,c;
int main(){
	freopen("maxm.in","r",stdin);
	freopen("maxm.in","w",stdout);
	cin>>n>>k;
	cout<<n<<" "<<k<<endl;
	for(i = 0;i < 12823;i++){
		c = rand();
	}
	for(i = 0;i < n;i++){
		cout<<rand()%(int(1.2* k))<<" ";
	}
	return 0;
}

