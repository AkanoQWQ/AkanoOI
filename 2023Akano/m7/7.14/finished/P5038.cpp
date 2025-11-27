#include<bits/stdc++.h>
#define int long long 
using namespace std;
using ll = long long;
const int MAXR = 106;
const int MAXN = 10006 + 1018 + 1108;//remember to EDIT
const int MAXM = 400006 + 1018 + 1108;//EDIT and *2
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
struct Edge{
	int nxt,to;
	ll cap;
}e[MAXM];
int head[MAXN],cnt = 1;
inline void AddEdge(int from,int to,ll val){
	e[++cnt].to = to;
	e[cnt].cap = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
inline void CreateEdge(int from,int to,ll val){
	AddEdge(from,to,val);
	AddEdge(to,from,0);
	return ;
} 
int DFS_ED;//share 
int dep[MAXN],cur[MAXN];
bool BFS(int n,int ST,int ED){
	for(int i = 0;i <= n;i++){
		dep[i] = 0;
	}
	queue<int> q;
	dep[ST] = 1;
	q.push(ST);
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		cur[u] = head[u];
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dep[v] != 0 || e[i].cap <= 0)continue;
			dep[v] = dep[u] + 1;
			q.push(v);
		}
	}
//	cout<<dep[ED]<<" ?! "<<endl;
	return (dep[ED] > 0);
}
ll DFS(int u,ll val){
	if(u == DFS_ED || val == 0)return val;
	ll ret = 0;
	for(int i = cur[u];i;i = e[i].nxt){
		const int v = e[i].to;
		cur[u] = i;
		if(e[i].cap <= 0 || dep[v] != dep[u] + 1)continue;
		const ll realPush = DFS(v,min(e[i].cap,val));
		ret += realPush;
		val -= realPush;
		e[i].cap -= realPush;
		e[i^1].cap += realPush;
		if(realPush == 0)dep[v] = -1;
		if(val == 0)break;
	}
	return ret;
}
inline ll Dinic(int n,int ST,int ED,ll TOT){
	ll ret = 0;
	DFS_ED = ED;
	while(BFS(n,ST,ED)){
		ll ddd = DFS(ST,INF);
//		cout<<"ADD "<<ddd<<endl;
		ret += ddd;
	}
	return ret;
}
ll T,n,m,vals[MAXR][MAXR],no[MAXR][MAXR],VST,VED;
inline void Clear(){
//	memset(head,0,sizeof(head));
	for(int i = 0;i <= VED;i++){
		head[i] = 0;
	}
	cnt = 1;
	return ;
}
inline bool Judge(ll x,ll y){
	return (x >= 1 && x <= n) && (y >= 1 && y <= m);
}
inline bool Check(ll x){
//	cout<<"TRY "<<x<<endl;
	Clear();
	ll OBJ = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if((i + j) % 2 == 0){//blk
				OBJ += x - vals[i][j];
				CreateEdge(VST,no[i][j],x - vals[i][j]);
				for(int k = 0;k < 4;k++){
					const int OX = i + dx[k],OY = j + dy[k];
					if(!Judge(OX,OY))continue;
					CreateEdge(no[i][j],no[OX][OY],INF);
				}
			}else{
				CreateEdge(no[i][j],VED,x - vals[i][j]);
			}
		}
	}
//	OBJ /= 2;
	const ll act = Dinic(VED,VST,VED,n*m);
//	cout<<act<<" COMPARE "<<OBJ<<endl;
	return (act >= OBJ);
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P5038.in","r",stdin);
	freopen("P5038.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		ll mx = 0,nnt = 0,black = 0,white = 0;
		ll bcnt = 0,wcnt = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin>>vals[i][j];
				no[i][j] = ++nnt;
				mx = max(mx,vals[i][j]);
				if((i + j) % 2 == 0){
					++black;
					bcnt += vals[i][j];
				}else{
					++white;
					wcnt += vals[i][j];
				}
			}
		}
		VST = ++nnt,VED = ++nnt;
		if(black == white){
			if(bcnt != wcnt){
				cout<<-1<<endl;
				continue;
			}
			ll l = mx,r = INF;
			while(l < r){
				const ll mid = (l + r) >> 1;
				if(Check(mid)){
					r = mid;
				}else{
					l = mid + 1;
				}
			}
			if(r == INF){
				cout<<-1<<endl;
			}else{
				cout<<(r * (n*m) - (bcnt + wcnt)) / 2<<endl;
			}
		}else{
			//black > white
			if(bcnt <= wcnt || ((bcnt-wcnt) % (black-white) != 0)){
				cout<<-1<<endl;
			}else if(Check((bcnt-wcnt) / (black-white))){
				cout<<(((bcnt-wcnt) / (black-white)) * (n*m) - (bcnt + wcnt)) / 2<<endl;
			}else{
				cout<<-1<<endl;
			}
		}
	}
	return 0;
}
