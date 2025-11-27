#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e8 + 6;
bitset<MAXN> vis;
int prime[20061108],tot,n;
void ol(){
	for(int i = 2;i <= n;i++){
		if(vis[i] == 0){
			prime[++tot] = i;
		}
		for(int j = 1;j <= tot;j++){
			if(1ll * i * prime[j] > n)break;
			vis[i*prime[j]] = 1;
			if(i % prime[j]== 0)break;
		}
	}
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	ol();
	cout<<prime[tot];
	return 0;
}
