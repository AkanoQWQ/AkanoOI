#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,m_ap[1005][1005],way[1005][1005],head,tail,x,y;
int wx[5] = {0,1,0,-1,0};
int wy[5] = {0,0,-1,0,1};
struct steam{
	int x;
	int y;
	int s;
}wmap[10006];
int main(){
	//freopen("maze.in","r",stdin);
	//freopen("maze.out","w",stdout);
	cin>>n>>m;
	for(i = 1;i <= n;i++){
		for(j = 1;j <= m;j++){
			cin>>m_ap[i][j];
		}
	}
	way[1][1] = 1;
	head = 0;
	tail = 1;
	wmap[tail].x = 1;
	wmap[tail].y = 1;
	wmap[tail].s = 1;
	while(head < tail){
		head++;
		for(i = 1;i <= 4;i++){
			x = wmap[head].x + wx[i];
			y = wmap[head].y + wy[i];
			if((x >= 1 && x <= n) & (y >= 1 && y <= m) && (m_ap[x][y] == 0 && way[x][y] == 0)){
				way[x][y] = 1;
				tail++;
				wmap[tail].x = x;
				wmap[tail].y = y;
				wmap[tail].s = wmap[head].s + 1;
				if(wmap[tail].x == n && wmap[tail].y == m){
					cout<<wmap[tail].s<<endl;
					return 0;
				}
			}
		}
	}
	cout<<-1;
	return 0;
}
