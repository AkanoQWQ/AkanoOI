#include<bits/stdc++.h>
using namespace std;
long long n = 1e4,m = 1e4,k = 1e18;
int main(){
	srand(time(0));
	freopen("rabbit.in","w",stdout);
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rand()%1000<<" ";
	}
	cout<<endl<<m<<" "<<k<<" "<<endl;
	for(int i = 1;i <= m;i++){
		cout<<((rand()*rand())%(n-3))+2<<" ";
	}
	return 0;
}
