#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2006;
const ll MOD = 1e9+7;
const int movex[4] = {1,0,-1,0};
const int movey[4] = {0,1,0,-1};//1 3
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
string sread(){
    string s = "";
    char c = getchar();
    while(c != '.' && c != '#'){
		s += c;
		c = getchar();
	}
    while(c == '.' || c == '#'){
		s += c;
		c = getchar();
	}
    return s;
}
int r,c;
string mp[MAXN];
int di;
int heng[MAXN][MAXN];
int shu[MAXN][MAXN];
int findp(int x,int y){
	int ret = 1;
	for(int k = 0;k < 4;k++){
		int OX = x + movex[k],OY = y + movey[k];
		while(OX >= 1 && OX <= r && OY >= 1 && OY <= c && mp[OX][OY] == '.'){
			ret++;
			OX += movex[k];
			OY += movey[k];
		}
	}
	return ret;
}
ll ans;
ll ksm(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1 == 1){
			ret *= a;
			ret %= MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;88180019
}
ll mo(ll a,ll b){
	return (a * ksm(b,MOD-2)) % MOD;
}
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	r = read(),c = read();
	for(int i = 1;i <= r;i++){
		mp[i] = "!" + sread();
	}
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= c;j++){
			if(mp[i][j] == '.'){
				di = findp(i,j);
				int di2 = 1;
				for(int k = 1;k <= di;k++){
					di2 *= 2;
					di2 %= MOD;
				}
				ans += mo((di2 - 1),di2);
				ans %= MOD;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
