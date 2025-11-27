#include<bits/stdc++.h>
using namespace std;
long long n = 1e18,m = 1e5;
long long r(){
	return abs(1ll*rand()*rand()*rand()/2*rand());
}
int main(){
	srand(time(0));
	freopen("erchatree.in","w",stdout);
	cout<<n<<" "<<m<<endl;
	while(m--){
		cout<<r()<<endl;
	}
	return 0;
}

