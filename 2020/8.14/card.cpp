#include<bits/stdc++.h>
using namespace std;
int a,b,c,k,ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b>>c>>k;
	if(k <= a){
		cout<<k;
		return 0;
	}else if(k <= a+b){
		cout<<a;
		return 0;
	}else if(k > a+b){//k > a+b
		cout<<2*a+b-k;
		return 0;
	}
	return 0;
}
