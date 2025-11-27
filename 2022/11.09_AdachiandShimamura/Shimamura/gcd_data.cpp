#include<bits/stdc++.h>
using namespace std;
int n = 3e5,MOD = 1.5e7;
int r(){
	return 1ll * rand() * rand();
}
int main(){
	srand(time(0));
	freopen("gcd.in","w",stdout);
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rand()%MOD + 1<<" ";
	}
	return 0;
}

