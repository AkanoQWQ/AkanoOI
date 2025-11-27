#include <bits/stdc++.h>
using namespace std;
const int Maxn=1e3+5;
inline int max(int a,int b){return a>b?a:b;}
inline int R()
{
	char c;int res,sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1;res=c-'0';
	while((c=getchar())>='0'&&c<='9') res=res*10+c-'0';
	return res*sign;
}
int n,m,First[Maxn],to[Maxn*2],Next[Maxn*2],dp[Maxn*2],cnt,ans[Maxn],M=1<<30,num;
inline void add(int z,int y)
{
	Next[++cnt]=First[z];
	First[z]=cnt;
	to[cnt]=y;
}
int dfs(int pos,int father ,int fr)
{
	if(fr&&dp[fr]) return dp[fr];
	int res=0;
	priority_queue<int>q;
	for(int k=First[pos];k;k=Next[k])
	{
		if(to[k]==father) continue;
		q.push(dfs(to[k],pos,k));
	}
	for(int i=1;!q.empty();i++,q.pop())
		res=max(res,q.top()+i);
	return dp[fr]=res;
}
int main()
{
	n=R();
	int x;
	for(int i=2;i<=n;i++)
	{
		x=R();
		add(i,x);
		add(x,i);
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=dfs(i,0,0);
		if(ans[i]<M)
			M=ans[i];
	}
	printf("%d\n",M);
	for(int i=1;i<=n;i++)
		if(ans[i]==M) printf("%d ",i);
	return 0;
}

