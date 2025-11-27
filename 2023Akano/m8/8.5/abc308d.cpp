#include<bits/stdc++.h>
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int MAXN = 606;
int n,m;
char MP[MAXN][MAXN];
bool vis[MAXN][MAXN];
queue<pii> q;
char nxt[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	nxt['s'] = 'n';
	nxt['n'] = 'u';
	nxt['u'] = 'k';
	nxt['k'] = 'e';
	nxt['e'] = 's';
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>MP[i][j];
		}
	}
	if(MP[1][1] != 's'){
		NO;
		return 0;
	}
	q.push(mp(1,1));
	vis[1][1] = true;
	while(!q.empty()){
		const pii u = q.front();
		q.pop();
		for(int k = 0;k < 4;k++){
			const int OX = u.first + dx[k],OY = u.second + dy[k];
			if(1 <= OX && OX <= n && 1 <= OY && OY <= m && !vis[OX][OY] && MP[OX][OY] == nxt[MP[u.first][u.second]]){
				vis[OX][OY] = true;
				q.push(mp(OX,OY));
			}
		}
	}
	if(vis[n][m]){
		YES;
	}else{
		NO;
	}
	return 0;
}



