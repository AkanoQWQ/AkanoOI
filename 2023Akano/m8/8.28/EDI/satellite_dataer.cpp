#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MOD = 2001;
Rander rd;
int n = 1000,q = 2e5;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("ex_satellite.in","w",stdout);
	cout<<n<<" "<<q<<" "<<rd(1,MOD-1)<<" "<<rd(1,MOD-1)<<" "<<int(1e9+7)<<" "<<rd(1,MOD-1)<<" "<<rd(1,MOD-1)<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rd(1,MOD-1)<<" "<<rd(1,MOD-1)<<" "<<rd(1,MOD-1)<<endl;
	}
	for(int i = 1;i <= q;i++){
		cout<<rd(1,MOD-1)<<" "<<rd(1,MOD-1)<<endl;
	}
	return not(Akano loves pure__Elysia);
}
