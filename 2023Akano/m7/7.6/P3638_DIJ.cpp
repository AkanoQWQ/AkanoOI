#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using pii = pair<int,int>;
const int MAXN = 14;
const int MAXP = 506;
const int MAXK = 5;
const int INF = 0x7fffffff / 2 - 1;
const int dx[4] = {-1,0,1,0};//up right down left
const int dy[4] = {0,1,0,-1};
struct Point{
	int x,y;
	Point(){x = y = 0;}
	Point(int _x,int _y){x = _x,y = _y;}
}startPos[MAXN];
ostream& operator<<(ostream& cout,Point _point){
	cout<<"("<<_point.x<<","<<_point.y<<")";
	return cout;
}
bool operator==(Point pa,Point pb){
	return (pa.x == pb.x) && (pa.y == pb.y);
}
bool operator!=(Point pa,Point pb){
	return !(pa == pb);
}
//vars 
Point edgeTo[MAXP][MAXP][MAXK];
bool inqSearch[MAXP][MAXP][MAXK];
int dis[MAXN][MAXN][MAXP][MAXP];
char mp[MAXP][MAXP];
int n,w,h;
inline void ReadMap(){
	cin>>n>>w>>h;
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			cin>>mp[i][j];
			if(isdigit(mp[i][j])){
				startPos[mp[i][j]-'0'] = Point(i,j);
				mp[i][j] = '.';
			}
		}
	}
	return ;
}
inline bool Judge(int x,int y){
	return (x >= 1 && x <= h && y >= 1 && y <= w) && (mp[x][y] != 'x');
}
Point Search(int x,int y,int dir){
	if(inqSearch[x][y][dir])return Point(0,0);
	if(edgeTo[x][y][dir] != Point())return edgeTo[x][y][dir];
	
	inqSearch[x][y][dir] = true;
	int realDir = dir;
	if(mp[x][y] == 'A')realDir = (realDir - 1 + 4) % 4;
	if(mp[x][y] == 'C')realDir = (realDir + 1) % 4;
	if(!Judge(x+dx[realDir],y+dy[realDir])){
		edgeTo[x][y][dir] = Point(x,y);
	}else{
		edgeTo[x][y][dir] = Search(x+dx[realDir],y+dy[realDir],realDir);
	}
	inqSearch[x][y][dir] = false;
	return edgeTo[x][y][dir];
}
inline void SearchForEdge(){
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			if(mp[i][j] != 'x'){
				for(int k = 0;k < 4;k++){
					Search(i,j,k);
					cout<<Point(i,j)<<" -> "<<edgeTo[i][j][k]<<endl;
				}
			}
		}
	}
	return ;
}
bool vis[MAXP][MAXP];
bool operator<(pair<int,Point> _a,pair<int,Point> _b){
	return _a.first > _b.first;
}
inline void DIJforStatus(int l,int r){
	priority_queue<pair<int,Point> > q;
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			vis[i][j] = false;
			if(dis[l][r][i][j] < INF){
				q.push(make_pair(dis[l][r][i][j],Point(i,j)));
			}
		}
	}
	while(!q.empty()){
		const Point now = q.top().second;
		q.pop();
		if(vis[now.x][now.y])continue;
		vis[now.x][now.y] = true;
		const int nowstep = dis[l][r][now.x][now.y];
		//Move
		for(int k = 0;k < 4;k++){
			const Point obj = edgeTo[now.x][now.y][k];
			if(obj == Point(0,0))continue;
			if(nowstep + 1 < dis[l][r][obj.x][obj.y]){
				dis[l][r][obj.x][obj.y] = nowstep + 1;
				q.push(make_pair(nowstep + 1,obj));
			}
		}
	}
	return ;
}
inline void DPSolve(){
	for(int _1 = 1;_1 <= n;_1++){
		for(int _2 = 1;_2 <= n;_2++){
			for(int _3 = 1;_3 <= h;_3++){
				for(int _4 = 1;_4 <= w;_4++){
					dis[_1][_2][_3][_4] = INF;//-1 ? INF ? 
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		dis[i][i][startPos[i].x][startPos[i].y] = 0;
		DIJforStatus(i,i);
	}	
	for(int len = 2;len <= n;len++){
		for(int l = 1;l + len - 1 <= n;l++){
			const int r = l + len - 1;
			for(int mid = l;mid < r;mid++){
				for(int _x = 1;_x <= h;_x++){
					for(int _y = 1;_y <= w;_y++){
						dis[l][r][_x][_y] = min(dis[l][r][_x][_y],dis[l][mid][_x][_y] + dis[mid+1][r][_x][_y]);
					}
				}
			}
			DIJforStatus(l,r);
		}
	}
	return ;
}
inline void Output(){
	int ans = INF;
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			ans = min(ans,dis[1][n][i][j]);
		}
	}
	if(ans == INF)ans = -1;
	cout<<ans<<flush;
	return ;
}
int main(){
	freopen("P3638.in","r",stdin);
	freopen("P3638.ans","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadMap();
	SearchForEdge();
	DPSolve();
	Output();
	return 0;
}
