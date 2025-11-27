#include<bits/stdc++.h>
using namespace std;
using ld = long double;
using pii = pair<int,int>;
const int MAXN = 34;
const int MAXNO = MAXN * MAXN; 
const int MAXM = MAXNO*MAXNO*4;
const int MAXSTAT = 255;
const int MAXH = 7;
const int MAXK = 7;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
const ld EPS = 1e-7;
int n,m,k,h,maxs,poss[MAXSTAT];
inline string Bit(int x){
	string ret;
	while(x){
		ret += (x & 1) + '0';
		x >>= 1;
	}
	while(int(ret.length()) < k)ret += "0";
	return ret;
}
inline string Srd(int x){
	string ret;
	while(x){
		ret += (x % 3) + '0';
		x /= 3;
	}
	while(int(ret.length()) < k)ret += "0";
	return ret;
}
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXSTAT][MAXNO],cnt;
inline void AddEdge(int no,int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[no][from];
	head[no][from] = cnt;
	return ;
}
ld dp[MAXNO][MAXSTAT][MAXH];
char mp[MAXN][MAXN],ch[MAXNO];
inline int SlowPow(int x,int y){
	int ret = 1;
	while(y--)ret *= x;
	return ret;
}
int trans[MAXSTAT];
inline pii Trans(int stat,int OBJ){//safe / dangerous
	pii ret = make_pair(0,0);
	for(int i = 0;i < k;i++){
		trans[i] = stat % 3;
		stat /= 3;
	}
	for(int i = 0;i < maxs;i++){
		bool OK = true;
		for(int j = 0;j < k;j++){
			if((trans[j] == 1 && (i & (1<<j))) || (trans[j] == 2 && (!(i & (1<<j))))){
				OK = false;
				break;
			}
		}
		if(OK){
			if(i & (1<<(OBJ-1))){
				ret.second += poss[i];
			}else{
				ret.first += poss[i];
			}
		}
	}
	return ret;
}
inline pii Add(int stat,int OBJ){//safe / dangerous
	pii ret = make_pair(0,0);
	for(int i = 0;i < k;i++){
		trans[i] = stat % 3;
		stat /= 3;
	}
	trans[OBJ-1] = 1;//SAFE
	for(int i = k-1;i >= 0;i--){
		ret.first = ret.first * 3 + trans[i];
	}
	trans[OBJ-1] = 2;//SAFE
	for(int i = k-1;i >= 0;i--){
		ret.second = ret.second * 3 + trans[i];
	}
	return ret;
}
inline bool Judge(int x,int y){
	return (x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] != '#');
}
int STx,STy,org[MAXSTAT][MAXK];
pii nxtposs[MAXSTAT][MAXK],nxtstat[MAXSTAT][MAXK];
ld dfs(int u,int stat,int health){
	if(health <= 0)return 0;
	if(ch[u] == '@')return 1;
	if(dp[u][stat][health] != 0)return dp[u][stat][health];
	ld ret = 0;
	for(int i = head[stat][u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(ch[v] < 'A' || ch[v] > 'Z'){
			ret = max(ret,dfs(v,stat,health));
			continue;
		}
		const int no = ch[v] - 'A' + 1;
		if(org[stat][no] == 0){
			if(nxtposs[stat][no] == make_pair(0,0))nxtposs[stat][no] = Trans(stat,no);
			if(nxtstat[stat][no] == make_pair(0,0))nxtstat[stat][no] = Add(stat,no);
			const pii nowposs = nxtposs[stat][no];
			const pii newstat = nxtstat[stat][no];
			const ld ans1 = dfs(v,newstat.first,health) * nowposs.first / (nowposs.first+nowposs.second);
			const ld ans2 = dfs(v,newstat.second,health-1) * nowposs.second / (nowposs.first+nowposs.second);
			ret = max(ret,ans1 + ans2);
		}else if(org[stat][no] == 2){
			const ld rrr = dfs(v,stat,health-1);
			ret = max(ret,rrr);
		}
	}
	dp[u][stat][health] = ret;
	return ret;
}
int no[MAXN][MAXN],nnt;
bool vis[MAXN][MAXN];
inline void GetEdge(int stat,int inx,int iny){
	queue<pii> q;
	q.push(make_pair(inx,iny));
	memset(vis,0,sizeof(vis));
	vis[inx][iny] = true;
	while(!q.empty()){
		const pii u = q.front();
		q.pop();
		if(mp[u.first][u.second] == '@'){
			AddEdge(stat,no[inx][iny],no[u.first][u.second]);
		}
		if(mp[u.first][u.second] >= 'A' && mp[u.first][u.second] <= 'Z' && !(u.first == inx && u.second == iny)){
			const int num = mp[u.first][u.second] - 'A' + 1;
			if(org[stat][num] == 0 || org[stat][num] == 2){
				AddEdge(stat,no[inx][iny],no[u.first][u.second]);
				continue;
			} 
		}
		for(int k = 0;k < 4;k++){
			const int OX = u.first + dx[k],OY = u.second + dy[k];
			if(Judge(OX,OY) && !vis[OX][OY]){
				q.push(make_pair(OX,OY));
				vis[OX][OY] = true;
			}
		}
	}
	return ;
}
inline void Pre(){
	const int ups = SlowPow(3,k);
	for(int i = 0;i < ups;i++){
		int copy = i;
		for(int j = 1;j <= k;j++){
			org[i][j] = copy % 3;
			copy /= 3;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k>>h;
	maxs = 1<<k;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>mp[i][j];
			if(mp[i][j] == '$'){
				STx = i,STy = j;
			}
			if(mp[i][j] != '.' && mp[i][j] != '#'){
				no[i][j] = ++nnt;
				ch[nnt] = mp[i][j];
			}
		}
	}
	Pre();
	for(int i = 0;i < maxs;i++){
		cin>>poss[i];
	}
	const int ups = SlowPow(3,k);
	for(int stat = 0;stat < ups;stat++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(mp[i][j] != '.' && mp[i][j] != '#'){
					GetEdge(stat,i,j);
				}
			}
		}
	}
	cout<<fixed<<setprecision(3)<<dfs(no[STx][STy],0,h)<<endl;
	return 0;
}
