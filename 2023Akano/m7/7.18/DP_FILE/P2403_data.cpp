#include<bits/stdc++.h>
#include "comp.h"
using namespace std;
const int MAXR = 1e3 + 6;
int n = 7,r = 6,c = 6;
int typ[MAXR][MAXR];
Rander rd = Rander(GetTime(),1,r);
int main(){
	freopen("P2043.in","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<n<<" "<<r<<" "<<c<<endl;
	for(int i = 1;i <= n;i++){
		int x = rd(),y = rd();
		if(typ[x][y] != 0){
			x = rd(),y = rd();
		}
		typ[x][y] = 3;
	}
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= r;j++){
			if(typ[i][j] != 0){
				cout<<i<<" "<<j<<" "<<typ[i][j]<<endl;
			}
		}
	}
	cout.clear(),cin.clear();
	freopen("P2043.chk","w",stdout);
	cout<<rd()<<endl;
	return 0;
}

