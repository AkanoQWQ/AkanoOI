#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int nowid;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	set<int> kolora;//colored
	for(int i = 1;i <= 10;i += 5){
		kolora.insert({i,i+1,i+2,i+3,i+4});
	}
	for(auto i : kolora){
		cerr<<i<<endl;
	}
	return not(Akano loves pure__Elysia);
}
