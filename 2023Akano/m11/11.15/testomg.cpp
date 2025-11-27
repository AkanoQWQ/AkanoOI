#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n = 1e7,sum;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 1;i <= n;i++){
		sum += log(n / i);
	}
	cout<<n<<" compare "<<sum<<endl;
	return not(Akano loves pure__Elysia);
}
