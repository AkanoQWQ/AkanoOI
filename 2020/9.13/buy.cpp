#include<bits/stdc++.h>
using namespace std;
long long need,money,cache1,cache2;
int main(){
	freopen("buy.in","r",stdin);
	freopen("buy.out","w",stdout);
	cin>>cache1;
	cin>>cache2;
	need += cache1 * cache2;
	cin>>cache1;
	cin>>cache2;
	need += cache1 * cache2;
	cin>>money;
	if(money >= need){
		cout<<"YES"<<endl<<money-need;
	}else{
		cout<<"NO"<<endl<<need-money;
	}
	return 0;
}
