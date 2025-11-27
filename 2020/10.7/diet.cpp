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
int a[200006],f[200006];
long long ans,n,k,cache,i,j;
int main(){
	freopen("diet.in","r",stdin);
	freopen("diet.out","w",stdout);
	cin>>n>>k;
	stb::mycin(a,n);
	stb::mycin(f,n);
	for(i = 0;i < n;i++){
		for(j = i;j < n;j++){//大-小 
			if(a[i] < a[j]){
				cache = a[i];
				a[i] = a[j];
				a[j] = cache;
			}
		}
	}
	for(i = 0;i < n;i++){
		for(j = i;j < n;j++){
			if(f[i] > f[j]){//小-大 
				cache = f[i];
				f[i] = f[j];
				f[j] = cache;
			}
		}
	}
	i = 0;
	while(k > 0 && i < n){
		if(k >= a[i]){
			k -= a[i];
			a[i] = 0;
			i++;
		}else{
			a[i] -= k;
			k = 0;
			i++;
		}
	}
	for(i = 0;i < n;i++){
		for(j = i;j < n;j++){//大-小 
			if(a[i] < a[j]){
				cache = a[i];
				a[i] = a[j];
				a[j] = cache;
			}
		}
	}
//	for(i = 0;i < n;i++){
//		if(ans < a[i] * f[i]){
//			ans = a[i] * f[i];
//		} 
//	}
	cout<<ans;
	return 0;
}
