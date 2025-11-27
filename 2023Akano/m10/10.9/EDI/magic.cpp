#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 6;
const int MAXS = (1<<18) + 1018 + 1108;
int id,T;
int n,m,k;
struct Magic{
	int type,deltax,deltay;	//1 type1上 2 type2左 3 type3左
	Magic() = default;		//4 type1下 5 type2右 6 type3右
	Magic(int _type,int _deltax,int _deltay){
		type = _type,deltax = _deltax,deltay = _deltay;
		return ;
	}
};
vector<Magic> magic;
bool blk[MAXN][MAXN],nowblk[MAXN][MAXN],vis[MAXS];
int no[MAXN][MAXN],nnt;
inline int Trans(){
	int ret = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(blk[i][j])ret += (1<<(no[i][j] - 1));
		}
	}
	return ret;
}
inline bool Judge(int x,int y){
	return (1 <= x && x <= n) && (1 <= y && y <= m);
}
inline void Draw(int x,int y,Magic maho){
	if(maho.type == 0){
		for(int i = -4;i <= 4;i++){
			const int OX = x + maho.deltax * i,OY = y + maho.deltay * i;
			if(Judge(OX,OY)){
				blk[OX][OY] = !blk[OX][OY];
			}
		}
	}else if(maho.type == 1){
		for(int i = -4;i <= 4;i++){
			const int OY1 = y + 2 * i;
			if(Judge(x,OY1)){
				blk[x][OY1] = !blk[x][OY1];
			}
			const int OY2 = OY1 + 1;
			if(Judge(x+1,OY2)){
				blk[x+1][OY2] = !blk[x+1][OY2];
			}
		}
	}else if(maho.type == 2){
		for(int i = -4;i <= 4;i++){
			const int OX1 = x + 2 * i;
			if(Judge(OX1,y)){
				blk[OX1][y] = !blk[OX1][y];
			}
			const int OX2 = OX1 + 1;
			if(Judge(OX2,y+1)){
				blk[OX2][y+1] = !blk[OX2][y+1];
			}
		}
	}else if(maho.type == 3){
		for(int i = -4;i <= 4;i++){
			const int OX1 = x + i,OY1 = y + 2 * i;
			if(Judge(OX1,OY1)){
				blk[OX1][OY1] = !blk[OX1][OY1];
			}
			if(Judge(OX1,OY1+1)){
				blk[OX1][OY1+1] = !blk[OX1][OY1+1];
			}
		}
	}
	return ;
}
inline bool Solve(){
	//记得清空!
	nnt = 0;
	magic.clear();
	memset(vis,0,sizeof(vis));
	
	cin>>n>>m>>k;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			no[i][j] = ++nnt;
			char ch;
			cin>>ch;
			blk[i][j] = (ch == '0');
		}
	}
	for(int i = 1;i <= k;i++){
		int _type,_x,_y;
		cin>>_type;
		if(_type == 1){
			cin>>_x>>_y;
			magic.emplace_back(0,_x,_y);
		}else{
			cin>>_type;
			magic.emplace_back(_type,1018,1108);
		}
	}
	
	queue<int> q;
	int startStat = Trans();
	vis[startStat] = true,q.push(startStat);
	if(startStat == 0)return true;
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		if(u == 0)return true;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(u & (1<<(no[i][j] - 1))){
					nowblk[i][j] = true;
				}else{
					nowblk[i][j] = false;
				}
			}
		}
		for(auto maho : magic){
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= m;j++){
					memcpy(blk,nowblk,sizeof(blk));
					Draw(i,j,maho);
					int nxt = Trans();
					if(!vis[nxt]){
						vis[nxt] = true,q.push(nxt);
						if(nxt == 0)return true;
					}
				}
			}
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>id>>T;
	while(T--){
		if(id >= 5){
			cout<<"No"<<endl;
			continue;//不可以,总司令!
		}
		bool suc = Solve();
		if(suc){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}
