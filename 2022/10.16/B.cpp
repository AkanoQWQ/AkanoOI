#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,q;
int main(){
	scanf("%lld",&t);
	while(t--){
		ll odd = 0,even = 0,sum = 0,c;
		scanf("%lld%lld",&n,&q);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&c);
			sum += c; 
			if(c % 2 == 0){
				even++;
			}else{
				odd++;
			}
		}
		while(q--){
			ll opt,x;
			scanf("%lld%lld",&opt,&x);
			if(opt == 0){
				sum += x * even;
				if(x % 2 == 1){
					odd += even;
					even = 0;
				}
			}else{
				sum += x * odd;
				if(x % 2 == 1){
					even += odd;
					odd = 0;
				}
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}
