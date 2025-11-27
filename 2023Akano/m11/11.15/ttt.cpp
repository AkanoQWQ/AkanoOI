#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
inline bool ISP(int x){
	for(int i = 2;i * i <= x;i++){
		if(x % i == 0)return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int pr = 0;
	for(int i = 2;i <= 300;i++){
		if(ISP(i))pr++;
	}
	cout<<pr<<endl;
	return not(Akano loves pure__Elysia);
}
