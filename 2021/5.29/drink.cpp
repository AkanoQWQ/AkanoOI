#include<bits/stdc++.h>
using namespace std;
int n,x,v,p,total,i; 
int main(){
	freopen("drink.in","r",stdin);
	freopen("drink.out","w",stdout);
	cin>>n>>x;
	for(i = 0;i < n;i++){
		cin>>v>>p;
		total += ((v * p) / 100);
		if(total > x){
			cout<<i+1;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}

