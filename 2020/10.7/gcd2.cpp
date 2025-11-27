#include<bits/stdc++.h>
using namespace std;//remember long long 
int gcd(int a,int b){
	if(a % b == 0){
		return b;
	}else{
		return gcd(b,a%b);
	}
}
int ccount[5006];
long long k,a,b,c,cache,ans;
int main(){
	//freopen("gcd.in","r",stdin);
	//freopen("gcd.out","w",stdout);
	cin>>k;
	for(a = 1;a <= k;a++){
		for(b = 1;b <= k;b++){
			cache = gcd(a,b);
			ccount[cache]++;
		}
	}
	for(c = 1;c <= k;c++){
		for(cache = 1;cache <= 2000;cache++){
			if(ccount[cache]){
				ans += 1ll * ccount[cache] * gcd(c,cache);
			}
		}
	}
	cout<<ans;
	return 0;
}
