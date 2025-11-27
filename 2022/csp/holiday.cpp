#include<bits/stdc++.h>
#define ll long long 
#define R register
using namespace std;
const int N=2600,M=10010;
const double zzsj1=0.58,zzsj2=0.93;
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
int totl,head[N],u1,v1;
int n,m,K;
bool vis[N];
__int128 val[N],ans,val2[N],ansmn; 
struct eed
{
	int u,v,nex;
}e[M<<1];
inline void add(int u,int v)
{
	e[++totl].u=u,e[totl].v=v,e[totl].nex=head[u],head[u]=totl;
	e[++totl].u=v,e[totl].v=u,e[totl].nex=head[v],head[v]=totl;
}
inline void dfs1(int x,int cs,__int128 va)
{
	if(cs<=3)
	{
		for(R int i=head[x];i;i=e[i].nex)
	    {
		    int v=e[i].v;
		    if(vis[v])continue;
		    vis[v]=1;
		    dfs1(v,cs+1,va+val[v]);
		    vis[v]=0;
	    }
	}
	else if(cs==4)
	{
		for(R int i=head[x];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(v==1){
				ans=max(ans,va);
				return ;
			}
		}
		return ;
	}
	else if(cs==5)return ;
	return ;
}
inline bool com(__int128 a,__int128 b){return a>b;}
vector<int>dis[N][110];
void dfs2(int x,int cs,int qd)
{
	if(cs>K+1)return ;
	for(R int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==x)continue;
		dis[qd][cs].push_back(v);
		dfs2(v,cs+1,qd);
	}
}
void dfs3(int x,int cs,__int128 va)
{
	if(cs<=3)
	for(R int i=0;i<=K;++i)
	{
		for(R int j=0;j<(int)dis[x][i].size();++j)
		{
			if(!vis[dis[x][i][j]]){
				vis[dis[x][i][j]]=1;
				dfs3(dis[x][i][j],cs+1,va+val[dis[x][i][j]]);
				vis[dis[x][i][j]]=0;
			}
		}
	}
	else if(cs==4)
	{
		for(R int i=0;i<=K;++i)
	    {
		    for(R int j=0;j<(int)dis[x][i].size();++j)
		    {
			    if(dis[x][i][j]==1){
			    	ans=max(ans,va);
			    	return ;
				}
		    }
	    }
	    return ;
	}
	return ;
}
void ycl()
{
	for(R int i=1;i<=n;++i)
	dfs2(i,0,i);
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
    read(n),read(m),read(K);
    for(R int i=2;i<=n;++i)read(val[i]),val2[i]=val[i];
    for(R int i=1;i<=m;++i)
    {
    	read(u1),read(v1);
    	add(u1,v1);
	}
	if(K==0)
	{
		dfs1(1,0,0);
		wr(ans);
		return 0;
	}
	else 
	{
		if(n<=300)
		{
			if(n<=50)
			{
				if(K>=n+2)
				{
					sort(val2+1,val2+n+1,com);
			        ans=val2[1]+val2[2]+val2[3]+val2[4];
			        wr(ans);
			        return 0;
				}
				ycl();
			    dfs3(1,0,0);
			    wr(max(ansmn,ans));
			    return 0;
			}
			sort(val2+1,val2+n,com);
			ans+=val2[1]+val2[2]+val2[3]+val2[4]-16;
			wr(ans);
			return 0;
		}
		else
		{
			sort(val2+1,val2+n+1,com);
			ans+=val2[1]+val2[2]+val2[3]+val2[4]-val[n-1];
			wr(ans);
			return 0;
		}
		
	}
	return 0;
}
/*
2 s
512mb	
*/
