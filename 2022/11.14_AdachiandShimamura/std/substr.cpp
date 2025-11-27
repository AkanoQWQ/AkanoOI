#include<bits/stdc++.h>
#define S ((1<<n)-1)
using namespace std;
const int N=1005,M=1<<12;
int n,tot=0,trie[N][26],state[N],fail[N],ans[N*M];
struct node{
    int state,u,lst;
    int ch;
}q[N*M],now,nxt;
bool vis[N][M];
char ss[105];
void build_trie(int num,char *s){
    int u=0,v,len=strlen(s+1);
    for(int i=1;i<=len;i++){
        v=s[i]-'A';
        if(!trie[u][v]) trie[u][v]=++tot;
        u=trie[u][v];
    }
    state[u]|=1<<(num-1);
    return;
}
void build_fail()
{
    int u=0;queue<int> q;
    for(int i=0;i<26;i++) if(trie[u][i]) q.push(trie[u][i]);
	while(!q.empty()){
        u=q.front();q.pop();
        cout<<u<<endl;
        for(int i=0;i<26;i++){
            if(trie[u][i])
            {
                fail[trie[u][i]]=trie[fail[u]][i];
                state[trie[u][i]]|=state[fail[trie[u][i]]];
                q.push(trie[u][i]);
            }
            else trie[u][i]=trie[fail[u]][i];
        }
    }
    return;
}
void getans(int x)
{
    int cnt=0;
    for(int i=x;i;i=q[i].lst)
    ans[++cnt]=q[i].ch;
    for(int i=cnt-1;i>=1;i--) putchar(ans[i]+'A');
    return;
}
void bfs()
{
    int h=1,t=0;
    now.u=0;now.state=0;now.lst=0;
    q[++t]=now;
    while(h<=t)
    {
        now=q[h++];
        if(now.state==S) {getans(h-1);return;}
        for(int i=0;i<26;i++)
        {
            nxt.ch=i;nxt.u=trie[now.u][i];nxt.state=now.state|state[nxt.u];nxt.lst=h-1;
            if(!vis[nxt.u][nxt.state])
            {
                vis[nxt.u][nxt.state]=true;
                q[++t]=nxt;
            }
        }
    }
    return;
}
int main()
{
    //freopen("substr.in", "r", stdin);
    //freopen("substr.out", "w", stdout);	
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",ss+1),build_trie(i,ss);
    build_fail();bfs();
    return 0;
}
