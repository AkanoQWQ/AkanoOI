#pragma GCC diagnostic error "-std=c++2a"
#pragma GCC optimize(2)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;
const int Mxdt=100000;
char gc(){
//	return getchar();
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
char pc(char c,bool opt){
//	return (opt||putchar(c)),0;
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (opt||(*p1++=c,p1==p2))&&(fwrite(buf,1,p1-buf,stdout),p1=buf),0; 
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10^48,0);
}
void printnum(int x,char c){
	if(x<0)pc('-',0),x=-x;
	print(x);pc(c,0);
}
int n,Q,x,y,p[100005],r[100005],c[100005],top,st[100005],rd[100005];long long ans;
int num[100005];bool cmp(const int&a,const int&b){return p[a]<p[b];}
int h[100005],cnt,Time,dfn[100005],low[100005],instack[100005],bl[100005],SCC;
struct edge{int to,next;}e[200005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
void tarjan(int x){
	int i,y;dfn[x]=low[x]=++Time;
	st[++top]=x;instack[x]=1;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;
		if(!dfn[y]){tarjan(y);low[x]=min(low[x],low[y]);}
		else if(instack[y])low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]){
		++SCC;
		do{
			y=st[top--];
			instack[y]=0;bl[y]=SCC;
		}while(y!=x);
	}
}
struct set{
	priority_queue<int>p1,p2;
	void insert(int x){p1.push(-x);}
	void erase(int x){p2.push(-x);}
	int begin(){
		while(!p2.empty()&&p1.top()==p2.top())p1.pop(),p2.pop();
		if(p1.empty())return 0;return -p1.top();
	}
}s[100005];
int main(){
	freopen("score/score2.in","r",stdin);
	freopen("score.ans","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		p[i]=read();r[i]=read();c[i]=read();num[i]=i;
	}
	sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n;++i){
		while(top&&p[st[top]]>=p[num[i]]-r[num[i]]){
			add(num[i],st[top]);--top;
		}
		st[++top]=num[i];
	}
	top=0;
	for(int i=n;i;--i){
		while(top&&p[st[top]]<=p[num[i]]+r[num[i]]){
			add(num[i],st[top]);--top;
		}
		st[++top]=num[i];
	}
	for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i);
	for(int x=1;x<=n;++x){
		for(int i=h[x];i;i=e[i].next){
			int y=e[i].to;
			if(bl[x]!=bl[y])++rd[bl[y]];
		}
	}
	for(int i=1;i<=n;++i){
		if(!rd[bl[i]]){
			s[bl[i]].insert(c[i]);
		}
	}
	for(int i=1;i<=SCC;++i){
		if(!rd[i]){
			cerr<<"add "<<s[i].begin()<<endl;
			ans+=s[i].begin();
		}
	}
	Q=read();
	for(int i=1;i<=Q;++i){
		x=read();y=read();
		if(i == 256)cerr<<"Change "<<x<<" from "<<c[x]<<" into "<<y<<" and first "<<s[bl[x]].begin()<<" in "<<rd[bl[x]]<<endl;
		if(!rd[bl[x]]){
			ans-=s[bl[x]].begin();
			s[bl[x]].erase(c[x]);
			c[x]=y;s[bl[x]].insert(c[x]);
			if(i == 256)cerr<<" new bgin "<<s[bl[x]].begin()<<endl;
			ans+=s[bl[x]].begin();
		}
		printnum(ans,'\n');
	}
	return pc(0,1);
}
