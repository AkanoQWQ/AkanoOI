#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves <
using namespace std;
using ll = long long;
const int MAXN = 206;
const int MAXM = 1e6 + 1018 + 1108;
const int MOD = 1e9 + 7;
int t,n,m;
struct MyLimit{
	int l,r,x;
}lim[MAXM];
bool Cmp(MyLimit lim1,MyLimit lim2){
	if(lim1.r != lim2.r)return lim1.r < lim2.r;
	if(lim1.l != lim2.l)return lim1.l < lim2.l;
	return lim1.x < lim2.x;
}
int f[2][3][MAXN][MAXN],lower[MAXN],upper[MAXN];
inline void Calc(int pos,int up,int x){
	if(lim[x].x == 1){
		//两个有一个大于等于l都非法 
		for(int o1 = 0;o1 <= up;o1++){
			lower[o1] = min(lower[o1],lim[x].l);
		}
		for(int o1 = lim[x].l;o1 <= up;o1++){
			lower[o1] = min(lower[o1],0);
		}
	}else if(lim[x].x == 2){
		//两个都大于等于l,或者都不大于等于l非法
		//都大于l
		for(int o1 = lim[x].l;o1 <= up;o1++){
			lower[o1] = min(lower[o1],lim[x].l);
		}
		//都不大于等于l
		for(int o1 = 0;o1 <= lim[x].l-1;o1++){
			upper[o1] = max(upper[o1],lim[x].l-1);
		}
	}else if(lim[x].x == 3){
		//两个有一个小于l就非法
		for(int o1 = 0;o1 <= up;o1++){
			upper[o1] = max(upper[o1],lim[x].l-1);
		}
		 for(int o1 = 0;o1 <= lim[x].l-1;o1++){
			upper[o1] = max(upper[o1],up);
		}
	}
	return ;
}
inline void Execute(int pos,int up){
	for(int lst = 0;lst < 3;lst++){
		for(int i = 0;i <= up;i++){
			for(int j = up;j >= lower[i];j--){
				f[pos][lst][i][j] = 0;
			}
			for(int j = 0;j <= upper[i];j++){
				f[pos][lst][i][j] = 0;
			}
		}
	}
	return ;
}
inline int Solve(){
	int tail = 1,ret = 0;
	for(int i = 1;i <= m;i++){
		cin>>lim[i].l>>lim[i].r>>lim[i].x;
	}
	sort(lim+1,lim+m+1,Cmp);
	memset(f,0,sizeof(f));
	int now = 0,pre = 1;
	f[now][0][0][0] = 1;
	for(int i = 1;i <= n;i++){
		swap(now,pre);
		for(int lst = 0;lst < 3;lst++){
			for(int o1 = 0;o1 <= i+2;o1++){
				for(int o2 = 0;o2 <= i+2;o2++){
					f[now][lst][o1][o2] = 0;
				}	
			}
		}
		for(int add = 0;add < 3;add++){
			for(int lst = 0;lst < 3;lst++){
				for(int o1 = 0;o1 <= i;o1++){
					for(int o2 = 0;o2 <= i;o2++){
						if(add == lst){
							f[now][add][o1][o2] += f[pre][lst][o1][o2];
							if(f[now][add][o1][o2] >= MOD)f[now][add][o1][o2] -= MOD;
						}else if(add == 0 && lst == 1){
							//o1 dir 1,o2 dir 2   o1 dir 0,o2 dir 2
							f[now][add][i-1][o2] += f[pre][lst][o1][o2];
							if(f[now][add][i-1][o2] >= MOD)f[now][add][i-1][o2] -= MOD;
						}else if(add == 0 && lst == 2){
							//o1 dir 1,o2 dir 2   o1 dir 0,o2 dir 1
							f[now][add][o2][i-1] += f[pre][lst][o1][o2];
							if(f[now][add][o2][i-1] >= MOD)f[now][add][o2][i-1] -= MOD;
						}else if(add == 1 && lst == 0){
							//o1 dir 0,o2 dir 2   o1 dir 1,o2 dir 2
							f[now][add][i-1][o2] += f[pre][lst][o1][o2];
							if(f[now][add][i-1][o2] >= MOD)f[now][add][i-1][o2] -= MOD;
						}else if(add == 1 && lst == 2){
							//o1 dir 0,o2 dir 2   o1 dir 0,o2 dir 1
							f[now][add][o1][i-1] += f[pre][lst][o1][o2];
							if(f[now][add][o1][i-1] >= MOD)f[now][add][o1][i-1] -= MOD;
						}else if(add == 2 && lst == 0){
							//o1 dir 0,o2 dir 1   o1 dir 1,o2 dir 2
							f[now][add][i-1][o1] += f[pre][lst][o1][o2];
							if(f[now][add][i-1][o1] >= MOD)f[now][add][i-1][o1] -= MOD;
						}else if(add == 2 && lst == 1){
							//o1 dir 0,o2 dir 1   o1 dir 0,o2 dir 2
							f[now][add][o1][i-1] += f[pre][lst][o1][o2];
							if(f[now][add][o1][i-1] >= MOD)f[now][add][o1][i-1] -= MOD;
						}
					}
				}
			}
		}
		for(int j = 0;j <= i;j++){//清空 
			lower[j] = i+1,upper[j] = -1;
		}
		while(tail <= m && lim[tail].r == i){//计算 
			Calc(now,i,tail++);
		}
		Execute(now,i);//实际操作 
	}
	for(int lst = 0;lst < 3;lst++){
		for(int o1 = 0;o1 <= n;o1++){
			for(int o2 = 0;o2 <= n;o2++){
				ret += f[now][lst][o1][o2];
				if(ret >= MOD)ret -= MOD;
			}
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		cout<<Solve()<<endl;
	}
	return (Akano loves pure__Elysia);
}
