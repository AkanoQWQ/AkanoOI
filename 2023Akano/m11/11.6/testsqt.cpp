#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int num = 1704151;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 2;i*i <= num;i++){
		if(num % i == 0){
			cerr<<i<<" and "<<num/i<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}
