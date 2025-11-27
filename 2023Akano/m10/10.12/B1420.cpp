#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e6 + 1018 + 1108;
bool notp[MAXN];
int pr[MAXN],prCnt,n;
inline void GetPrime(){
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
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	GetPrime();
	for(int i = 1;i <= prCnt;i++){
		int now = pr[i],cnt = 0;
		while(true){
			cnt += n / now;
			if(1ll * pr[i] * now <= n){
				now *= pr[i];
			}else{
				break;
			}
		}
		cout<<pr[i]<<" "<<cnt<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
