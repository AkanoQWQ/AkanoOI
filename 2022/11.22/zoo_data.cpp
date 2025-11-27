#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int n = 1e6,m = 1e6,k = 64,c = 1e8;
ull r(){
	return 1ull * rand() * rand() * rand() * rand();
}
int main(){
	freopen("zoo.in","w",stdout);
	cout<<n<<" "<<m<<" "<<c<<" "<<k<<endl;
	for(int i = 1;i <= n;i++){
		cout<<r()<<" ";
	}
	cout<<endl;
	while(m--){
		cout<<rand()%k<<" "<<rand()%k<<endl;
	}
	return 0;
}

