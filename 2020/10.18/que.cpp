#include<bits/stdc++.h>
using namespace std;//remember long long  
namespace stb{//常用数据库 
	void mycin(int b[],int n){
		for(int i = 1;i <= n;i++){
			scanf("%d",&b[i]);
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
int a[10006],b[10006],n,m,l,r,c,i;
int main(){
	freopen("que.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	stb::mycin(a,n);
	for(i = 1;i <= m;i++){
		cin>>l>>r>>c;
		b[l] += c;
		b[r+1] -= c;
	}
	for(i = 1;i <= n;i++){
		b[i] = b[i] + b[i-1];
	}
	for(i = 1;i <= n;i++){
		a[i] += b[i];
		cout<<a[i]<<" ";
	}
	return 0;
}
