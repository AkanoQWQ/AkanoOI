#include<bits/stdc++.h>
#define int long long
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
int t,n,q,op,x,y,col=0;
int head[MAXN],tot=0;
struct node
{
    int nxt,to;
}ed[MAXN<<1];
void add(int u,int v)
{
    ed[++tot].to=v;
    ed[tot].nxt=head[u];
    head[u]=tot;
}
int dep[MAXN],fa[MAXN],son[MAXN],siz[MAXN];
int dfn[MAXN],inv[MAXN],top[MAXN],dfnt=0;
void dfs1(int st,int fat,int de)
{
    dep[st]=de;
    siz[st]=1;
    fa[st]=fat;
    son[st]=st;
    for(int i=head[st];i;i=ed[i].nxt)
    {
        int v=ed[i].to;
        if(v==fat)continue;
        dfs1(v,st,de+1);
        if(son[st]==st)son[st]=v;
        else if(siz[v]>siz[son[st]])son[st]=v;
        siz[st]+=siz[v];
    }
}
void dfs2(int st,int fat,int tp)
{
    dfn[st]=++dfnt;
    top[st]=tp;
    inv[dfnt]=st;
    if(son[st]!=st)dfs2(son[st],st,tp);
    for(int i=head[st];i;i=ed[i].nxt)
    {
        int v=ed[i].to;
        if(v==fat||v==son[st])continue;
        dfs2(v,st,v);
    }
}
struct segtree
{
    struct node
    {
        int lc,rc,data,lazy,lco,rco;
    }no[MAXN<<4];
    void pushup(int st)
    {
        no[st].data=no[st<<1].data+no[(st<<1)|1].data;
        no[st].lco=no[st<<1].lco;
        no[st].rco=no[(st<<1)|1].rco;
        if((no[st<<1].rco==no[(st<<1)|1].lco)&&(no[st<<1].rco))no[st].data++;
        //cout<<"pushup..."<<" l:"<<no[st].lc<<" r:"<<no[st].rc<<" data:"<<no[st].data<<" lco:"<<no[st].lco<<" rco:"<<no[st].rco<<" l.r:"<<no[st<<1].rco<<" r.l:"<<no[(st<<1)|1].lco<<endl;
    }
    void build(int l,int r,int st)
    {
        no[st].lc=l;
        no[st].rc=r;
        no[st].lco=no[st].rco=no[st].data=no[st].lazy=0;
        if(l==r)return;
        int mid=(l+r)>>1;
        build(l,mid,st<<1);
        build(mid+1,r,(st<<1)|1);
        pushup(st);
    }
    void changep(int st,int co)
    {
        no[st].data=no[st].rc-no[st].lc;
        no[st].lco=no[st].rco=co;
        no[st].lazy=co;
        //cout<<"changep..."<<" l:"<<no[st].lc<<" r:"<<no[st].rc<<" data:"<<no[st].data<<" lco:"<<no[st].lco<<" rco:"<<no[st].rco<<endl;
    }
    void pushdown(int st)
    {
        if(!no[st].lazy)return;
        changep(st<<1,no[st].lazy);
        changep((st<<1)|1,no[st].lazy);
        no[st].lazy=0;
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
    int getsum(int l,int r,int st)
    {
        if(no[st].lc>r||no[st].rc<l)return -1;
        if(no[st].lc>=l&&no[st].rc<=r)
        {
            return no[st].data;
        }
        pushdown(st);
        int ret1=0,ret2=0;
        ret1+=getsum(l,r,st<<1);
        ret2+=getsum(l,r,(st<<1)|1);
        bool addret = 0;
        if((no[st<<1].rco==no[(st<<1)|1].lco)&&ret1!=-1&&ret2!=-1)addret = 1;
        int ret=0;
        if(ret1!=-1)ret+=ret1;
        if(ret2!=-1)ret+=ret2;
        return ret + addret;
    }
    int getco(int p,int st)
    {
        if(no[st].lc>p||no[st].rc<p)return 0;
        if(no[st].lc==no[st].rc&&no[st].lc==p)return no[st].lco;
        pushdown(st);
        return getco(p,st<<1)+getco(p,(st<<1)|1);
    }
}segt;
void change_xtoy(int x,int y,int co)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])x^=y^=x^=y;
        //cout<<"change..."<<dfn[top[x]]<<' '<<dfn[x]<<endl;
        segt.change(dfn[top[x]],dfn[x],1,co);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])x^=y^=x^=y;
    //cout<<"change:"<<dfn[top[x]]<<' '<<dfn[y]<<endl;
    segt.change(dfn[x],dfn[y],1,co);
}
int ask_xtoy(int x,int y)
{
    int ans=0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])x^=y^=x^=y;
        //cout<<"l:"<<dfn[top[x]]<<" r:"<<dfn[x]<<endl;
        ans+=segt.getsum(dfn[top[x]],dfn[x],1);
        if(segt.getco(dfn[fa[top[x]]],1)==segt.getco(dfn[top[x]],1))ans++;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])x^=y^=x^=y;
    //cout<<"l:"<<dfn[x]<<" r:"<<dfn[y]<<endl;
    ans+=segt.getsum(dfn[x],dfn[y],1);
    return ans;
}
signed main()
{
	//freopen("lonely1.in","r",stdin);
	//freopen("lonely1.ans","w",stdout);
    t=read();
    while(t--)
    {
        n=read();
        q=read();
        memset(head,0,sizeof(head));
        tot=dfnt=0;
        //memset(segt.no,0,sizeof(segt.no));
        for(int i=1;i<n;i++)
        {
            x=read();
            y=read();
            add(x,y);
            add(y,x);
        }
        dfs1(1,1,1);
        dfs2(1,1,1);
        segt.build(1,dfnt,1);
        /*for(int i=1;i<=n;i++)
            cout<<dfn[i]<<' ';
        cout<<endl;*/
        while(q--)
        {
            op=read();
            x=read();
            y=read();
            if(op==1)
            {
                change_xtoy(x,y,++col);
            }
            else if(op==2)
            {
                write(ask_xtoy(x,y));
                puts("");
            }
        }
    }
    return 0;
}
