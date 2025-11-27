#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 100006;
ll n,m,k,a[MAXN];
double pos[MAXN],op[MAXN];
inline ll iread(){
	ll ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
namespace subtask1{
	void solve(){
		while(k--){
			for(int i = 1;i <= m;i++){
				pos[a[i]] = pos[a[i]-1] + pos[a[i]+1] - pos[a[i]];
			}
		}
		return ;
	}
}
namespace subtask2{
	int IMPORTANT_VALUE = 1000000;
	bool used[MAXN];
	int tail,check[MAXN];
	void solve(){
		for(int i = 1;i <= m;i++){
			if(used[a[i]] == 0){
				used[a[i]] = 1;
				check[++tail] = a[i];
			}
		}
		int turns;
		for(turns = 1;turns <= k;turns++){
			for(int i = 1;i <= m;i++){
				pos[a[i]] = pos[a[i]-1] + pos[a[i]+1] - pos[a[i]];
			}
			bool fd = 1;
			for(int i = 1;i <= tail;i++){
				if(pos[check[i]] != op[check[i]]){
					fd = 0;
					break;
				}
			}
			IMPORTANT_VALUE -= fd;
			if(IMPORTANT_VALUE <= 0)break;
		}
		k %= turns;
		return ;
	}
}
int main(){
	freopen("rabbit.in","r",stdin);
	freopen("rabbit_old2.out","w",stdout);
	n = iread();
	for(int i = 1;i <= n;i++){
		ll inp = iread();
		pos[i] = inp;
		op[i] = pos[i];
	}
	m = iread(),k = iread();
	for(int i = 1;i <= m;i++){
		a[i] = iread();
	}
	if(k > 1e8 || (m * k >= 2e6 && k >= 100)){
		subtask2::solve();//一个对于n << m 且 k很大 起效的优化 
	}
	subtask1::solve();
	for(int i = 1;i <= n;i++){
		printf("%.1lf\n",pos[i]);
	}
	return 0;
}
//pos[a[i]] = 0.5 * (2 * pos[a[i]-1] - pos[a[i]]) + 0.5*(2 * pos[a[i]+1] - pos[a[i]]);

