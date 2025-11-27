#include<bits/stdc++.h>
using namespace std;
int yuan[200006],n,i,cache;
int main(){
	freopen("boss.in","r",stdin);
	freopen("boss.out","w",stdout);
	cin>>n;
	for(i = 2;i <= n;i++){
		cin>>cache;
		yuan[cache]++;
	}
	for(i = 1;i <= n;i++){
		cout<<yuan[i]<<endl;
	}
	return 0;
}
