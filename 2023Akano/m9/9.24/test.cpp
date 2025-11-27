#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
ll k = 10,cnt,times = 10;
int main(){
	mt19937 rng(time(0));
	for(int t = 1;t <= times;t++){
		ll pos = 1000;
		while(pos != 1000 + 2*k){
			ll dis = rng() % (k+1);
			if(rng() % 2){
				pos += dis;
			}else{
				pos -= dis;
			}
			++cnt;
		}
	}
	cnt /= times;
	cout<<cnt<<endl;
	return not(Akano loves pure__Elysia);
}
