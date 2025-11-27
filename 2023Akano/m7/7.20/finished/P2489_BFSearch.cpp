//#include<bits/stdc++.h>
////#include<conio.h>
////remember to delete!
//using namespace std;
//using pii = pair<int,int>;
//const int MAXN = 44;
//const int MAXSTAT = 360;
//const int MAXH = 8;
//const int MAXK = 8;
//const int dx[4] = {0,1,0,-1};
//const int dy[4] = {1,0,-1,0};
//const double EPS = 1e-7;
//int n,m,k,h,maxs,poss[MAXSTAT];
//char mp[MAXN][MAXN];
//inline int SlowPow(int x,int y){
//	int ret = 1;
//	while(y--)ret *= x;
//	return ret;
//}
//inline string Bit(int x){
//	string ret;
//	while(x){
//		ret += (x & 1) + '0';
//		x >>= 1;
//	}
//	while(int(ret.length()) < k)ret += "0";
//	return ret;
//}
//inline string Srd(int x){
//	string ret;
//	while(x){
//		ret += (x % 3) + '0';
//		x /= 3;
//	}
//	while(int(ret.length()) < k)ret += "0";
//	return ret;
//}
//int trans[MAXSTAT];
//inline pii Trans(int stat,int OBJ){//safe / dangerous
//	pii ret = make_pair(0,0);
//	for(int i = 0;i < k;i++){
//		trans[i] = stat % 3;
//		stat /= 3;
//	}
//	for(int i = 0;i < maxs;i++){
//		bool OK = true;
//		for(int j = 0;j < k;j++){
//			if((trans[j] == 1 && (i & (1<<j))) || (trans[j] == 2 && (!(i & (1<<j))))){
//				OK = false;
//				break;
//			}
//		}
//		if(OK){
//			if(i & (1<<(OBJ-1))){
//				ret.second += poss[i];
//			}else{
//				ret.first += poss[i];
//			}
//		}
//	}
//	return ret;
//}
//inline pii Add(int stat,int OBJ){//safe / dangerous
//	pii ret = make_pair(0,0);
//	for(int i = 0;i < k;i++){
//		trans[i] = stat % 3;
//		stat /= 3;
//	}
//	trans[OBJ-1] = 1;//SAFE
//	for(int i = k-1;i >= 0;i--){
//		ret.first = ret.first * 3 + trans[i];
//	}
//	trans[OBJ-1] = 2;//SAFE
//	for(int i = k-1;i >= 0;i--){
//		ret.second = ret.second * 3 + trans[i];
//	}
//	return ret;
//}
//inline bool Judge(int x,int y){
//	return (x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] != '#');
//}
//int STx,STy;
//bool vis[MAXN][MAXN][MAXSTAT][MAXH];
//pii nxtposs[MAXSTAT][MAXK],nxtstat[MAXSTAT][MAXK];
//double dfs(int x,int y,int stat,int health){
//	if(health <= 0)return 0;
//	if(mp[x][y] == '@')return 1;
//	if(mp[x][y] >= 'A' && mp[x][y] <= 'Z'){
//		const int no = mp[x][y] - 'A' + 1;int copys = stat;
//		for(int i = 1;i < no;i++){
//			copys /= 3;
//		}
//		copys %= 3;
//		if(copys == 0){
//			if(nxtposs[stat][no] == make_pair(0,0))nxtposs[stat][no] = Trans(stat,no);
//			if(nxtstat[stat][no] == make_pair(0,0))nxtstat[stat][no] = Add(stat,no);
//			const pii nowposs = nxtposs[stat][no];
//			const pii newstat = nxtstat[stat][no];//Should health -= 1?OK?
//			const double ans1 = dfs(x,y,newstat.first,health) * nowposs.first / (nowposs.first+nowposs.second);
//			const double ans2 = dfs(x,y,newstat.second,health) * nowposs.second / (nowposs.first+nowposs.second);
//			return ans1 + ans2;
//		}else if(copys == 1){
//			//do nothing and continue
//		}else{
//			health--;
//		}
//	} 
//	vis[x][y][stat][health] = true;
//	double ret = 0;
//	for(int k = 0;k < 4;k++){
//		const int OX = x + dx[k],OY = y + dy[k];
//		if(Judge(OX,OY) && !vis[OX][OY][stat][health])ret = max(ret,dfs(OX,OY,stat,health));
//	}
//	vis[x][y][stat][health] = false;
//	cout<<"vis "<<x<<","<<y<<" ans "<<ret<<endl;
//	return ret;
//}
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
////	freopen("P2489.in","r",stdin);
//	cin>>n>>m>>k>>h;
//	maxs = 1<<k;
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			cin>>mp[i][j];
//			if(mp[i][j] == '$'){
//				STx = i,STy = j;
//			}
//		}
//	}
//	for(int i = 0;i < maxs;i++){
//		cin>>poss[i];
//	}
//	cout<<fixed<<setprecision(3)<<dfs(STx,STy,0,h)<<endl;
//	return 0;
//}
