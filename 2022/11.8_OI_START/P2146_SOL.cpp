#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,k=0,x,head[maxn],q,deep[maxn],father[maxn],size[maxn];
int tid[maxn],top[maxn],son[maxn],tidnum=0,pos[maxn];char s[15];
struct node
{
    int to,next;
} edge[maxn<<1];
struct Node
{
    int left,right,flag,sum;
} tree[maxn<<2];
void add(int u,int v)
{
    edge[++k].to=v;
    edge[k].next=head[u];
    head[u]=k;
}
int read()
{
    int x=0;char ch=getchar();
    while(ch<48||ch>57) ch=getchar();
    while(ch>=48&&ch<=57) x=x*10+ch-48,ch=getchar();
    return x;
}
void dfs1(int x,int fa,int depth)
{
    size[x]=1;father[x]=fa;deep[x]=depth;
    for(int i=head[x];i;i=edge[i].next)
    {
        if(edge[i].to==fa) continue;
        dfs1(edge[i].to,x,depth+1);
        size[x]+=size[edge[i].to];
        if(!son[x]||size[edge[i].to]>size[son[x]]) son[x]=edge[i].to;
    }
}
void dfs2(int x,int tp)
{
    tid[x]=++tidnum;pos[tid[x]]=x;top[x]=tp;
    if(!son[x]) return;dfs2(son[x],tp);
    for(int i=head[x];i;i=edge[i].next)
    {
        if(edge[i].to!=son[x]&&edge[i].to!=father[x])
            dfs2(edge[i].to,edge[i].to);
    }
}
void build(int id,int l,int r)
{
    tree[id].left=l;tree[id].right=r;
    tree[id].sum=0;tree[id].flag=-1;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(id<<1,l,mid);build(id<<1|1,mid+1,r);
    return;
}
void downdata(int id)
{
    tree[id<<1].sum=(tree[id<<1].right-tree[id<<1].left+1)*tree[id].flag;
    tree[id<<1|1].sum=(tree[id<<1|1].right-tree[id<<1|1].left+1)*tree[id].flag;
    tree[id<<1].flag=tree[id<<1|1].flag=tree[id].flag;
    tree[id].flag=-1;
}
void update(int id,int l,int r,int val)
{
	cout<<"vis "<<id<<endl;
	if(id == 2168){
		cout<<"compare "<<tree[id].left<<"to"<<tree[id].right<<" "<<l<<"to"<<r;
	}
    if(tree[id].right<l||tree[id].left>r) return;
    if(id*2 == 2168){
    	cout<<tree[2168].sum<<endl;
    	cout<<tree[id].right<<" "<<l<<endl;
    	cout<<tree[id].flag<<endl;
    	while(1);
	}
    if(tree[id].right<=r&&tree[id].left>=l)
    {
        tree[id].sum=(tree[id].right-tree[id].left+1)*val;
        tree[id].flag=val;
//        std::cout<<id<<" end into "<<tree[id].sum<<endl;
        return;
    }
    if(tree[id].flag!=-1) downdata(id);
    cout<<id<<" mid "<<(tree[id].right + tree[id].left) / 2<<" "<<tree[id].right <<" "<< tree[id].left<<endl;
    update(id<<1,l,r,val);update(id<<1|1,l,r,val);
    tree[id].sum=tree[id<<1].sum+tree[id<<1|1].sum;
    cout<<id<<" ret "<<tree[id].sum<<"bec "<<id*2<<","<<id*2+1<<endl;
//    cout<<tree[id*2].sum<<" add "<<tree[id*2+1].sum<<endl;
  //  cout<<"mid objl"<<tree[id].left<<" and "<<tree[id].right<<" "<<l<<endl;
    return;
}
void change(int u,int v,int val)
{
    while(top[u]!=top[v])
    {
        if(deep[top[u]]<deep[top[v]]) std::swap(u,v);
        update(1,tid[top[u]],tid[u],val);
        u=father[top[u]];
    }
    if(deep[u]>deep[v]) std::swap(u,v);
    update(1,tid[u],tid[v],val);
    return;
}
int main()
{
	freopen("P2146.in","r",stdin);
    n=read();
    for(int i=2;i<=n;i++)
    {
        x=read();x++;
        add(x,i);
    }
    dfs1(1,1,1);dfs2(1,1);
    q=read();build(1,1,tidnum);
    for(int i=1;i<=q;i++)
    {
        scanf("%s",s);
        x=read();x++;
        int t1=tree[1].sum;
        if(s[0]=='i')
        {
            change(1,x,1);
            int t2=tree[1].sum;
            printf("%d\n",abs(t2-t1));
        }
        if(s[0]=='u')
        {
            update(1,tid[x],tid[x]+size[x]-1,0);
            int t2=tree[1].sum;
            printf("%d\n",abs(t1-t2));
        }
    }
    return 0;
}
