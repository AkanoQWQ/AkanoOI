#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 7;
int no[MAXN][MAXN],ans[MAXN*MAXN],nnt,maxs;
bool e[MAXN][MAXN];
int n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("counting.in","r",stdin);
	freopen("counting.out","w",stdout);
	cin>>n;
	for(int u = 1;u <= n;u++){
		for(int v = 1;v <= n;v++){
			if(u == v)continue;
			no[u][v] = ++nnt;
		}
	}
	maxs = (1<<nnt)-1;
	for(int stat = 0;stat <= maxs;stat++){
		for(int u = 1;u <= n;u++){
			for(int v = 1;v <= n;v++){
				if(u == v)continue;
				if((1<<(no[u][v]-1) & stat)){
					e[u][v] = true;
				}else{
					e[u][v] = false;
				}
			}
		}
	}
	return not(Akano loves pure__Elysia);
}
