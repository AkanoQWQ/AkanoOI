#include<bits/stdc++.h>
using namespace std;
long long a,b,s[200611],t,i,j,k;
int main(){
	freopen("divisor.in","r",stdin);
	freopen("divisor.out","w",stdout);
	cin>>a>>b>>k;
	for(i = 1;i <= 100;i++){
		if(a % i == 0 && b % i == 0){
			s[t] = i;
			t++;
		}
	}
	cout<<s[t-k];
	return 0;
}

