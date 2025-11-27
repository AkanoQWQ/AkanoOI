#include<bits/stdc++.h>
using namespace std;
int house[10006][100][2],n,m,i,j,ans,posx,posy;
int rooms[10006];
int main(){
	//freopen("NOIP2012P02.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(i = 1;i <= n;i++){
		for(j = 0;j < m;j++){
			cin>>house[i][j][0]>>house[i][j][1];
			if(house[i][j][0] == 1)rooms[i]++;
		}
	}
	cin>>j;
	//ans += house[1][j][1];
	posx = 1,posy = j;
	while(posx <= n){
		//cout<<posx<<" "<<posy<<" ";
		ans += house[posx][posy][1];
		i = house[posx][posy][1];
		if(i > rooms[posx])i %= rooms[posx];
		if(i == 0)i = rooms[posx];
		//cout<<i<<endl;
		for(j = posy;j <= (m+3);j++){
			if(j >= m)j -= m;//0-6
			if(house[posx][j][0] == 1)i--;
			if(i == 0)break;//7
		}
		posx += 1,posy = j;
	}
	cout<<ans;
	return 0;
}

