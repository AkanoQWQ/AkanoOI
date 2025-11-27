#include<bits/stdc++.h>
using namespace std;
 /*void dfs1(int x,int f,int deep){
    dep[x]=deep;
    fa[x]=f;
    siz[x]=1;
    int maxson=-1;
    for(int i=head[x];i;i=e[i].nex){
        int y=e[i].v;
        if(y==f)continue;
        dfs1(y,x,deep+1);
        siz[x]+=siz[y];
        if(siz[y]>maxson)son[x]=y,maxson=siz[y];
    }
}*/
void dfs1(int x)
{
	son[x]=-1;
	siz[x]=1;
	for(int i=head[x];i;i=e[i].nex)
	{
		int y=e[i].v;
		if(dep[y]) continue;
		dep[y]=dep[x]+1;
		fa[y]=x;
		dfs1(y);
		siz[x]+=siz[y];
		if(son[x]==-1||siz[y]>siz[son[x]]) son[x]=y;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	return 0;
}

