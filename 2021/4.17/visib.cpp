#include<bits/stdc++.h>
using namespace std;
int i,j,k,h,w,x,y,ans;
char _Map[106][106];
int main(){
	freopen("visib.in","r",stdin);
	freopen("visib.out","w",stdout);
	cin>>h>>w>>x>>y;
	for(i = 1;i <= h;i++){
		for(j = 1;j <= w;j++){
			cin>>_Map[i][j];
		}
	}
	for(i = x;i > 0;i--){
		if(_Map[i][y] != '.'){
			break;
		}
		ans++;
	}
	//3 5 1 4
	//#....
	//#####
	//....#
	for(i = x;i <= h;i++){
		if(_Map[i][y] != '.'){
			break;
		}
		ans++;
	}
	for(i = y;y <= w;i++){
		if(_Map[x][i] != '.'){
			break;
		}
		ans++;
	}
	for(i = y;y > 0;i--){
		if(_Map[x][i] != '.'){
			break;
		}
		ans++;
	}
	ans -= 3;
	cout<<ans;
	return 0;
}

