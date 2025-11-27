#include<bits/stdc++.h>
#define int long long 
#define re  register
#define in inline
#define max(a,b) ((a)>(b)?a:b)
#define min(a,b) ((a)<(b)?a:b)
using namespace std;
const int MAXN=1e4+10;
const int MAXM=2e5+19;
const int INF=0x3f3f3f3f3f;

in int read(){
    re int x=0,f=0;
	re char c=getchar();
    while(!isdigit(c)) f|=(c=='-'),c=getchar();
    while(isdigit(c)) x=(x<<3)+(x<<1)+c-'0',c=getchar();
    return f?-x:x;
}

int n,m,s,t,dis[MAXN],cur[MAXN];

struct edge{
    int u,v,w;
    int nx;
}e[MAXM];
int head[MAXN],tot = 2;

in void  add(int u,int v,int w){
    e[tot].u=u;
    e[tot].v=v;
    e[tot].w=w;
    e[tot].nx=head[u];
    head[u]=tot++;
}

bool bfs(){
//广搜一下测一下剩下点的深度，顺便找出增广路
    queue<int>q;
    memset(dis,-1,sizeof(dis));
    q.push(s);
    dis[s]=0;
    cur[s]=head[s];//cur是当前弧优化的宝贝
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=e[i].nx){
            int v=e[i].v;
            if(dis[v]==-1&&e[i].w){
            	if(e[i].w <= 0){
            		cout<<"no";
				}
                dis[v]=dis[u]+1;
                cur[v]=head[v];
                if(v==t){
                	cout<<"we get "<<v<<endl;
                    return 1;
                }
                q.push(v);
            }
        }
    }
    return 0;//不存在增广路了，可以结束le
}

int dfs(int u,int lim){
	cout<<"get "<<u<<" in "<<lim<<endl;
    if(u==t || lim == 0){
        return lim;
    }

    int flow=0;//从u点分出去的
    for(int i=cur[u];i;i=e[i].nx){
        cur[u]=i;//当前弧优化，很新对你来说，（走过就不再走了）
        int v=e[i].v;
        if(dis[v]==dis[u]+1&&e[i].w > 0){
        	cout<<u<<" to "<<v<<endl;
            int minf=dfs(v,min(e[i].w,lim-flow));//求要给v多少
//limit-flow给这条边能分的最多有多少
            e[i].w-=minf;
            e[i^1].w+=minf;
            flow+=minf;
            if(flow==lim){
                return flow;
            }
        }   
    }
    return flow;

}

int dinic(){
    int ans=0;
    while(bfs()){
    //  cout<<ans<<endl;
        ans+=dfs(s,INF);
        system("pause");
    }
    return ans;
}

signed main(){
    n=read();m=read();s=read();t=read();
    for(re int i=1;i<=m;i++){
        int u,v,w;
        u=read();v=read();w=read();
        add(u,v,w);add(v,u,0);
    }
    cout<<dinic()<<endl;
    return 0;
}
