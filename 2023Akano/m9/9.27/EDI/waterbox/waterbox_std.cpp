#include<bits/stdc++.h>
#define N 200005
using namespace std;
#define G if(++ip==ie)if(fread(ip=ibuf,1,LL,stdin))
const int LL=1<<21;
char ibuf[LL],*ie=ibuf+LL,*ip=ie-1;
inline char nc(void){G;return *ip;}
#define getchar nc
inline int read(void){
	char opt;int flag=1,res=0;
	while((opt=getchar())<'0');
	while(opt>='0'){res=(res<<3)+(res<<1)+opt-'0';opt=getchar();}
	return res*flag;
}
int Case,n,m,ans,tot,fa[N],f[N],g[N];
struct Node{int h,x,opt;inline char operator<(Node a)const{return h^a.h?h<a.h:opt<a.opt;}}p[N];
inline int getf(int x){return x==fa[x]?x:fa[x]=getf(fa[x]);}
inline void Solve(void){
	int i,x,y,z,fx,fy;n=read(),m=read();ans=0,tot=n+m-1;
	for(i=1;i<=n;++i)fa[i]=i,f[i]=g[i]=0;
	for(i=1;i<n;++i)p[i].h=read(),p[i].x=i,p[i].opt=0;
	for(i=1;i<=m;++i)x=read(),y=read(),z=read(),p[i+n-1]={y,x,z+1};
	for(sort(p+1,p+tot+1),i=1;i<=tot;++i){
		if(!p[i].opt){
			fx=getf(p[i].x),fy=getf(p[i].x+1);
			f[fx]=max(f[fx]+f[fy],g[fa[fy]=fx]+=g[fy]);
		}
		else if(p[i].opt==1)++f[getf(p[i].x)];
		else fx=getf(p[i].x),f[fx]=max(f[fx],++g[fx]);
	}for(i=1;i<=n;++i)ans=max(ans,f[getf(i)]);
	printf("%d\n",ans);
}
int main(void){
	Case=read();
	while(Case--)Solve();
	return 0;
}
