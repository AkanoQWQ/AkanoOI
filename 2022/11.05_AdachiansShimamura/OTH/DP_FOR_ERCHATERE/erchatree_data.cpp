#include<bits/stdc++.h>
using namespace std;
long long n = 6e6,m = 1e5;
long long r(){
	return 1ll*rand()*rand()*rand()/2*rand();
}
int main(){
	srand(time(0));
	freopen("erchatree.in","w",stdout);
	cout<<n<<" "<<m<<endl;
	while(m--){
		cout<<(r()%n) + 1<<endl;
	}
	return 0;
}

