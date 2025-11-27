#include<bits/stdc++.h>
using namespace std;
long long n = 11,a = 2;
int main(){
	srand(time(0));
	freopen("t2.in","w",stdout);
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		a += rand()*rand();
		cout<<a<<" ";
	}
	cout<<rand()*rand()*1ll*rand() + 1;
	return 0;
}

