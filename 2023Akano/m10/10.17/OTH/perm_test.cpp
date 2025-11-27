#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1018 + 1108;
bool vis[MAXN][MAXN];
int f[MAXN][MAXN],n,q,a[MAXN];
int F(int x,int y){
	if(vis[x][y]){
		f[x][y] = -1e7;
		return -1e7;
	}
	if(x == y)return 1;
	if(f[x][y] != -1)return f[x][y];
	vis[x][y] = true;
	f[x][y] = F(x + y - abs(x-y),abs(x-y)) + 1;
	vis[x][y] = false;
	return f[x][y];
}
vector<pair<int,int> > vecs[111];
set<pair<int,int> > st[111];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("perm/perm2.in","r",stdin);
	freopen("perm/perm2.out","w",stdout);
	memset(f,-1,sizeof(f));
	n = 1000;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if((i+j) % 2 == 1)continue;
			if(F(i,j) > 0 && F(i,j) <= 100){
				vecs[F(i,j)].emplace_back(i,j);
			}
		}
	}
	for(int i = 1;i <= 100;i++){
		if(vecs[i].empty())continue;
		for(auto j : vecs[i]){
			int gcd = __gcd(j.first,(j.first + j.second));
			st[i].insert(make_pair(j.first / gcd,(j.first + j.second) /gcd));
		}
		cerr<<i<<" : ";
		for(auto j : st[i]){
			cerr<<j.first<<"/"<<j.second<<" ";
		}
		cerr<<endl;
	}
	return not(Akano loves pure__Elysia);
}
