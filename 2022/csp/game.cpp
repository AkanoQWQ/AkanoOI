#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e5+100;
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
ll A[N],B[N],n,m,q,l1,r1,l2,r2,maxx1[N<<2],minn1[N<<2],maxx2[N<<2],minn2[N<<2];
void build1(int x,int l,int r)
{
	minn1[x]=1e18;
	if(l==r)
	{
		minn1[x]=maxx1[x]=A[l];
		return ;
	}
	int mid=(l+r)>>1;
	build1(x<<1,l,mid);
	build1(x<<1|1,mid+1,r);
	maxx1[x]=max(maxx1[x<<1],maxx1[x<<1|1]);
	minn1[x]=min(minn1[x<<1],minn1[x<<1|1]);
	return ;
}
void build2(int x,int l,int r)
{
	minn2[x]=1e18;
	if(l==r)
	{
		minn2[x]=maxx2[x]=B[l];
		return ;
	}
	int mid=(l+r)>>1;
	build2(x<<1,l,mid);
	build2(x<<1|1,mid+1,r);
	maxx2[x]=max(maxx2[x<<1],maxx2[x<<1|1]);
	minn2[x]=min(minn2[x<<1],minn2[x<<1|1]);
	return ;
}
pair<ll,ll> ask1(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&qr>=r)return make_pair(maxx1[x],minn1[x]);
	pair<ll,ll>res1,res2,res3;
	res1.first=res2.first=res3.first=0,res1.second=res2.second=res3.second=1e18;
	int mid=(l+r)>>1;
	if(ql<=mid)res2=ask1(x<<1,l,mid,ql,qr);
	if(qr>mid)res3=ask1(x<<1|1,mid+1,r,ql,qr);
	res1.first=max(res2.first,res3.first);
	res1.second=min(res2.second,res3.second);
	return res1;
}
pair<ll,ll> ask2(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&qr>=r)return make_pair(maxx2[x],minn2[x]);
	pair<ll,ll>res1,res2,res3;
	res1.first=res2.first=res3.first=0,res1.second=res2.second=res3.second=1e18;
	int mid=(l+r)>>1;
	if(ql<=mid)res2=ask2(x<<1,l,mid,ql,qr);
	if(qr>mid)res3=ask2(x<<1|1,mid+1,r,ql,qr);
	res1.first=max(res2.first,res3.first);
	res1.second=min(res2.second,res3.second);
	return res1;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    read(n),read(m),read(q);
    for(int i=1;i<=n;++i)read(A[i]);
    for(int i=1;i<=m;++i)read(B[i]);
    if(n<=3000)
    {
    	for(int i=1;i<=q;++i)
        {
    	read(l1),read(r1),read(l2),read(r2);
    	ll ansz=-1e18-10;
    	for(int j=l1;j<=r1;++j)
    	{
    		ll com=A[j];ll ans=1e18+10;
    		for(int k=l2;k<=r2;++k)
    		{
    			if(com*B[k]<ans)
    			ans=com*B[k];
			}
			ansz=max(ansz,ans);
		}
		wr(ansz),putchar('\n');
	    }
	}
	else
	{
		build1(1,1,n);
		build2(1,1,m);
		for(int i=1;i<=q;++i)
		{
			read(l1),read(r1),read(l2),read(r2);
			pair<ll,ll>Aans,Bans;
			Aans=ask1(1,1,n,l1,r1),Bans=ask2(1,1,m,l2,r2);
			ll anss1,anss2,anss3,anss4;
			if(Aans.second>0&&Bans.second>0)
			{
			   wr(Aans.first*Bans.second);
			   puts("");
			   continue;
			}
			anss1=Aans.first*Bans.first;
			anss3=Aans.first*Bans.second;
			anss2=Aans.second*Bans.second;
			anss4=Aans.second*Bans.first;
			wr(max(min(anss1,anss3),min(anss2,anss4))),putchar('\n');
		}
	}
	return 0;
}
/*
1 s
512 mb
4 3 2
0 1 2 2
3 4 5
1 3 1 2
2 3 2 2
*/
