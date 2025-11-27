#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e7 + 1018 + 1108;
ll phi[MAXN],pr[MAXN],sum[MAXN],prCnt;
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
ll ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	Euler();
	phi[1] = 1;//要算一下自己
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i-1] + phi[i];//包括自己
	}
	for(int i = 1;i <= prCnt;i++){
		ans += sum[n / pr[i]] * 2 - 1;//i,i会被算两边
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
