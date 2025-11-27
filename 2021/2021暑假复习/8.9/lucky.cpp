#include<bits/stdc++.h>
using namespace std;
int n,num,ans,wei = 1,c,b,num2,sum;
int main(){
	freopen("lucky.in","r",stdin);
	freopen("lucky.out","w",stdout);
	while(1){
		ans = 0,sum = 0,wei = 1;
		cin>>b;
		if(b == 0)break;
		cin>>num;
		num2 = num;
		while(num != 0){
			c = num % 10;
			ans += c * wei;
			num /= 10;
			wei *= b;
		}
		while(num2 != 0){
			c = num2 % 10;
			sum += c;
			num2 /= 10;
		}
		if(ans % sum == 0){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
	
	return 0;
}

