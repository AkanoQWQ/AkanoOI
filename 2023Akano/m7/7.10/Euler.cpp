#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int MAXN = 1e8 + 6;
const int MAXSZ = 5800000;
int n,q,pr[MAXSZ],tail;
bitset<MAXN> vis;
inline void Euler(int up){
	for(int i = 2;i <= up;i++){
		if(!vis[i]){
			pr[++tail] = i;
		}
		for(int j = 1;j <= tail;j++){
			if(1ll * i * pr[j] > n)break;
			vis[i * pr[j]] = true;
			if(i % pr[j] == 0)break;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	Euler(n);
	while(q--){
		cin>>n;
		cout<<pr[n]<<endl;
	}
	return 0;
}
