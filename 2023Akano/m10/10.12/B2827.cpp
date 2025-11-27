#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 40000 + 2006 + 1018 + 1108;
int phi[MAXN],pr[MAXN],prCnt;
bool notp[MAXN];
int n;
inline void Euler(){
	for(int i = 2;i <= n;i++){
		if(notp[i] == false){
			pr[++prCnt] = i;
			phi[i] = i - 1;
		}
		for(int j = 1;j <= prCnt;j++){
			if(i * pr[j] > n)break;
			notp[i * pr[j]] = true;
			if(i % pr[j] == 0){
				phi[i * pr[j]] = phi[i] * pr[j];
				break;
			}else{
				phi[i * pr[j]] = phi[i] * (pr[j] - 1);
			}
		}
	}
	return ;
}
long long ans = 3;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	Euler();
	for(int i = 2;i <= n;i++){
		ans += phi[i] * 2;
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
