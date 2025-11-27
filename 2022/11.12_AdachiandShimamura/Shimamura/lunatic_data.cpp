#include<bits/stdc++.h>
using namespace std;
int l,r,n = 100,k = 100;
int main(){
	freopen("lunatic.in","w",stdout);
	cout<<n<<" "<<k<<endl;
	for(int i = 1;i <= n;i++){
		r = 1,l = 2;
		while(l > r){
			l = rand();
			r = rand();
		}
		cout<<l<<" "<<r<<endl;
	}
	return 0;
}

