#include<bits/stdc++.h>
#include "AL/rander.h"
using namespace std;
const int MAXVAL = 1e9;
const int MAXN = 1<<20;
int maxdep = 8,dep[MAXN];
int n = (1<<maxdep) - 1,m = 14;
Rander rd;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("trade/data.in","w",stdout);
	cout<<maxdep<<" "<<m<<endl;
	for(int i = 1;i <= n;i++){
		dep[i] = dep[i/2] + 1;
	}
	for(int i = 2;i <= n;i++){
		cout<<rd(1,MAXVAL)<<" ";
	}
	cout<<endl;
	for(int t = 1;t <= m;t++){
		int v = rd(2,n);
		int fadp = dep[v] - 1;
		int up = rd(1,fadp);
		int u = v;
		while(up--)u >>= 1;
		int w = rd(1,MAXVAL);
		cout<<u<<" "<<v<<" "<<w<<endl;
	}
	return 0;
}

