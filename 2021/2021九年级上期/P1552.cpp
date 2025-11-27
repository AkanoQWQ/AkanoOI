#include<bits/stdc++.h>
using namespace std;
const int INF = 1<<30;
const int MN = 206;
int n,dis[MN],roads[MN][MN],v0,i,j,len,cint,Wei;
bool vis[MN];
string cch;
void DIJ(int STR){
	for(int i = 0;i <= n;i++){
		dis[i] = INF;
	}
	dis[STR] = 0;
	for(int i = 0;i <= n;i++){
		int TPoint = -1,TValue = INF;
		for(int j = 0;j <= n;j++){
			if(vis[j] == 0 && dis[j] < TValue){
				TPoint = j,TValue = dis[j];
			}
		}
		for(int j = 0;j <= n;j++){
			if(vis[j] == 0 && dis[TPoint] + roads[TPoint][j] < dis[j]){
				dis[j] = dis[TPoint] + roads[TPoint][j];
			}
		}
		vis[TPoint] = 1;
	}
}
int main(){
	//freopen("P1552.in","r",stdin);
	//freopen(".out","w",stdout);
	memset(roads,2,sizeof(roads));
	cin>>n>>v0;
	for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			cin>>cch;
			if(cch == "-")continue;
			len = cch.length()-1,Wei = 1,cint = 0;
			while(len >= 0){
				cint += (cch[len] - '0')*Wei,Wei *= 10;
				len--;
			}
			roads[i][j] = cint;
		}
	}
	DIJ(v0);
	for(i = 1;i <= n;i++){
		if(i != v0){
			cout<<"("<<v0<<" -> "<<i<<") = "<<dis[i]<<endl;
		}
	}
	return 0;
}
