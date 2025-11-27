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
bool operator<=(pii _a,pii _b){
	return _a.first <= _b.first;
}
ostream& operator<<(ostream& cout,pii _pii){
	cout<<"("<<_pii.first<<","<<_pii.second<<")";
	return cout;
}
struct Node{
	pii val;
	int key,l,r,tot,sz,ret;
	Node(pii inv,int ink){
		val = inv;
		key = ink;
		tot = sz = 1;
		l = r = 0;
	}
	Node(){
		key = l = r = tot = sz = 0;
	}
};
class Treap{
	private:
		Node node[MAXN];
		int cnt,root;
		inline int& L(int p){
			return node[p].l;
		}
		inline int& R(int p){
			return node[p].r;
		}
		inline void PushUp(int p){
			node[p].sz = node[L(p)].sz + node[R(p)].sz + node[p].tot;
			return ;
		}
		inline void Zag(int &p){//×óÐý 
			int q = R(p);
			R(p) = L(q);
			L(q) = p;
			p = q;
			PushUp(p);
			PushUp(L(p));
			return ;
		}
		inline void Zig(int &p){//ÓÒÐý 
			int q = L(p);
			L(p) = R(q);
			R(q) = p;
			p = q;
			PushUp(p);
			PushUp(R(p));
			return ;
		}
		void Insert(int &p,pii val){
			if(!p){
				node[++cnt] = Node(val,rand());
				p = cnt;
				return ;
			}
			if(val == node[p].val){
				node[p].tot++;
			}else if(val < node[p].val){
				Insert(L(p),val);
				if(node[p].key < node[L(p)].key){
					Zig(p);
				}
			}else{
				Insert(R(p),val);
				if(node[p].key < node[R(p)].key){
					Zag(p);
				}
			}
			PushUp(p);
			return ;
		}
		void Delete(int &p,pii val){
			if(!p)return ;
			if(node[p].val == val){
				if(node[p].tot >= 2){
					--node[p].tot;
				}else if(L(p) + R(p)){
					if(node[L(p)].key > node[R(p)].key){
						Zig(p);
						Delete(R(p),val);
					}else{
						Zag(p);
						Delete(L(p),val);
					}
				}else{
					node[p] = Node(make_pair(0,0),-1);
					p = 0;
				}
			}else if(val < node[p].val){
				Delete(L(p),val); 
			}else if(val > node[p].val){
				Delete(R(p),val);
			}
			PushUp(p);
			return ;
		}
		pii GetVal(int p,int k){
			if(k <= node[L(p)].sz){
				return GetVal(L(p),k);
			}else if(k <= node[L(p)].sz + node[p].tot){
				return node[p].val;
			}
			return GetVal(R(p),k - node[L(p)].sz - node[p].tot);
		}
	public:
		inline void Init(){
			cnt = 0;
			root = 0;
			Insert(root,make_pair(INF,0));
			Insert(root,make_pair(-INF,0));
			return ;
		}
		inline void Insert(pii val){
			Insert(root,val);
			return ;
		}
		inline void Delete(pii val){
			Delete(root,val);
			return ;
		}
		inline pii GetVal(int k){
			return GetVal(root,k);
		}
		inline pii GetMax(){
			return GetVal(node[root].sz-1);
		} 
		inline bool Empty(){
			return (node[root].sz <= 2);
		}
		inline int Size(){
			return node[root].sz;
		}
}tr;


inline int Zip(int x,int y){
	return (x-1) * w + y; //1 ~ wh
}
inline pii Decode(int no){
	pii ret;
	ret.second = ((no-1) % w)+1;
	ret.first = (no + 1 - ret.second) / w + 1;
	return ret;
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
bool vis[MAXP];
inline void DIJforStatus(int l,int r){
	tr.Init();
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			const int no = Zip(i,j);
			vis[no] = false;
			if(dis[l][r][no] < INF){
				cout<<"INS "<<make_pair(-dis[l][r][no],no)<<endl;
				tr.Insert(make_pair(-dis[l][r][no],no));
			}
		}
	}
	while(!tr.Empty()){
		const pii nowpr = tr.GetMax();
		const int now = nowpr.second;
		cout<<"FIND "<<nowpr<<endl;
		tr.Delete(nowpr);
		if(vis[now])continue;
		vis[now] = true;
		const int nowstep = dis[l][r][now];
		cout<<-nowpr.first<<" COMPARE "<<dis[l][r][now]<<endl;
		//Move
		for(int k = 0;k < 4;k++){
			const int obj = edgeTo[now][k];
			if(obj <= 0)continue;
			if(nowstep + 1 < dis[l][r][obj]){
				dis[l][r][obj] = nowstep + 1;
				tr.Insert(make_pair(- nowstep - 1,obj));
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
		DIJforStatus(i,i);
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
			DIJforStatus(l,r);
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
	freopen("P3638.in","r",stdin);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadMap();
	SearchForEdge();
	DPSolve();
	Output();
	return 0;
}
