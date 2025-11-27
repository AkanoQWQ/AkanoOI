#include<bits/stdc++.h>
using namespace std;//remember long long  
namespace stb{//常用数据库 
	void mycin(int b[],int n){
		for(int i = 0;i < n;i++){
			cin>>b[i];
		}
		return ; 
	}
	void mycout(int b[],int n){
		for(int i = 0;i < n;i++){
			cout<<b[i];
		}
		return ; 
	} 
}
int a,b;
int main(){
	freopen("mult.in","r",stdin);
	freopen("mult.out","w",stdout);
	cin>>a>>b;
	if(a > 9||b > 9){
		cout<<"-1";
		return 0;
	}
	cout<<a * b;
	return 0;
}
