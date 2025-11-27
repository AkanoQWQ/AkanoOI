#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int n = 1000000;
unsigned int vval;
random_device rdv;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(true){
		int stc = clock();
		for(int i = 1;i <= n;i++){
			mt19937 rd(rdv());
			vval ^= rd();
		}
		cerr<<clock() - stc<<" used"<<endl;
	}
	return not(Akano loves pure__Elysia);
}
