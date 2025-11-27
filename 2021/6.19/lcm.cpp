#include<bits/stdc++.h>
using namespace std;

long long gcd(int x,int y){
	long long mmax = max(x,y);
	for(long long i = 2;i <= sqrt(mmax);i++){
		if(x % i == 0 && y % i == 0){
			return gcd(x/i,y/i)*i;
		}
	}
	return 1;
}
const long long ii = 246913578;
long long n,m;
int main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	cin>>n;
	m = gcd(n,ii);
	cout<<((n%1234567890) * (ii%1234567890) / (m%1234567890))%1234567890;
	return 0;
}

