#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 100;
int f[MAXN][MAXN][MAXN],s[MAXN][MAXN][MAXN],n,k,pos[MAXN],b;
int main(){
	freopen("E.in","r",stdin);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		int bc;cin>>bc;
		if(bc == true)pos[++b] = i;
	}
	f[0][0/*2?4?6?*/][0] = 1;
	s[0][0][0] = 1;
	for(int i = 1;i <= b;i++){
		for(int j = 0;j <= k;j++){
			for(int x = 1;x <= n;x++){
				const int use_step = j - abs(x-pos[i]);
				if(use_step < 0)continue;
				for(int dx = 0;dx < x;dx++){
					f[i][j][x] += f[i-1][use_step][dx];
				}
			}
		}
	}
	long long ans = 0;
	for(int i = 0;i <= n;i++){
		for(int j = 0;k - 2 * j >= 0;j++){
			ans += f[b][k - 2 * j][i];
		}
	}
	cout<<ans<<endl;
	return 0;
}

