#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cout<<(1<<64)<<endl;
	cout<<(1ll<<62)<<endl;
	cout<<(1ll<<63)<<endl;
	cout<<(1ll<<64)<<endl;
	cout<<(1ull<<64)<<endl;
	cout<<((1ull<<63)-1)*2 + 1<<endl;
	unsigned long long a = 1;
	for(int i = 1;i <= 63;i++){
		a *= 2;
	}
	cout<<a<<endl;
	cout<<((a-1)*2)+1<<endl;
	cout<<a*2<<endl;
	return 0;
}
18446744073709551616
