#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;
int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int n,m,s,x,y,z,c[MAXN],isp[MAXN],q;
int head[MAXN],tot=0;
struct edge
{
    int from,to,nxt,w;
}ed[MAXN*2];
void add(int u,int v,int w)
{
    ed[++tot].to=v;
    ed[tot].from=u;
    ed[tot].w=w;
    ed[tot].nxt=head[u];
    head[u]=tot;
}
int dis[MAXN],near[MAXN],up=0,down=0,now;
int arr[MAXN*2],vis[MAXN];
int father[MAXN];
int fa(int data)
{
    if(father[data]==data)return data;
    return father[data]=fa(father[data]);
}
void spfa()
{
	for(int i = 1;i <= n;i++)dis[i] = 0x7fffffff/4;
    up=down=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=s;i++)
        arr[++down]=c[i],dis[c[i]]=0,near[c[i]]=c[i],vis[c[i]]=1;

    while(up<down)
    {
        now=arr[++up];
        vis[now]=0;
        for(int i=head[now];i;i=ed[i].nxt)
        {
            int v=ed[i].to;
            if(dis[now]+ed[i].w<dis[v])
            {
                dis[v]=dis[now]+ed[i].w;
                near[v]=near[now];
                if(!vis[v])
                {
                    vis[v]=1;
                    arr[++down]=v;
                }
            }
        }
    }
}
struct ak
{
    int x,y,b,num,ans;
}ask[MAXN];
bool cmp(ak a,ak b)
{
    return a.b<b.b;
}
bool cmp2(ak a,ak b)
{
    return a.num<b.num;
}
struct edge2
{
    int l,r,w;
}ed2[MAXN];
int edtot=0;
bool cmp3(edge2 a,edge2 b)
{
    return a.w<b.w;
}
int ans[MAXN]; 
int main()
{
    freopen("petrol.in","r",stdin);
    freopen("petrol2.out","w",stdout);
    n=read();
    s=read();
    m=read();
    for(int i = 1;i <= n;i++)father[i] = i;
    for(int i=1;i<=s;i++)
        c[i]=read(),isp[c[i]]=1,father[c[i]]=c[i];
    for(int i=1;i<=m;i++)
    {
        x=read();
        y=read();
        z=read();
        add(x,y,z);
        add(y,x,z);
    }
    //memset(dis,0x3f,sizeof(dis));
    spfa();
    for(int i=1;i<=m*2;i+=2)
    {
    	if(ed[i].from > n || ed[i].from < 1){
    		cout<<"nonono";
		}else if(ed[i].to > n || ed[i].to < 1){
			cout<<"nonono";
		}
        if(near[ed[i].from]!=near[ed[i].to])
        {
        	cout<<"add "<<edtot+1<<" in ";
        	cout<<near[ed[i].from]<<" "<<near[ed[i].to]<<endl;
            ed2[++edtot].l=near[ed[i].from];
            ed2[edtot].r=near[ed[i].to];
            ed2[edtot].w=dis[ed[i].from]+dis[ed[i].to]+ed[i].w;
        }else{
        	cout<<"skip"<<(i/2)+1<<endl;
		}
    }
    q=read();
    for(int i=1;i<=q;i++)
    {
        ask[i].x=read();
        ask[i].y=read();
        ask[i].b=read();
        ask[i].num=i;
    }
    sort(ed2+1,ed2+edtot+1,cmp3);
    sort(ask+1,ask+q+1,cmp);
    int kkk=1;
    for(int i=1;i<=q;i++)
    {
        while(ed2[kkk].w<=ask[i].b&&kkk<=edtot)
        {
            if(fa(ed2[kkk].l)!=fa(ed2[kkk].r))father[fa(ed2[kkk].l)]=ed2[kkk].r;
            if(i<=10000)cout<<ed2[kkk].w<<"compare"<<ask[i].b<<" ";
			kkk++;
            if(i<=10000)cout<<i<<":"<<kkk<<endl;
        }
        //cout<<(fa(ask[i].x)==fa(ask[i].y))<<endl;
        if(fa(ask[i].x)==fa(ask[i].y))ans[ask[i].num]=1;
        else ans[ask[i].num]=0;
    }
    for(int i=1;i<=q;i++)
    //    if(ans[i])puts("TAK");
    //    else puts("NIE");
    return 0;
}
/*
6 4 5
1 5 2 6
1 3 1
2 3 2
3 4 3
4 5 5
6 4 5
4
1 2 4
2 6 9
1 5 9
6 5 8

*/
