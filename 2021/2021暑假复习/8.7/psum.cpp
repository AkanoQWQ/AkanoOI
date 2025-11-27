#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10006;
int pri[MAXN],n,m,ans;
bool ispri[MAXN];
void cai(int n){
	ispri[1] = 0;
	m = 0;
	for(int i = 2;i <= n;i++){
		if(ispri[i] == 1)pri[++m] = i;
		for(int j = 1;j <= m;j++){
			if(pri[j] > n/i)break;
			ispri[i * pri[j]] = 0;
			if(i % pri[j] == 0)break;
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	memset(ispri,1,sizeof(ispri));
	cai(10000);
	while(1){
		cin>>n;
		ans = 0;
		if(n == 0)break;
		for(int i = 0;i < m;i++){
			if(pri[i] >= n/2)break;
			if(ispri[n - pri[i]] == 1){
				ans++;
			}
		}	
		cout<<ans<<" ";
	}
	
	return 0;
}

