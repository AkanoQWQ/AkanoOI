#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
int n,m,MOD = 1019663265,t = 200;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("data1.in","w",stdout);
	n = rd(800,1000),m = rd(800,1000);
	cout<<n<<" "<<m<<" "<<t<<" "<<MOD<<endl;
	for(int i = 1;i <= t;i++){
		cout<<rd(1,n)<<" "<<rd(1,m)<<endl;
	}
	return not(Akano loves pure__Elysia);
}

