#include<bits/stdc++.h>
#define ll long long 
#define R register
using namespace std;
const int N=2e5+100,M=10010;
template<typename T>void read(T &x)
{
	x=0;char c=getchar();T neg=0;
	while(!isdigit(c))neg|=!(c^'-'),c=getchar();
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	if(neg)x=(~x)+1;
	return ;
}
template<typename T>void wr(T x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)wr(x/10);
	putchar((x-x/10*10)^48);
	return ;
}
int n,q,K,u1,v1,head[N],totl,dep[N],dis[N],son[N],fa[N],siz[N],id[N],tot,top[N],pos[N],toff;
ll val[N],dpp[N];
struct eed
{
	int u,v,nex;
}e[N<<1];
inline void add(int u,int v)
{
	e[++totl].u=u,e[totl].v=v,e[totl].nex=head[u],head[u]=totl;
	e[++totl].u=v,e[totl].v=u,e[totl].nex=head[v],head[v]=totl;
	return ;
}
void dfs1(int x,int f)
{
	fa[x]=f;
	dep[x]=dep[f]+1;
	siz[x]=1;
	int maxx=-1;
	for(R int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==f)continue;
		dis[v]=dis[x]+v;
		dfs1(v,x);
		siz[x]+=siz[v];
		
		if(siz[v]>maxx)maxx=siz[v],son[x]=v;
	}
}
void dfs2(int x,int lai)
{
	id[x]=++tot;
	pos[tot]=x;
	top[x]=lai;
	int sx=son[x];
	if(!sx)return ;
	dfs2(sx,lai);
	for(R int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v!=fa[x]&&v!=sx)
		dfs2(v,v);
	}
}
int lca(int l,int r)
{
	while(top[l]!=top[r])
	{
		if(dep[top[l]]<dep[top[r]])swap(l,r);
		l=fa[top[l]];
	}
	if(dep[l]>dep[r])swap(l,r);
	return l;
}
ll chl(int l,int r)
{
	ll dp[M],ans[M],to2=0;
//	printf("%lld %lld \m",to2,to3);
	memset(dp,0,sizeof(dp));
	memset(ans,0x3f,sizeof(ans));
	while(top[l]!=top[r])
	{
		if(dep[top[l]]<dep[top[r]])swap(l,r);
		for(R int i=id[l];i>=id[top[l]];--i)dp[++to2]=pos[i];
		l=fa[top[l]];
	}
	if(dep[l]>dep[r])swap(l,r);
	if(l!=r)
	for(R int i=id[l];i<=id[r];++i)dp[++to2]=pos[i];
	ans[1]=dp[1];
	for(R int i=2;i<=n;++i)
	{
		for(R int k=i-1;k>=i-K&&k>=1;--k)
		{
			ans[i]=min(ans[i],ans[k]+dp[i]);
		}
	}
	return ans[to2];
}
inline bool dfsf(int x,int ed,int f)
{
	if(x==ed){
		dpp[++toff]=x;
		return 1;
	}
	for(R int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==f)continue;
		if(dfsf(v,ed,x))
		{
			dpp[++toff]=x;
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
    read(n),read(q),read(K);	
	for(R int i=1;i<=n;++i)
    read(val[i]);
    for(R int i=1;i<n;++i)
    {
    	read(u1),read(v1);
    	add(u1,v1);
	}
	dis[1]=1;
    dfs1(1,1);
    dfs2(1,1);
    if(K==1)
    {
    	while(q--)
    	{
    		read(u1),read(v1);
    		int lc=lca(u1,v1);
    		wr(dis[u1]+dis[v1]-dis[lc]),puts("");
		}
    	return 0;
	}
	else
	{
		if(n>=210)
		{
			while(q--)
		    {
			read(u1),read(v1);
			wr(chl(u1,v1)),puts("");
		    }
		}
		else
		{
			while(q--)
			{
				read(u1);read(v1);
				toff=0;
				dfsf(u1,v1,u1);
				ll ans[M];
	            memset(ans,0x3f,sizeof(ans));
	             ans[1]=dpp[1];
	            for(R int i=2;i<=toff;++i)
	           {
		           for(R int k=i-1;k>=i-K&&k>=1;--k)
		          {
			        ans[i]=min(ans[i],ans[k]+dpp[i]);
		           }
	            }
	            wr(ans[toff]),puts("");
			}
		}
		return 0;
	}
	return 0;
}
/*
3 s
1024 mb

7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7

4 7
5 6
1 2

*/
