#include<bits/stdc++.h>
#include "comp.h"
using namespace std;
const int MAXN = 1e5 + 1018;
const int MAXM = 1e6 + 1108;
set<pair<int,int> > vis;
int n = 1e5,m = 1e6;
mt19937 rng(GetTime());
inline int rd(int up){
	return (rng() % up) + 1;
}
int main(){
	freopen("easy.in","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i < n;i++){
		--m;
		cout<<i<<" "<<i+1<<" "<<int(1e9)<<'\n';
	}
	while(m--){
		int x = rd(n),y = rd(n);
		if(x > y)swap(x,y);
		while(vis.find(make_pair(x,y)) != vis.end() || x == y){
			x = rd(n),y = rd(n);
			if(x > y)swap(x,y);
		}
		vis.insert(make_pair(x,y));
		cout<<x<<" "<<y<<" "<<rd(1e9)<<'\n';
	}
	cout<<flush;
	return 0;
}

