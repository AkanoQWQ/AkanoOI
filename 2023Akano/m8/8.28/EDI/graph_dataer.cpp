#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
int t = 1,n = 1e5,m = 10;
inline void Make(){
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i <= m;i++){
		cout<<rd(1,n)<<" ";
	}
	cout<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("ex_graph.in","w",stdout);
	cout<<t<<endl;
	for(int turn = 1;turn <= t;turn++){
		Make();
	}
	return not(Akano loves pure__Elysia);
}

