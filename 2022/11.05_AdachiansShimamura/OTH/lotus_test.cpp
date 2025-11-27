#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 200006;
vector<ll> mp[MAXN];
ll t,n,m,inll,sum,k,ans,lastm;
vector<ll> s[MAXN];
bool judge(int px1,int py1,int px2,int py2){
	int fd = s[px2][py2] + s[px1-1][py1-1];
	return ((fd - s[px1-1][py2] - s[px2][py1-1]) == k);
}
inline ll read(){
	ll ret = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return ret * f;
}
void write(ll inx){
	if(inx < 0){
		inx = -inx;
		putchar('-');
	}
	if(inx > 9){
		write(inx / 10);
	}
	putchar((inx%10) + '0');
}
int main(){
	freopen("lotus.in","r",stdin);
	freopen("lotus2.out","w",stdout);
	t = read();
	while(t--){
		n = read(),m = read();
		sum = 0;
		ans = 0;
		s[0].clear();
		for(int i = 0;i <= m;i++){
			s[0].push_back(0);
		}
		for(int i = 1;i <= n;i++){
			mp[i].clear();
			s[i].clear();
			mp[i].push_back(114514);
			s[i].push_back(0);
			for(int j = 1;j <= m;j++){
				inll = read();
				sum = inll;
				sum += s[i][j-1] + s[i-1][j] - s[i-1][j-1];
				mp[i].push_back(inll);
				s[i].push_back(sum);
			}
		}
		k = read();
		for(int posx1 = 1;posx1 <= n;posx1++){
			for(int posy1 = 1;posy1 <= m;posy1++){
				for(int posx2 = posx1;posx2 <= n;posx2++){
					for(int posy2 = posy1;posy2 <= m;posy2++){
						bool jfd = judge(posx1,posy1,posx2,posy2);
						//if(!jfd)continue;
						ans += jfd;
					}
				}
			}
		}
		write(ans),putchar('\n');
		lastm = m;
	}
	return 0;
}
