#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int siz = 2e5;
const int n = 1e3;
const double poss = (1 - double(n) / double(siz));
double ans = 1;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 1;i <= n;i++){
		ans *= poss;
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
