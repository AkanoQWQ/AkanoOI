#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using pii = pair<int,int>;
const int MAXN = 14;
const int MAXP = 506 * 506;
const int MAXK = 5;
const int INF = 0x7fffffff / 2 - 1;
const int dx[4] = {-1,0,1,0};//up right down left
const int dy[4] = {0,1,0,-1};
int n,w,h;
inline int Zip(int x,int y){
	return (x-1) * w + y; //1 ~ wh
}
inline pii Decode(int no){
	pii ret;
	ret.second = ((no-1) % w)+1;
	ret.first = (no + 1 - ret.second) / w + 1;
	return ret;
}
ostream& operator<<(ostream& cout,pii _pii){
	cout<<"("<<_pii.first<<","<<_pii.second<<")";
	return cout;
}
//vars 
int edgeTo[MAXP][MAXK],startPos[MAXN];
bool inqSearch[MAXP][MAXK];
int dis[MAXN][MAXN][MAXP];
char mp[MAXP];
inline void ReadMap(){
	cin>>n>>w>>h;
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			const int No = Zip(i,j);
			cin>>mp[No];
			if(isdigit(mp[No])){
				startPos[mp[No]-'0'] = Zip(i,j);
				mp[No] = '.';
			}
		}
	}
	return ;
}
inline bool Judge(int x,int y){
	return (x >= 1 && x <= h && y >= 1 && y <= w) && (mp[Zip(x,y)] != 'x');
}
int Search(int no,int dir){
	if(inqSearch[no][dir]){
		edgeTo[no][dir] = -1;
		return edgeTo[no][dir];
	}
	if(edgeTo[no][dir])return edgeTo[no][dir];
	inqSearch[no][dir] = true;
	int realDir = dir;
	if(mp[no] == 'A'){
		realDir = realDir + 3;
		if(realDir >= 4)realDir -= 4;
	}
	if(mp[no] == 'C'){
		realDir = realDir + 1;
		if(realDir >= 4)realDir -= 4;
	}
	const pii nowxy = Decode(no);
	if(!Judge(nowxy.first+dx[realDir],nowxy.second+dy[realDir])){
		edgeTo[no][dir] = no;
	}else{
		edgeTo[no][dir] = Search(Zip(nowxy.first+dx[realDir],nowxy.second+dy[realDir]),realDir);
	}
	inqSearch[no][dir] = false;
	return edgeTo[no][dir];
}
inline void SearchForEdge(){
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			if(mp[Zip(i,j)] != 'x'){
				for(int k = 0;k < 4;k++){
					Search(Zip(i,j),k);
				}
			}
		}
	}
	return ;
}
bool inq[MAXP];
int MainL,MainR;
bool Cmp(int _a,int _b){
	return dis[MainL][MainR][_a] < dis[MainL][MainR][_b];
}
const int KUE_SIZE = MAXP * 4;
struct Kueue{
	int c[KUE_SIZE],head,tail;
	inline void Push(const int& _x){
		c[++tail] = _x;
		if(tail >= KUE_SIZE - 5){
			tail = 0;
		}
		return ;
	}
	inline int Front_Pop(){
		if(head+1 >= KUE_SIZE - 5){
			const int ret = c[head];
			head = 0;
			return ret;
		}
		return c[head++];
	}
	inline int Front(){
		return c[head];
	}
	inline bool Empty(){
		return head == tail+1;
	}
	inline void SortInner(){
		if(head < tail)sort(c+head,c+tail,Cmp);
		return ;
	} 
	Kueue(){head = 1,tail = 0;}
};
struct PairKueue{
	Kueue k1,k2;
	inline void PrePush(const int& _x){
		k1.Push(_x);
		return ;
	}
	inline void PreCalc(){
		k1.SortInner();
		return ;
	}
	inline void Push(const int& _x){
		k2.Push(_x);
		return ;
	}
	inline int Front_Pop(){
		if(k1.Empty()){
			return k2.Front_Pop();
		}else if(k2.Empty()){
			return k1.Front_Pop();
		}else if(dis[MainL][MainR][k1.Front()] < dis[MainL][MainR][k2.Front()]){
			return k1.Front_Pop();
		}else{
			return k2.Front_Pop();
		}
	}
	inline bool Empty(){
		return (k1.Empty() && k2.Empty());
	}
};
inline void SPFAforStatus(int l,int r){
	MainL = l,MainR = r;
	PairKueue q;
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			const int no = Zip(i,j);
			inq[no] = false;
			if(dis[l][r][no] < INF){
				inq[no] = true;
				q.PrePush(no);
			}
		}
	}
	q.PreCalc();
	while(!q.Empty()){
		const int now = q.Front_Pop();
		inq[now] = false;
		const int nowstep = dis[l][r][now];
		//Move
		for(int k = 0;k < 4;k++){
			const int obj = edgeTo[now][k];
			if(obj <= 0)continue;
			if(nowstep + 1 < dis[l][r][obj]){
				dis[l][r][obj] = nowstep + 1;
				if(!inq[obj]){
					q.Push(obj);
					inq[obj] = true;
				}
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
					dis[_1][_2][Zip(_3,_4)] = INF;//-1 ? INF ? 
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		dis[i][i][startPos[i]] = 0;
		SPFAforStatus(i,i);
	}	
	for(int len = 2;len <= n;len++){
		for(int l = 1;l + len - 1 <= n;l++){
			const int r = l + len - 1;
			for(int mid = l;mid < r;mid++){
				for(int _x = 1;_x <= h;_x++){
					for(int _y = 1;_y <= w;_y++){
						const int no = Zip(_x,_y);
						dis[l][r][no] = min(dis[l][r][no],dis[l][mid][no] + dis[mid+1][r][no]);
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
			ans = min(ans,dis[1][n][Zip(i,j)]);
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
