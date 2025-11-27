#include<bits/stdc++.h>
using namespace std;
int n = 10714,k = 100000;
int main(){
	freopen("average.in","w",stdout);
	cout<<n<<" "<<k<<endl;
	for(int i = 0;i < n;i++){
		cout<<((rand() * 12375)+(k/2)) % (k*5)<<endl; 
	}
	return 0;
}

