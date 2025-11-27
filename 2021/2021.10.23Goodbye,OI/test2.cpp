#include<bits/stdc++.h>
using namespace std;
long long g[1000006],n,i,j,k,ans,lans = 1000000;
char a;
int main(){
	freopen("test.out","r",stdin);
	while(cin>>n){
		cin>>a;
		ans++;	
	}
	cout<<"打表已完成"<<ans<<endl<<double(double(ans)/1000000.00)*100<<"%"<<endl;
	cout<<"新增了"<<ans-lans;
	return 0;
	
} 
