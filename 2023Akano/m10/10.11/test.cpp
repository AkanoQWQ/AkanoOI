#include<bits/stdc++.h>
#define fls false
#define tre true
#define que queue
#define stk stack
#define vct vector
#define priq priority_queue
#define st struct
#define asdf read()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef string si;
typedef bool bl;
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57)
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57)
		x=x*10+ch-48,ch=getchar();
	return x*f;
}
#define N 131
#define M
ll n,ru[N],a;
vct<ll>g[N];
que<ll>q;
int main()
{
	//ios::sync_with_stdio(fls);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		while((a=asdf)!=0)
		{
			g[i].push_back(a);
			ru[a]++;
		}
	for(int i=1;i<=n;i++)
		if(!ru[i])
			q.push(i);
	while(q.size())
	{
		ll now=q.front();
		q.pop();
		cout<<now<<' ';
		for(int i=0;i<g[now].size();i++)
			if(!(--ru[g[now][i]]))
				q.push(g[now][i]);
	}
	return 114514*0;
}
