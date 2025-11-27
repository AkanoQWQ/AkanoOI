#include<bits/stdc++.h>
using namespace std;
int blocks[106][106],i,j,h,w,objective = 1410,ans;
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	cin>>h>>w;
	for(i = 0;i < h;i++){
		for(j = 0;j < w;j++){
			cin>>blocks[i][j];
			objective = min(objective,blocks[i][j]);
		}
	}
	for(i = 0;i < h;i++){
		for(j = 0;j < w;j++){
			if(objective < blocks[i][j]){
				ans += blocks[i][j] - objective;
			}
		}
	}
	cout<<ans;
	return 0;
}

