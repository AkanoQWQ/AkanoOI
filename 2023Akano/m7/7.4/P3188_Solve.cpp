#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void Write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
const int MAXW = 34;
const int MAXV = 1006;
const int MAXN = 106;
int v = 10;
int _2[MAXW],n,w,f[MAXW][MAXV],dp[MAXN][MAXV],g[MAXW][MAXV];
struct Item{
	int cost,val;
	Item(){}
	Item(int _cost,int _val){cost = _cost,val = _val;}
};
vector<Item> items[MAXW];
inline void Clear(){
	for(int i = 0;i <= 30;i++)items[i].clear();
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	return ;
}
int main(){
	freopen("P3188.in","r",stdin);
	freopen("P3188.out","w",stdout);
	_2[0] = 1;
	for(int i = 1;i <= 30;i++)_2[i] = _2[i-1] * 2;
	int ss = 0;
	for(ss = 0;ss <= 30;ss++);
	while(1){
		n = Read(),w = Read();
		v = 10 * n;
		if(n == -1 && w == -1)break;
		Clear();
		for(int i = 1;i <= n;i++){
			int _cost = Read(),_val = Read(),upperw = 0;
			while(upperw < 30){
				if(_cost % _2[upperw+1] == 0){
					upperw++;
				}else{
					break;
				}
			}
			_cost /= _2[upperw];
			items[upperw].push_back(Item(_cost,_val));
		}
		for(int i = 0;i <= 30;i++){
			if(items[i].size() == 0)continue;
			memset(dp,0,sizeof(dp));
//			cout<<i<<"th _2 have "<<items[i].size()<<" item which:"<<endl;
			for(int j = 1;j <= items[i].size();j++){
				const int cost = items[i][j-1].cost,val = items[i][j-1].val;
//				cout<<cost<<" : "<<val<<endl;
				for(int k = 0;k <= v;k++){
					dp[j][k] = dp[j-1][k];
					if(k - cost >= 0)dp[j][k] = max(dp[j][k],dp[j-1][k-cost]+val);
				}
			}
			for(int j = 0;j <= v;j++){
				f[i][j] = dp[items[i].size()][j];
//				if(j == v)cout<<j<<" vals "<<f[i][j]<<endl<<endl;
			}
		}
		for(int i = 0;i <= v;i++){
			g[0][i] = f[0][i];
		}
		for(int i = 1;i <= 30;i++){
			for(int j = 0;j <= v;j++){
				for(int k = 0;k <= j;k++){
					const int left = min(v,2 * k + (1 & (w>>(i-1))));
					g[i][j] = max(g[i][j],f[i][j-k] + g[i-1][left]);
				}
			}
		}
		int wwei = 0;
		while(wwei < 30){
			if(w > _2[wwei+1]){
				++wwei;
			}else{
				break;
			}
		}
		cout<<g[wwei][1]<<endl;
	}
	return 0;
}


