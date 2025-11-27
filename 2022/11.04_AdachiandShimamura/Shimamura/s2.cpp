#include<bits/stdc++.h>
using namespace std;
const int MAXN = 106;
int n,m,tot;
struct pr{
	int r,c;
}p[12006];
bool cmp(pr a,pr b){
	return (a.r*a.c) > (b.r*b.c);
}
int mp[MAXN][MAXN],np[MAXN][MAXN],mainr,mainc,nowk,mpcnt;
bool judge(int stx,int sty){
	for(int x = 0;x < mainr;x++){
		for(int y = 0;y < mainc;y++){
			if(np[stx+x][sty+y]+1 > mp[stx+x][sty+y])return 0;
		}
	}
	return 1;
}
void show(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<np[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return ;
}
bool dfs(){
	for(int i = 1;(i+mainr-1) <= n;i++){
		for(int j = 1;(j+mainc-1) <= m;j++){
			if(judge(i,j)){
				for(int x = 0;x < mainr;x++){
					for(int y = 0;y < mainc;y++){
						np[i+x][j+y]++;
					}
				}
				nowk -= mainr*mainc;
				if(nowk == 0)return 1;
				if(dfs())return 1;
				for(int x = 0;x < mainr;x++){
					for(int y = 0;y < mainc;y++){
						np[i+x][j+y]--;
					}
				}
				nowk += mainr*mainc;
			}
		}
	}
	return 0;
}
bool play(int r,int c){
	memset(np,0,sizeof(np));
	mainr = r;
	mainc = c;
	nowk = mpcnt;
	return dfs();
}
int main(){
	freopen("susliks.in","r",stdin);
	//freopen("susliks.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>mp[i][j];
			mpcnt += mp[i][j];
			p[++tot].r = i;
			p[tot].c = j;
		}
	}
	sort(p+1,p+tot+1,cmp);
	for(int i = 1;i <= tot;i++){
		if(play(p[i].r,p[i].c)){
			cout<<mpcnt / (p[i].r * p[i].c);
			return 0;
		}
	}
	return 0;
}

