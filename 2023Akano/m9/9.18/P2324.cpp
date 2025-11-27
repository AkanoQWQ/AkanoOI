#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 6;
const int MAXANS = 15;
const int n = 5;
const int dx[8] = {-2,-1,1,2,2,1,-1,-2};
const int dy[8] = {1,2,2,1,-1,-2,-2,-1};
struct ChessBoard{
	char status[MAXN][MAXN];
	char* operator[](int x){
		return status[x];
	}
	const char* operator[](int x)const {
		return status[x];
	}
}stdBoard;
struct Search{
	ChessBoard board;
	int step,val;
	inline void GetValue(){
		val = step;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				val += (board[i][j] != stdBoard[i][j]);
			}
		}
		if(val > step)val--;
		return ;
	}
};
bool operator<(const ChessBoard& cb1,const ChessBoard& cb2){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(cb1[i][j] != cb2[i][j])return cb1[i][j] < cb2[i][j];
		}
	}
	return false;
}
bool operator==(const ChessBoard& cb1,const ChessBoard& cb2){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(cb1[i][j] != cb2[i][j])return false;
		}
	}
	return true;
}
bool operator<(const Search& s1,const Search& s2){
	return s1.val > s2.val;
}
int t;
inline void Init(){
	stdBoard[1][1] = stdBoard[1][2] = stdBoard[1][3] = stdBoard[1][4] = stdBoard[1][5] = '1';
	stdBoard[2][1] = '0',stdBoard[2][2] = stdBoard[2][3] = stdBoard[2][4] = stdBoard[2][5] = '1';
	stdBoard[3][1] = stdBoard[3][2] = '0',stdBoard[3][3] = '*',stdBoard[3][4] = stdBoard[3][5] = '1';
	stdBoard[4][1] = stdBoard[4][2] = stdBoard[4][3] = stdBoard[4][4] = '0',stdBoard[4][5] = '1';
	stdBoard[5][1] = stdBoard[5][2] = stdBoard[5][3] = stdBoard[5][4] = stdBoard[5][5] = '0';
	return ;
}
inline int Solve(){
	Search st;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin>>st.board[i][j];
		}
	}
	st.step = 0,st.GetValue();
	if(st.board == stdBoard)return 0;
	for(int lim = 0;lim <= MAXANS;lim++){
		set<ChessBoard> vis;
		priority_queue<Search> q;
		
		bool OK = false;
		if(vis.find(st.board) == vis.end()){
			if(st.val <= lim){
				if(st.val == st.step)OK = true;
				vis.insert(st.board);
				q.push(st);
			}
		}
		while(!q.empty()){
			if(OK)break;
			const Search now = q.top();
			q.pop();
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					if(now.board[i][j] != '*')continue;
					for(int k = 0;k < 8;k++){
						const int OX = i + dx[k],OY = j+dy[k];
						if(1 <= OX && OX <= n && 1 <= OY && OY <= n){
							Search nxt = now;
							swap(nxt.board[i][j],nxt.board[OX][OY]);
							if(vis.find(nxt.board) == vis.end()){
								nxt.step = now.step + 1;
								nxt.GetValue();
								if(nxt.val <= lim){
									if(nxt.val == nxt.step)OK = true;
									vis.insert(nxt.board);
									q.push(nxt);
								}
							}
						}
					}
				}
			}
		}
		if(OK)return lim;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	Init();
	cin>>t;
	while(t--){
		cout<<Solve()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
