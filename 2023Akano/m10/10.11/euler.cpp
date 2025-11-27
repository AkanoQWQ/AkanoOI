#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e8 + 1018 + 1108;
const int MAXPR = 2e6 + 1018 + 1108;
bitset<MAXN> notp;
int pr[MAXPR],prCnt,n,q,idx;
inline void Euler(int up){
	for(int i = 2;i <= up;i++){
		if(notp[i] == false){
			pr[++prCnt] = i;
		}
		for(int j = 1;j <= prCnt;j++){
			if(1ll * i * pr[j] > up)break;
			notp[i * pr[j]] = true;
			if(i % pr[j] == 0)break;//是最小质因数
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	Euler(n);
	while(q--){
		cin>>idx;
		cout<<pr[idx]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
