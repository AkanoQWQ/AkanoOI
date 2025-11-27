#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 100006;
const int _1e9 = 1000000000;
int n,m;
vector<int> b[MAXN];
int tt,x[MAXN],y[MAXN],sumx,sumy,c,d,_11;
int calc(int inx){
	int ret = 0;
	for(int i = 1;i <= m;++i){
		ret += abs(x[i]-inx);
	}
	inx = _11 - inx;
	for(int i = 1;i <= n;++i){
		ret += abs(y[i]-inx);
	}
	return ret;
}
signed main(){
	freopen("eatshxt.in","r",stdin);
	freopen("eatshxt.out","w",stdout);
	scanf("%d",&tt);
	while(tt--){
		bool FD = 1;
		sumx = 0,sumy = 0;
		scanf("%lld%lld",&n,&m);
		for(int i = 1;i <= n;i++){
			b[i].clear();
			b[i].push_back(0);
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				int qwer;
				scanf("%lld",&qwer);
				b[i].push_back(qwer);
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				int qwer;
				scanf("%lld",&qwer);
				b[i][j] -= qwer;
			}
		}
		_11 = -b[1][1];
		for(int i = 1;i <= m;i++){
			x[i] = -b[1][i];
		}
		for(int i = 1;i <= n;i++){
			int obj = b[i][1] + x[1];
			for(int j = 1;j <= m;j++){
				if(b[i][j] + x[j] != obj){
					FD = 0;
					break;
				}
			}
			if(!FD)break;
		}
		for(int i = 1;i <= n;i++){
			int c = -b[i][1];
			b[i][1] += c;
			for(int j = 2;j <= m;j++){
				b[i][j] += c;
			}
			y[i] = c;
		}
		if(!FD){
			printf("-1\n");
			continue;
		}
		if(n < m){
			swap(x,y);
			swap(n,m);
		}
		int l = -_1e9,r = _1e9,ret = 0;
		while(l < r){
			int midl = l + (r-l)/3,midr = r - (r-l)/3;
			int fl = calc(midl),fr = calc(midr);
			if(fl > fr){
				l = midl+1;
				ret = fr;
			}else{
				r = midr-1;
				ret = fl;
			}
		}
		printf("%lld\n",ret);
	}
	return 0;
}
