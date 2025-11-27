#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
using ll = long long;
const int MAXN = 1e6;
const int SZ = MAXN + 1018 + 1108;
ll phi[SZ],ans[SZ];
bitset<SZ> vis;
vector<ll> pr;
inline void PreCalc(){
	phi[1] = 1;
	for(int i = 2;i <= MAXN;i++){
		if(!vis[i]){
			pr.push_back(i);
			phi[i] = i - 1;
		}
		for(auto p : pr){
			if(p * i > MAXN)break;
			vis[p * i] = true;
			if(i % p == 0){
				phi[i * p] = phi[i] * p;
				break;
			}
			phi[i * p] = phi[i] * (p - 1);//phi[p] = p - 1
		}
	}
	for(int i = 1;i <= MAXN;i++){
		for(int j = 1;i * j <= MAXN;j++){
			ans[i * j] += j * phi[j] / 2;
		}
	}
	for(int i = 1;i <= MAXN;i++){
		++ans[i];
		ans[i] *= i;
	}
	return ;
}
ll t,n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	PreCalc();
	while(t--){
		cin>>n;
		cout<<ans[n]<<'\n';
	}
	cout<<flush;
	return 0;
}
