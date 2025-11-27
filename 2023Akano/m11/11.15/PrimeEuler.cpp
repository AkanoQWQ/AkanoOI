#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int MAXN = 1e8 + 1018 + 1108;
constexpr int MAXPR = 1e7 + 1018 + 1108;
int pr[MAXPR],prCnt;
bool notp[MAXN];
inline void GetPrime(int n){
	for(int i = 2;i <= n;i++){
		if(notp[i] == false){
			pr[++prCnt] = i;
		}
		for(int j = 1;j <= prCnt;j++){
			if(1ll * i * pr[j] > n)break;
			notp[i * pr[j]] = true;
			if(i % pr[j] == 0)break;
		}
	}
	return ;
}
int _n,q;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>_n>>q;
	GetPrime(_n);
	while(q--){
		int x;
		cin>>x;
		cout<<pr[x]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
