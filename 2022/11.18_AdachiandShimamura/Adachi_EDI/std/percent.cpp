#include<bits/stdc++.h>
using namespace std;
template <typename T>inline void re(T &x) {
	x=0;
	int f=1;
	char c=getchar();
	for(; !isdigit(c); c=getchar()) if(c=='-') f=-f;
	for(; isdigit(c); c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	x*=f;
	return;
}
template <typename T>void wr(T x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10^'0');
	return;
}
const int N=4e5+5,M=20;
char s[N];
int n,q;
int stk[N],top;
int stk0[N],top0;
int cnt;
vector<int> to[N];
int t[N];
int rt[N];
int pare[N][M];
int mins[N][M][2][2];
int snum[N];
int dep[N];
int rk[N];
void dfs(int x) {
	int num=0;
	for(auto v:to[x]) {
		++num;
		rk[v]=num;
		dep[v]=dep[x]+1;
		rt[v]=rt[x];
		pare[v][0]=x;
		mins[v][0][0][0]=min(1+(num-1)*2,3+(snum[x]-num)*2);
		mins[v][0][0][1]=min(2+(num-1)*2,2+(snum[x]-num)*2);
		mins[v][0][1][0]=min(2+(num-1)*2,2+(snum[x]-num)*2);
		mins[v][0][1][1]=min(3+(num-1)*2,1+(snum[x]-num)*2);
		for(int i=1; pare[v][i-1]; ++i) {
			pare[v][i]=pare[pare[v][i-1]][i-1];
			mins[v][i][0][0]=min(mins[v][i-1][0][0]+mins[pare[v][i-1]][i-1][0][0],mins[v][i-1][0][1]+mins[pare[v][i-1]][i-1][1][0]);
			mins[v][i][0][1]=min(mins[v][i-1][0][0]+mins[pare[v][i-1]][i-1][0][1],mins[v][i-1][0][1]+mins[pare[v][i-1]][i-1][1][1]);
			mins[v][i][1][0]=min(mins[v][i-1][1][0]+mins[pare[v][i-1]][i-1][0][0],mins[v][i-1][1][1]+mins[pare[v][i-1]][i-1][1][0]);
			mins[v][i][1][1]=min(mins[v][i-1][1][0]+mins[pare[v][i-1]][i-1][0][1],mins[v][i-1][1][1]+mins[pare[v][i-1]][i-1][1][1]);
		}
		dfs(v);
	}
}
inline int fnd(int u,int tu,int v,int tv) {
	int up_u[2]= {0,0};
	int up_v[2]= {0,0};
	if(dep[u]<dep[v]) swap(u,v),swap(tu,tv);
	up_u[tu^1]=1;
	up_v[tv^1]=1;
	if(rt[u]==rt[v]) {
		for(int i=M-1; i>=0; --i) {
			if(dep[pare[u][i]]>=dep[v]) {
				int t0=min(up_u[0]+mins[u][i][0][0],up_u[1]+mins[u][i][1][0]);
				int t1=min(up_u[0]+mins[u][i][0][1],up_u[1]+mins[u][i][1][1]);
				up_u[0]=t0;
				up_u[1]=t1;
				u=pare[u][i];
			}
		}
		if(u==v) return up_u[tv];
		for(int i=M-1; i>=0; --i) {
			if(pare[u][i]!=pare[v][i]) {
				{
					int t0=min(up_u[0]+mins[u][i][0][0],up_u[1]+mins[u][i][1][0]);
					int t1=min(up_u[0]+mins[u][i][0][1],up_u[1]+mins[u][i][1][1]);
					up_u[0]=t0;
					up_u[1]=t1;
					u=pare[u][i];
				}
				{
					int t0=min(up_v[0]+mins[v][i][0][0],up_v[1]+mins[v][i][1][0]);
					int t1=min(up_v[0]+mins[v][i][0][1],up_v[1]+mins[v][i][1][1]);
					up_v[0]=t0;
					up_v[1]=t1;
					v=pare[v][i];
				}
			}
		}
		int ans;
		if(u<v) ans=(rk[v]-rk[u]-1)*2+up_u[1]+up_v[0]+1;
		else ans=(rk[u]-rk[v]-1)*2+up_v[1]+up_u[0]+1;
		{
			int t0=min(up_u[0]+mins[u][0][0][0],up_u[1]+mins[u][0][1][0]);
			int t1=min(up_u[0]+mins[u][0][0][1],up_u[1]+mins[u][0][1][1]);
			up_u[0]=t0;
			up_u[1]=t1;
		}
		{
			int t0=min(up_v[0]+mins[v][0][0][0],up_v[1]+mins[v][0][1][0]);
			int t1=min(up_v[0]+mins[v][0][0][1],up_v[1]+mins[v][0][1][1]);
			up_v[0]=t0;
			up_v[1]=t1;
		}
		return min(ans,min(up_u[0]+up_v[0],up_u[1]+up_v[1]));
	}
	for(int i=M-1; i>=0; --i) {
		if(pare[u][i]) {
			int t0=min(up_u[0]+mins[u][i][0][0],up_u[1]+mins[u][i][1][0]);
			int t1=min(up_u[0]+mins[u][i][0][1],up_u[1]+mins[u][i][1][1]);
			up_u[0]=t0;
			up_u[1]=t1;
			u=pare[u][i];
		}
	}
	for(int i=M-1; i>=0; --i) {
		if(pare[v][i]) {
			int t0=min(up_v[0]+mins[v][i][0][0],up_v[1]+mins[v][i][1][0]);
			int t1=min(up_v[0]+mins[v][i][0][1],up_v[1]+mins[v][i][1][1]);
			up_v[0]=t0;
			up_v[1]=t1;
			v=pare[v][i];
		}
	}
	if(u<v) return (rk[v]-rk[u]-1)*2+up_u[1]+up_v[0]+1;
	return (rk[u]-rk[v]-1)*2+up_v[1]+up_u[0]+1;
}
signed main() {
	freopen("percent.in","r",stdin);
	freopen("percent.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	int br=0;
	for(int i=1; i<=n; ++i) {
		if(s[i]=='(') {
			stk[++top]=i;
			t[i]=++cnt;
			if(top==1) rk[cnt]=++br;
		} else {
			t[i]=t[stk[top]];
			while(top0&&stk0[top0]>stk[top]) to[t[stk[top]]].push_back(t[stk0[top0--]]),++snum[t[stk[top]]];
			stk0[++top0]=stk[top--];
		}
	}
	for(int i=1; i<=cnt; ++i) reverse(to[i].begin(),to[i].end());
	for(int i=1; i<=cnt; ++i) {
		if(!rt[i]) {
			dep[i]=1;
			rt[i]=i;
			dfs(i);
		}
	}
	re(q);
	while(q--) {
		int l,r;
		re(l),re(r);
		wr(fnd(t[l],s[l]==')',t[r],s[r]==')'));
		putchar('\n');
	}
	return 0;
}
