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
int MX_DDL_TEST = 300;
Point Search(int x,int y,int dir,int _TEST_DDL){
	if(++_TEST_DDL > MX_DDL_TEST)return Point(0,0);
	if(edgeTo[x][y][dir] != Point())return edgeTo[x][y][dir];
	if(inqSearch[x][y][dir])return Point(0,0);
	inqSearch[x][y][dir] = true;
	int realDir = dir;
	if(mp[x][y] == 'A')realDir = (realDir - 1 + 4) % 4;
	if(mp[x][y] == 'C')realDir = (realDir + 1) % 4;
	if(!Judge(x+dx[realDir],y+dy[realDir])){
		edgeTo[x][y][dir] = Point(x,y);
	}else{
		edgeTo[x][y][dir] = Search(x+dx[realDir],y+dy[realDir],realDir,_TEST_DDL);
	}
	inqSearch[x][y][dir] = false;
	return edgeTo[x][y][dir];
}
inline void SearchForEdge(){
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			if(mp[i][j] != 'x'){
				for(int k = 0;k < 4;k++){
					Search(i,j,k,0);
				}
			}
		}
	}
	return ;
}
class Kueue{
	private:
		int c1[MAXP];
		int head,tail;
	public:
		inline void Init(){
			head1 = head2 = 1,tail1 = tail2 = 0;
			return ;
		}
		inline void PrePush(int _x){
			c1[++tail1] = _x;
			return ;
		}
		inline void Push(int _x){
			c2[++tail2] = _x;
			return ;
		}
		inline void PreSort(){
			sort(c1+head1,c1+tail1);
			return ;
		}
		inline bool Empty(){
			return (head1 > tail1) && (head2 > tail2);
		}
		inline int Front_Pop(){
			if(head1 > tail1){
				return c2[head2++];
			}else if(head2 > tail2){
				return c1[head1++];
			}else if(c1[head1] < c2[head2]){
				return c1[head1++];
			}else{
				return c2[head2++];
			}
			return 0;
		}
		Kueue(){Init();}
};
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
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadMap();
	SearchForEdge();
	DPSolve();
	Output();
	return 0;
}
