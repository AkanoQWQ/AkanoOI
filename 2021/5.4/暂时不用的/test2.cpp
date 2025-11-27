#include<bits/stdc++.h>
using namespace std;
int n = 200,a = 10000,b = 8000;
int main(){
	freopen("bomb.in","w",stdout);
	cout<<n<<" "<<a<<" "<<b<<endl;
	for(int i = 0;i < n;i++){
		cout<<(rand() * 47) % ((5*b)+a)<<endl; 
	}
	return 0;
}

