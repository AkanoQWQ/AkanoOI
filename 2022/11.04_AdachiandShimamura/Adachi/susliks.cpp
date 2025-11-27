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
int judge2(int stx,int sty){
	int ret = 0x7fffffff;
	for(int x = 0;x < mainr;x++){
		for(int y = 0;y < mainc;y++){
			ret = min(ret,mp[stx+x][sty+y]-np[stx+x][sty+y]);
		}
	}
	return ret;
}
/*
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
bool judge(int stx,int sty){
	for(int x = 0;x < mainr;x++){
		for(int y = 0;y < mainc;y++){
			if(np[stx+x][sty+y]+1 > mp[stx+x][sty+y])return 0;
		}
	}
	return 1;
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
*/
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
bool play2(int r,int c){
	memset(np,0,sizeof(np));
	mainr = r;
	mainc = c;
	nowk = mpcnt;
	for(int i = 1;(i+mainr-1) <= n;i++){
		for(int j = 1;(j+mainc-1) <= m;j++){
			int j2 = judge2(i,j);
			if(j2 <= 0)continue;
			for(int x = 0;x < mainr;x++){
				for(int y = 0;y < mainc;y++){
					np[i+x][j+y] += j2;
				}
			}
			nowk -= j2 * (r * c);
			if(nowk == 0)return 1;
		}
	}
	return 0;
}
int main(){
	freopen("susliks.in","r",stdin);
	freopen("susliks.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			mp[i][j] = read();
			mpcnt += mp[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(mpcnt % (i*j) != 0)continue; 
			p[++tot].r = i;
			p[tot].c = j;
		}
	}
	sort(p+1,p+tot+1,cmp);
	for(int i = 1;i <= tot;i++){
		if(play2(p[i].r,p[i].c)){
			cout<<mpcnt / (p[i].r * p[i].c);
			return 0;
		}
	}
	return 0;
}
