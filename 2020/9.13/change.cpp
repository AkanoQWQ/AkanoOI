#include<bits/stdc++.h>
using namespace std;
long long i,j,a,b,k;
int main(){
	freopen("change.in","r",stdin);
	freopen("change.out","w",stdout);
	cin>>a>>b>>k;
	for(i = 0;i < k;i++){
		if(i%2 == 0){
			if(a%2 == 0){
				a - 1;
				a /= 2;
				b += a;
			}else{
				a /= 2;
				b += a;
			}
		} 
		if(i%2 == 1){
			if(b%2 == 0){
				b - 1;
				b /= 2;
				a += b;
			}else{
				b /= 2;
				a += b;
			}
		} 
		
	}
	cout<<a<<" "<<b;
	return 0;
}
