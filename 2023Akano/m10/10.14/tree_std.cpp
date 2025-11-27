#include<bits/stdc++.h>
#define ci const int
#define ls k<<1
#define rs k<<1|1
using namespace std;
char buf[1<<20],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
int read(){int res(0);char ch(getchar());while(ch<48||ch>57)ch=getchar();while(ch>=48&&ch<=57)res=(res<<1)+(res<<3)+(ch^48),ch=getchar();return res;}
ci N=2e5+5,M=N<<3,inf=1e7;
int n,t,lm,ans[N],col[N];
vector<int>g[N];
int dis[N];
namespace sol1{//求出到每个点的最远距离 
	int dn[N],up[N];
	void Init(){
		for(int i=1;i<=n;++i)dn[i]=up[i]=-inf;
	}
	int l[M],r[M];
	struct D{
		int dis,len;
		D(int dis=0,int len=0):dis(dis),len(len){}
	}s[M],tmp[N<<1];
	D operator + (D A,D B){
		return D(max(A.dis+B.len,B.dis),A.len+B.len);
	}
	void upd(ci k){
		s[k]=s[ls]+s[rs];
	}
	void build(ci k,ci L,ci R){
		l[k]=L,r[k]=R;
		if(L==R){
			s[k]=tmp[L];
			return;
		}
		ci mid=L+R>>1;
		build(ls,L,mid),build(rs,mid+1,R),upd(k);
	}
	D qry(ci k,ci L,ci R){
		if(L<=l[k]&&r[k]<=R)return s[k];
		if(R<=r[ls])return qry(ls,L,R);
		if(L>=l[rs])return qry(rs,L,R);
		return qry(ls,L,R)+qry(rs,L,R);
	}
	void dfs(ci x){
		if(col[x]==1)dn[x]=up[x]=0;
		for(int y:g[x])dfs(y),dn[x]=max(dn[x],dn[y]+1);
	}
	void calc(ci x){
		int mx=-inf,mx2=-inf,id=0;
		for(int y:g[x])
			if(dn[y]>mx)mx2=mx,mx=dn[y],id=y;
		else if(dn[y]>mx2)mx2=dn[y];
		for(int y:g[x]){
			if(y==id)up[y]=max(up[y],mx2+2);
			else up[y]=max(up[y],mx+2);
			up[y]=max(up[y],up[x]+1);
			calc(y);
		}
	}
	void Work(){
		Init();
		for(int i=1;i<=t;++i)dfs(i);
		if(t>1){
			for(int i=1;i<=t;++i)tmp[i]=tmp[i+t]=D(dn[i],1);
			build(1,1,t<<1);
			for(int i=1;i<=t;++i)up[i]=max(up[i],qry(1,i+t-lm,i+t-1).dis+1);
		}
		if(t>2){
			for(int i=1;i<=t;++i)tmp[t-i+1]=tmp[t-i+1+t]=D(dn[i],1);
			build(1,1,t<<1);
			for(int i=1;i<=t;++i)up[i]=max(up[i],qry(1,t-i+1+t-(lm-(t%2==0)),t-i+1+t-1).dis+1);
		}
		for(int i=1;i<=t;++i)calc(i);
		for(int i=1;i<=n;++i)dis[i]=max(up[i],dn[i]);
	}
}
namespace sol2{//求解答案 
	struct pr{//val表示还剩的距离 
		int val,cnt;
		pr(int val=0,int cnt=0):val(val),cnt(cnt){}
	}dn[N],up[N];
	int ans;
	void Init(){
		ans=0;
		for(int i=1;i<=n;++i)dn[i]=up[i]=pr(inf,0);
	}
	int l[M],r[M];
	pr operator + (pr A,pr B){
		if(A.val<B.val)return A;
		if(B.val<A.val)return B;
		return pr(A.val,A.cnt+B.cnt);
	}
	pr add(pr A,ci v){
		return pr(A.val+v,A.cnt);
	}
	struct D{
		pr v;int len;
		D(pr v=pr(0,0),int len=0):v(v),len(len){}
	}s[M],tmp[N<<1];
	D operator + (D A,D B){
		return D(add(A.v,-B.len)+B.v,A.len+B.len);
	}
	void upd(ci k){
		s[k]=s[ls]+s[rs];
	}
	void build(ci k,ci L,ci R){
		l[k]=L,r[k]=R;
		if(L==R){
			s[k]=tmp[L];
			return;
		}
		ci mid=L+R>>1;
		build(ls,L,mid),build(rs,mid+1,R),upd(k);
	}
	D qry(ci k,ci L,ci R){
		if(L<=l[k]&&r[k]<=R)return s[k];
		if(R<=r[ls])return qry(ls,L,R);
		if(L>=l[rs])return qry(rs,L,R);
		return qry(ls,L,R)+qry(rs,L,R);
	}
	void dfs(ci x){
		if(col[x]==0)dn[x]=pr(dis[x],1);
		for(int y:g[x])dfs(y),dn[x]=dn[x]+add(dn[y],-1);
	}
	void calc(ci x){
		if(col[x]==1){
			pr tmp=up[x]+dn[x];
			if(tmp.val==0)ans=max(ans,tmp.cnt);
		}
		else up[x]=up[x]+pr(dis[x],1);
		int mn=inf;
		for(int y:g[x])mn=min(mn,dn[y].val);
		pr mx(inf,0),mx2(inf,0);
		for(int y:g[x])
			if(dn[y].val==mn)mx=mx+dn[y];
		else mx2=mx2+dn[y];
		for(int y:g[x]){
			if(dn[y].val==mn){
				if(mx.cnt==dn[y].cnt)up[y]=up[y]+add(mx2,-2);
				else up[y]=up[y]+add(pr(mx.val,mx.cnt-dn[y].cnt),-2);
			}
			else up[y]=up[y]+add(mx,-2);
			up[y]=up[y]+add(up[x],-1);
			calc(y);
		}
	}
	void Work(){
		Init();
		for(int i=1;i<=t;++i)dfs(i);
		if(t>1){
			for(int i=1;i<=t;++i)tmp[i]=tmp[i+t]=D(dn[i],1);
			build(1,1,t<<1);
			for(int i=1;i<=t;++i)up[i]=up[i]+add(qry(1,i+t-lm,i+t-1).v,-1);
		}
		if(t>2){
			for(int i=1;i<=t;++i)tmp[t-i+1]=tmp[t-i+1+t]=D(dn[i],1);
			build(1,1,t<<1);
			for(int i=1;i<=t;++i)up[i]=up[i]+add(qry(1,t-i+1+t-(lm-(t%2==0)),t-i+1+t-1).v,-1);
		}
		for(int i=1;i<=t;++i)calc(i);
		printf("%d\n",ans);
	}
}
void Init(){
	for(int i=1;i<=n;++i)g[i].clear(),dis[i]=-inf;
}
void Work(){
	n=read(),t=read(),lm=t>>1;
	Init();
	for(int i=t+1;i<=n;++i)g[read()].push_back(i);
	for(int i=1;i<=n;++i)col[i]=read();
	sol1::Work(),sol2::Work();
} 
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T=read();
	while(T--)Work();
	return 0;
}
