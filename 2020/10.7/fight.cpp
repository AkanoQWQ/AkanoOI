#include<bits/stdc++.h>
using namespace std;//remember long long  
namespace stb{//常用数据库 
	void mycin(int b[],int n){
		for(int i = 0;i < n;i++){
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
int h[200006],i,j,cache,n,k;
long long ans;
int main(){
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	cin>>n>>k;
	stb::mycin(h,n);
	if(k > n){
		cout<<0;
		return 0;
	}
	for(i = 0;i < n;i++){
		for(j = i;j < n;j++){
			if(h[i] < h[j]){
				cache = h[i];
				h[i] = h[j];
				h[j] = cache;
			}
		}
	}
	for(i = k;i < n;i++){
		ans += h[i]; 
	}
	cout<<ans; 
	return 0;
}
