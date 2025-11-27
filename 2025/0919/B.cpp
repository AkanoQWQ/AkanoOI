#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 5e7 + 1018 + 1108;
bitset<MAXN> notp,f;
vector<int> prime;
int minp[MAXN];
int n;
inline void Eu(){
	for(int i = 2;i <= n;i++){
		if(notp[i] == false){
			minp[i] = 1;
			prime.push_back(i);
		}
		for(auto p : prime){
			if(i * p > n)continue;
			notp[i * p] = true;
			minp[i * p] = p;
			if(i % p == 0)break;
		}
	}
	return ;
}
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	Eu();
	f[0] = 1;//f[1] = 0
	for(int i = 1;i <= n;i++){
		const int res = i / minp[i];
		if(res % minp[i] == 0){
			
		}
		f[i] = !f[minp[i]];
		cerr<<i<<" : "<<minp[i]<<" is "<<f[i]<<endl;
	}
	return not(Akano loves pure__Elysia);
}
