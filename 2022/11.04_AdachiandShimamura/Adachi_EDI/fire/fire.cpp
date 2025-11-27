#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ri register int

inline int rd()
{
	int a=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) a=(a<<1)+(a<<3)+c-'0';
	return a*f;
}

inline void wr(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
}

int n,s;

struct node{
	int nex,to,v;
}edge[1000050<<1];

int head[1000050];
int cnt;

inline void addedge(int st,int to,int v){
	edge[++cnt].to=to;
	edge[cnt].v=v;
	edge[cnt].nex=head[st];
	head[st]=cnt;
}

int k;
int dis[1000050];
int fa[1000050];
bool f[1000050];

inline void dfs(int x,int fath){
	fa[x]=fath;
	if(dis[x]>dis[k]) k=x;
	for(ri i=head[x];i;i=edge[i].nex){
		int v=edge[i].to;
		if(v==fath||f[v]) continue;
		dis[v]=dis[x]+edge[i].v;
		dfs(v,x);
	}
	return;
}

signed main(){
//	freopen("fire.in","r",stdin);
//	freopen("fire.out","w",stdout);
	n=rd(),s=rd();
	for(ri i=1;i<n;++i){
		int x=rd(),y=rd(),z=rd();
		addedge(x,y,z);
		addedge(y,x,z);
	}
	dis[1]=1e9;dfs(1,0);
	//wr(k),puts(" ");
	dis[k]=0;dfs(k,0);
	//wr(k),puts(" ");
	int ans=1e9 + 7;
	for(ri i=k,j=k;i;i=fa[i]){
		while(dis[j]-dis[i]>s) j=fa[j];
		ans=min(ans,max(dis[k]-dis[j],dis[i]));
	}
	//wr(ans),puts(" ");
	for(ri i=k;i;i=fa[i])
		f[i]=true;
		
	for(ri i=k;i;i=fa[i]){
		k=i;
		dis[k]=0;
		dfs(i,fa[i]);
	}
	
	for(ri i=1;i<=n;++i)
		ans=max(ans,dis[i]);
		
	wr(ans);
	
	return 0;
	
}

/*
5 2
1 2 5
2 3 2
2 4 4
2 5 3

8 6
1 3 2
2 3 2
3 4 6
4 5 3
4 6 4
4 7 2
7 8 3
*/
