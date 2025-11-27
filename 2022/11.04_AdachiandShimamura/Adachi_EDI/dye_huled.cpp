#include<bits/stdc++.h>
#define MAXN 100010
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
struct edge
{
    int to,nxt;
}ed[MAXN<<1];
int head[MAXN],tot=0;
void add(int u,int v)
{
    ed[++tot].to=v;
    ed[tot].nxt=head[u];
    head[u]=tot;
}
int n,m,w[MAXN],x,y,z,ttot=0;
char op;
int siz[MAXN],son[MAXN],fa[MAXN],dfn[MAXN]={0},top[MAXN],dep[MAXN];
int inv[MAXN];//dfn为i的节点的编号
struct segtree
{
    struct node
    {
        int lc,rc,lazy,lco,rco,num;
    }no[MAXN<<2];
    void changep(int st,int co)
    {
        no[st].lco=no[st].rco=co;
        no[st].num=1;
        no[st].lazy=co;
    }
    void pushup(int st)
    {
        no[st].num=no[st<<1].num+no[(st<<1)|1].num;
        no[st].lco=no[st<<1].lco;
        no[st].rco=no[(st<<1)|1].rco;
        if(no[st<<1].rco==no[(st<<1)|1].lco)no[st].num--;
    }
    void pushdown(int st)
    {
        if(!no[st].lazy)return;
        no[st<<1].lazy=no[(st<<1)|1].lazy=no[st].lazy;
        changep(st<<1,no[st].lazy);
        changep((st<<1)|1,no[st].lazy);
        no[st].lazy=0;
    }
    void build(int l,int r,int st)
    {
        no[st].lc=l;
        no[st].rc=r;
        no[st].lazy=0;
        if(l==r)
        {
            no[st].lco=no[st].rco=w[inv[l]];
            no[st].num=1;
            return;
        }
        int mid=(l+r)>>1;
        build(l,mid,st<<1);
        build(mid+1,r,(st<<1)|1);
        pushup(st);
        cout<<"l:"<<l<<" r:"<<r<<" lco:"<<no[st].lco<<" rco:"<<no[st].rco<<" num:"<<no[st].num<<endl;
    }
    void change(int l,int r,int st,int co)
    {
        if(no[st].lc>r||no[st].rc<l)return;
        if(no[st].lc>=l&&no[st].rc<=r)
        {
            changep(st,co);
            return;
        }
        pushdown(st);
        change(l,r,st<<1,co);
        change(l,r,(st<<1)|1,co);
        pushup(st);
    }
    int ask(int l,int r,int st)
    {
        if(no[st].lc>r||no[st].rc<l)return 0;
        if(no[st].lc>=l&&no[st].rc<=r)return no[st].num;
        pushdown(st);
        int lans=ask(l,r,st<<1);
        int rans=ask(l,r,(st<<1)|1);
        if(lans&&rans&&no[st<<1].rco==no[(st<<1)|1].lco)return lans+rans-1;
        else return lans+rans;
    }
}segt;
void dfs1(int st,int fat,int de)
{
    siz[st]=1;
    fa[st]=fat;
    son[st]=st;
    dep[st]=de;
    for(int i=head[st];i;i=ed[i].nxt)
    {
        int v=ed[i].to;
        if(v==fat)continue;
        dfs1(v,st,de+1);
        siz[st]+=siz[v];
        if(son[st]==st)son[st]=v;
        else if(siz[son[st]]<siz[v])son[st]=v;
    }
}
void dfs2(int st,int fat,int tp)
{
    top[st]=tp;
    dfn[st]=++ttot;
    inv[ttot]=st;
    if(!dfn[son[st]])dfs2(son[st],st,tp);
    for(int i=head[st];i;i=ed[i].nxt)
    {
        int v=ed[i].to;
        if(v==fat||v==son[st])continue;
        dfs2(v,st,v);
    }
}
void change_xtoy(int x,int y,int co)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])x^=y^=x^=y;
        segt.change(dfn[top[x]],dfn[x],1,co);
        x=fa[top[x]];
    }
    if(dep[x]<dep[y])x^=y^=x^=y;
    segt.change(dfn[y],dfn[x],1,co);
}
int ask_xtoy(int x,int y)
{
    int ans=0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])x^=y^=x^=y;
        ans+=segt.ask(dfn[top[x]],dfn[x],1);
        if(w[top[x]]==w[fa[top[x]]])ans--;
        x=fa[top[x]];
    }
    if(dep[x]<dep[y])x^=y^=x^=y;
    ans+=segt.ask(dfn[y],dfn[x],1);
    return ans;
}
/*
void display()
{
    for(int i=1;i<=n;i++)
        cout<<segt.ask(dfn[i],dfn[i],1)<<' ';
    cout<<endl<<endl;
}*/
int main()
{
    freopen("dye.in","r",stdin);
    //freopen("dye.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
        w[i]=read();
    for(int i=1;i<n;i++)
    {
        x=read();
        y=read();
        add(x,y);
        add(y,x);
    }
    dfs1(1,1,0);
    dfs2(1,1,1);
    segt.build(1,ttot,1);
    //cout<<ask_xtoy(1,3)<<endl;
    //change_xtoy(1,3,1);
    //cout<<ask_xtoy(1,3);
    for(int i = 1;i <= n;i++){
    	segt.change(dfn[i],dfn[i],1,w[i]);
	}
    for(int i=1;i<=m;i++)
    {
        cin>>op;
        x=read();
        y=read();
        if(op=='C')
        {
            z=read();
            change_xtoy(x,y,z);
        }
        else if(op=='Q')
        {
            printf("%d\n",ask_xtoy(x,y));
        }
        //display();
    }
    return 0;
}
/*
6 5
2 2 1 2 1 1
1 2
1 3
2 4
2 5
2 6
Q 3 5
C 2 1 1
Q 3 5
C 5 1 2
Q 3 5

10 10
1 1 1 2 2 1 3 3 1 1
1 2
1 3
1 6
1 5
1 4
4 8
4 7
7 9
9 10
Q 1 7

*/
