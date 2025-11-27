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
inline bool Border(Point pt){
	return (pt.x == 0 || pt.x == h+1 || pt.y == 0 || pt.y == w+1);
}
inline bool Judge(Point pt){
	return (pt.x >= 1 && pt.x <= h && pt.y >= 1 && pt.y <= w) && (mp[pt.x][pt.y] != 'x');
}
Point Search(Point pt,int dir){
	if(edgeTo[pt.x][pt.y][dir] != Point())return edgeTo[pt.x][pt.y][dir];
	if(inqSearch[pt.x][pt.y][dir])return Point(0,0);//?OK?   -1,-1? 0,0? ???
	if(Border(pt) || mp[pt.x][pt.y] == 'x')return Point(pt.x-dx[dir],pt.y-dy[dir]);
	inqSearch[pt.x][pt.y][dir] = true;
	int realDir = dir;
	if(mp[pt.x][pt.y] == 'A')realDir = (realDir - 1 + 4) % 4;
	if(mp[pt.x][pt.y] == 'C')realDir = (realDir + 1) % 4;
	edgeTo[pt.x][pt.y][dir] = Search(Point(pt.x+dx[realDir],pt.y+dy[realDir]),realDir);
	inqSearch[pt.x][pt.y][dir] = false;
	return edgeTo[pt.x][pt.y][dir];
}
inline void SearchForEdge(){
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			if(mp[i][j] != 'x'){
				for(int k = 0;k < 4;k++){
					Search(Point(i,j),k);
					cout<<Point(i,j)<<" -> "<<edgeTo[i][j][k]<<" in "<<k<<endl;
				}
			}
		}
	}
	return ;
}
bool inq[MAXP][MAXP];
inline void SPFAforStatus(int l,int r){
	queue<Point> q;
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			if(dis[l][r][i][j] < INF){
				inq[i][j] = true;
				q.push(Point(i,j));
			}
		}
	}
	while(!q.empty()){
		const Point now = q.front();
		inq[now.x][now.y] = false;
		q.pop();
		const int nowstep = dis[l][r][now.x][now.y];
		//Move
		for(int k = 0;k < 4;k++){
			const Point obj = edgeTo[now.x][now.y][k];
			if(obj == Point(0,0))continue;
			if(nowstep + 1 < dis[l][r][obj.x][obj.y]){
				dis[l][r][obj.x][obj.y] = nowstep + 1;
				if(!inq[obj.x][obj.y])q.push(obj);
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
		SPFAforStatus(i,i);
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
			SPFAforStatus(l,r);
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
	//freopen("P3638.in","r",stdin);
	//freopen("P3638.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadMap();
	SearchForEdge();
	DPSolve();
	Output();
	return 0;
}
