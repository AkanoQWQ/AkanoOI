#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10 + 18;
const int MAXTS = (1<<10) + 10 + 18;
const int MAXBS = (1<<8) + 11 + 8;
int T,n,t[MAXN],b[MAXN],f[2][MAXBS][MAXTS];
vector<int> cnt[2][MAXBS];
inline int OneCnt(int x){
	int ret = 0;
	while(x){
		ret += (x&1);
		x >>= 1;
	}
	return ret;
}
bool cmp4OneNum(int _a,int _b){
	return OneCnt(_a) < OneCnt(_b);
}
vector<int> stats;
inline void Pre(){
	stats.reserve(1<<8);
	for(int i = 0;i < (1<<8);i++){
		stats.push_back(i);
	}
	sort(stats.begin(),stats.end(),cmp4OneNum);
	return ;
}
int otp[66];
inline void Print(int x){
	int cnt = 0;
	while(x){
		otp[++cnt] = (x & 1);
		x >>= 1;
	}
	for(int i = cnt;i >= 1;i--)cout<<otp[i];
	return ;
}
inline string Bit(int x){
	string ret;
	while(x){
		ret += (x & 1)+'0';
		x >>= 1;
	}
	return ret;
}
inline bool Exist(int stat,int bw){
	for(int i = 1;i <= bw;i++){
		stat >>= 1;
	}
	return stat;
}
inline void Update(int& val1,int val2){
	val1 = min(val1,val2);
	return ;
}
inline int Solve(){
	int now = 0,tail = 1;
	memset(f,0x3f,sizeof(f));
	const int INF = f[0][0][0];
	for(int i = 0;i <= b[1];i++){
		f[tail][1<<i][t[1+i]] = 0;//swap
		cnt[tail][1<<i].push_back(t[1+i]);
	}
	for(int i = 1;i <= n;i++){
		swap(now,tail);
		memset(f[tail],0x3f,sizeof(f[tail]));
		for(auto stat : stats){
			cnt[tail][stat].clear();
			if(Exist(stat,b[i]+1))continue;
			for(int nxt = 0;nxt <= b[i];nxt++){
				if((1<<nxt) & stat)continue;
				bool OK = true;
				for(int nnxt = nxt + b[i+nxt] + 1;nnxt <= b[i];nnxt++){
					if((1<<nnxt) & stat){
						OK = false;
						continue;
					}
				}
				if(!OK)continue;
				for(auto nowt : cnt[now][stat]){
					if(f[now][(1<<nxt) + stat][t[i+nxt]] == INF){
						cnt[now][(1<<nxt) + stat].push_back(t[i+nxt]);
					}
					Update(f[now][(1<<nxt) + stat][t[i+nxt]],f[now][stat][nowt] + (nowt | t[i+nxt]) - (nowt & t[i+nxt]));					
				}
			}
		}
		for(auto stat : stats){
			if(stat & 1){
				for(auto nowt : cnt[now][stat]){
					if(f[tail][stat>>1][nowt] == INF){
						cnt[tail][stat>>1].push_back(nowt);
					}
					Update(f[tail][stat>>1][nowt],f[now][stat][nowt]);		
				}
			}
		}
	}
	int ret = INT_MAX;
	for(int nowt = 0;nowt <= 1000;nowt++){
		Update(ret,f[tail][0][nowt]);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("P2157.in","r",stdin);
	cin>>T;
	Pre();
	while(T--){
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>t[i]>>b[i];
		}
		cout<<Solve()<<endl;
	}
	return 0;
}

