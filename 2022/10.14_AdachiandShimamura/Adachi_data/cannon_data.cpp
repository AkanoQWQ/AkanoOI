#include<bits/stdc++.h>
#define int long long
using namespace std;
int n = 250000,ST = 10000000000,m = 500,k = 10000000000;
int r(){
	return rand()*rand();
}
signed main(){
	srand(1919810);
	freopen("cannon.in","w",stdout);
	cout<<n<<' '<<m<<" "<<k<<endl;
	for(int i = 1;i <= n;i++){
		cout<<ST<<endl;
		ST -= r()%(9990000000/n*2);
	}
	//m--;
	while(m--){
		cout<<(r()*rand()*rand())%10000000000<<" "<<r()%2500000<<endl;
	}
	//cout<<10000000000<<" "<<2<<endl;
	return 0;
}

