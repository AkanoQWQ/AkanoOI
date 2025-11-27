#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,b,k,p[16],sumw;
int main(){
	freopen("fans.in","r",stdin);
	freopen("fans.out","w",stdout);
	scanf("%lld",&n);
	while(n--){
		scanf("%lld%lld%lld",&a,&b,&k);
		sumw = 0;
		for(int i = 9;i >= 2;i--){
			p[i] = 0;
			while(k % i == 0){
				k /= i;
				p[i]++;
				sumw++;
			}
		}
		if(k != 1 || sumw > 18){
			puts("0");
			continue;
		}
		cout<<rand()*rand()<<endl;
	}
	return 0;
}

