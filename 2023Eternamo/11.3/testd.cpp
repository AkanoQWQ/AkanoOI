#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n = 34;
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 2*n;j++){
			if((i^j) < n){
				cout<<1;
			}else{
				cout<<0;
			}
		}
		cout<<endl;
	}
	return not(Akano loves pure__Elysia);
}
