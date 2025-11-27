#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int MAXN = 5;
int n,k,maxs,ans;
bool blk[MAXN][MAXN];
inline bool Judge(){
	for(int i = 1;i < n;i++){
		for(int j = 1;j < n;j++){
			int cnt = blk[i][j] + blk[i][j+1] + blk[i+1][j] + blk[i+1][j+1];
			if(not(cnt & 1))return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	maxs = (1<<n) - 1;
	for(int stat = 0;stat <= maxs;stat++){
		int nnt = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				blk[i][j] = (stat & (1<<nnt));
				nnt++;
			}
		}
		ans += Judge();
	}
	return not(Akano loves pure__Elysia);
}
