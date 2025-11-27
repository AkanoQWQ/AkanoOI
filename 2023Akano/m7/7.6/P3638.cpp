#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
const int MAXN = 11;
const int MAXP = 503;
const int MAXK = 4;
const int INF = 1e8;
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
bool inq[MAXP][MAXP];
int f[MAXN][MAXN][MAXP][MAXP];
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
Point Search(Point pt,int dir){
	if(inq[pt.x][pt.y])return pt;//?OK?
	if(Border(pt) || mp[pt.x][pt.y] == 'x')return Point(pt.x-dx[dir],pt.y-dy[dir]);
	if(edgeTo[pt.x][pt.y][dir] != Point()){
		return edgeTo[pt.x][pt.y][dir];
	}
	inq[pt.x][pt.y] = true;
	int realDir = dir;
	if(mp[pt.x][pt.y] == 'A')realDir = (realDir - 1 + 4) % 4;
	if(mp[pt.x][pt.y] == 'C')realDir = (realDir + 1) % 4;
	edgeTo[pt.x][pt.y][dir] = Search(Point(pt.x+dx[realDir],pt.y+dy[realDir]),realDir);
	inq[pt.x][pt.y] = false;
	return edgeTo[pt.x][pt.y][dir];
}
inline void SearchForEdge(){
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			for(int k = 0;k < 4;k++)Search(Point(i,j),k);
		}
	}
	return ;
}
inline void PrintMap(){
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			cout<<mp[i][j];
		}
		cout<<endl;
	}
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			cout<<Point(i,j)<<" up-> "<<edgeTo[i][j][0]<<endl;
			cout<<Point(i,j)<<" right-> "<<edgeTo[i][j][1]<<endl;
			cout<<Point(i,j)<<" down-> "<<edgeTo[i][j][2]<<endl;
			cout<<Point(i,j)<<" left-> "<<edgeTo[i][j][3]<<endl;
		}
	}
	return ;
}
struct Node{
	int l,r,step;
	Point pos;
	Node(){l = r = step = 0,pos = Point();}
	Node(int _l,int _r,int _step,Point _pos){l = _l,r = _r,step = _step,pos = _pos;}
};
bool operator<(Node _a,Node _b){//for pq
	return _a.step > _b.step;
}
inline void SPFAforStatus(){
	for(int _1 = 1;_1 <= n;_1++){
		for(int _2 = 1;_2 <= n;_2++){
			for(int _3 = 1;_3 <= h;_3++){
				for(int _4 = 1;_4 <= w;_4++){
					f[_1][_2][_3][_4] = INF;//-1 ? INF ? 
				}
			}
		}
	}
	queue<Node> q;
	for(int i = 1;i <= n;i++){
		q.push(Node(i,i,0,startPos[i]));
		f[i][i][startPos[i].x][startPos[i].y] = 0;
	}
	while(!q.empty()){
		const Node now = q.front();
		q.pop();
		//Merge
		for(int i = 1;i < now.l;i++){
			const int Nstep = f[i][now.l-1][now.pos.x][now.pos.y] + now.step;
			if(f[i][now.r][now.pos.x][now.pos.y] <= Nstep)continue;
			q.push(Node(i,now.r,Nstep,now.pos));
			f[i][now.r][now.pos.x][now.pos.y] = Nstep;
		}
		for(int i = now.r+1;i <= n;i++){
			const int Nstep = f[now.r+1][i][now.pos.x][now.pos.y] + now.step;
			if(f[now.l][i][now.pos.x][now.pos.y] <= Nstep)continue;
			q.push(Node(now.l,i,Nstep,now.pos));
			f[now.l][i][now.pos.x][now.pos.y] = Nstep;
		}
		//Move
		for(int k = 0;k < 4;k++){
			const Point obj = edgeTo[now.pos.x][now.pos.y][k];
			if(now.step+1 < f[now.l][now.r][obj.x][obj.y]){
				q.push(Node(now.l,now.r,now.step+1,obj));
				f[now.l][now.r][obj.x][obj.y] = now.step + 1;
			}
		}
	}
	return ;
}
inline void Output(){
	int ans = INF;
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			ans = min(ans,f[1][n][i][j]);
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
	SPFAforStatus();
	Output();
	return 0;
}
