#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 2006 + 1018 + 1108;
int no,n,m,q,ans;
bool mp[MAXN][MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("color/color2.in","r",stdin);
	cin>>no>>n>>m>>q;
	while(q--){
		int opt,_x1,_x2,_y1,_y2;
		cin>>opt>>_x1>>_y1>>_x2>>_y2;
		if(_x1 > _x2)swap(_x1,_x2);
		if(_y1 > _y2)swap(_y1,_y2);
		if(opt == 1){
			for(int i = _x1;i <= _x2;i++){
				mp[i][_y1] = true;
			}
		}else if(opt == 2){
			for(int i = _y1;i <= _y2;i++){
				mp[_x1][i] = true;
			}
		}else if(opt == 3){
			for(int i = _x1,j = _y1;i <= _x2;i++,j++){
				mp[i][j] = true;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			ans += mp[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
