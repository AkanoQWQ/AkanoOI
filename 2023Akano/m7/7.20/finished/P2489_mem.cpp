#include<bits/stdc++.h>
//#include<conio.h>
//remember to delete!
using namespace std;
using ld = long double;
using pii = pair<int,int>;
const int MAXN = 44;
const int MAXSTAT = 360;
const int MAXH = 8;
const int MAXK = 8;
const int MAXDIR = 7;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
const ld EPS = 1e-7;
int n,m,k,h,maxs,poss[MAXSTAT];
ld dp[MAXN][MAXN][MAXSTAT][MAXH][MAXDIR];
char mp[MAXN][MAXN];
inline int SlowPow(int x,int y){
	int ret = 1;
	while(y--)ret *= x;
	return ret;
}
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
int STx,STy;
bool vis[MAXN][MAXN][MAXSTAT][MAXH][MAXDIR];
pii nxtposs[MAXSTAT][MAXK],nxtstat[MAXSTAT][MAXK];
ld dfs(int x,int y,int stat,int health,int dir){
	if(health <= 0)return 0;
	if(mp[x][y] == '@')return 1;
	if(mp[x][y] >= 'A' && mp[x][y] <= 'Z'){
		const int no = mp[x][y] - 'A' + 1;
		int copys = stat;
		for(int i = 1;i < no;i++){
			copys /= 3;
		}
		copys %= 3;
		if(copys == 0){
			if(nxtposs[stat][no] == make_pair(0,0))nxtposs[stat][no] = Trans(stat,no);
			if(nxtstat[stat][no] == make_pair(0,0))nxtstat[stat][no] = Add(stat,no);
			const pii nowposs = nxtposs[stat][no];//5 ? dir
			const pii newstat = nxtstat[stat][no];//Should health -= 1?OK?
			const ld ans1 = dfs(x,y,newstat.first,health,dir) * nowposs.first / (nowposs.first+nowposs.second);
			const ld ans2 = dfs(x,y,newstat.second,health,dir) * nowposs.second / (nowposs.first+nowposs.second);
			dp[x][y][stat][health][dir] = ans1 + ans2;
			return dp[x][y][stat][health][dir];
		}else if(copys == 1){
			//do nothing and continue
		}else{
			health--;
		}
	}
	if(dp[x][y][stat][health][dir] != 0)return dp[x][y][stat][health][dir];//health-- before?
	vis[x][y][stat][health][dir] = true;
	ld ret = 0;
	for(int k = 0;k < 4;k++){
		const int OX = x + dx[k],OY = y + dy[k];
		if(Judge(OX,OY) && !vis[OX][OY][stat][health][k])ret = max(ret,dfs(OX,OY,stat,health,k));
	}
//	vis[x][y][stat][health][dir] = false;
	dp[x][y][stat][health][dir] = ret;
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("P2489.in","r",stdin);
	cin>>n>>m>>k>>h;
	maxs = 1<<k;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>mp[i][j];
			if(mp[i][j] == '$'){
				STx = i,STy = j;
			}
		}
	}
	for(int i = 0;i < maxs;i++){
		cin>>poss[i]; 
	}
	ld mans = 0;
	for(int i = 0;i < 4;i++){
		mans = max(mans,dfs(STx,STy,0,h,0));
	}
	cout<<fixed<<setprecision(3)<<mans<<endl;
	return 0;
}
