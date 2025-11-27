//#include<bits/stdc++.h>
//#define Akano 1
//#define pure__Elysia 0
//#define loves <
//using namespace std;
//using ll = long long;
//const int MAXN = 206;
//const int MAXM = 1e6 + 1018 + 1108;
//const int MOD = 1e9 + 7;
//int t,n,m;
//struct MyLimit{
//	int l,r,x;
//}lim[MAXM];
//bool Cmp(MyLimit lim1,MyLimit lim2){
//	if(lim1.r != lim2.r)return lim1.r < lim2.r;
//	if(lim1.l != lim2.l)return lim1.l < lim2.l;
//	return lim1.x < lim2.x;
//}
//ll f[2][MAXN][MAXN][MAXN];
//inline void Calc(int pos,int up,int x){
//	for(int o1 = 0;o1 <= up;o1++){
//		for(int o2 = 0;o2 <= up;o2++){
//			for(int o3 = 0;o3 <= up;o3++){
//				int cnt = 0;
//				if(o1  >= lim[x].l)cnt++;
//				if(o2  >= lim[x].l)cnt++;
//				if(o3  >= lim[x].l)cnt++;
//				if(cnt != lim[x].x){
//					f[pos][o1][o2][o3] = 0;
//				}
//			}
//		}
//	}
//	return ;
//}
//inline ll Solve(){
//	int tail = 1;
//	ll ret = 0;
//	for(int i = 1;i <= m;i++){
//		cin>>lim[i].l>>lim[i].r>>lim[i].x;
//	}
//	sort(lim+1,lim+m+1,Cmp);
//	memset(f,0,sizeof(f));
//	int now = 0,pre = 1;
//	f[now][0][0][0] = 1;
//	for(int i = 1;i <= n;i++){
//		swap(now,pre);
//		memset(f[now],0,sizeof(f[now]));
//		for(int o1 = 0;o1 <= i;o1++){
//			for(int o2 = 0;o2 <= i;o2++){
//				for(int o3 = 0;o3 <= i;o3++){
//					f[now][i][o2][o3] += f[pre][o1][o2][o3];
//					f[now][i][o2][o3] %= MOD;
//					f[now][o1][i][o3] += f[pre][o1][o2][o3];
//					f[now][o1][i][o3] %= MOD;
//					f[now][o1][o2][i] += f[pre][o1][o2][o3];
//					f[now][o1][o2][i] %= MOD;
//				}
//			}
//		}
//		while(tail <= m && lim[tail].r == i){
//			Calc(now,i,tail++);
//		}
//	}
//	for(int o1 = 0;o1 <= n;o1++){
//		for(int o2 = 0;o2 <= n;o2++){
//			for(int o3 = 0;o3 <= n;o3++){
//				ret += f[now][o1][o2][o3];
//				ret %= MOD;
//			}
//		}
//	}
//	return ret;
//}
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("string/string2.in","r",stdin);
//	cin>>t;
//	while(t--){
//		cin>>n>>m;
//		cout<<Solve()<<endl;
//	}
//	return (Akano loves pure__Elysia);
//}

