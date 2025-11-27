#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 506;
const int PY = 2006;
using Block = bitset<MAXN>;
int n,o;
char mp[MAXN][MAXN];
Block lr[MAXN],ud[MAXN],rd[MAXN*8];//left-right up-down right-down(斜线)
long long ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("firstsnow.in","r",stdin);
	freopen("firstsnow.out","w",stdout);
	cin>>n>>o;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin>>mp[i][j];
			lr[i][j] = (mp[i][j] == '1');
			ud[j][i] = (mp[i][j] == '1');
			rd[PY+i-j][j] = (mp[i][j] == '1');
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(mp[i][j] == '0')continue;
			for(int delta = 1;delta < i;delta++){//delta = 0 的贡献由下面算
				Block now = lr[i-delta] >> (j-1);
				now &= (ud[j + delta] >> (i-1));
				now &= (rd[PY+i-j-delta*2] >> (j+delta-1));
				int deltaAns = now.count();
				if(now[0])deltaAns--;//不计算0!
				ans += deltaAns;
			}
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
