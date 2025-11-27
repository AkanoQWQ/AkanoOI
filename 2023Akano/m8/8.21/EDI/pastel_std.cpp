#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define int unsigned int
using namespace std;
const int Mxdt=100000;	//单次大小 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
inline int read()
{
	int res=0,bj=0;char ch=gc();
	while(ch<'0'||ch>'9')bj|=(ch=='-'),ch=gc();
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=gc();
	return bj?-res:res;
}
void print(int x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch)
{
	if(x<0)pc('-',false),x=-x;
	print(x),pc(ch,false);
}
int n,m,fa[300005],opt,x,y;
int h[300005],cnt;
struct edge{int to,next;}e[500005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
int size[300005],son[300005],d[300005];
void dfs1(int x){
	int i,y;size[x]=1;d[x]=d[fa[x]]+1;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;dfs1(y);size[x]+=size[y];
		son[x]=size[son[x]]<size[y]?y:son[x];
	}
}
int in[300005],out[300005],Time,pos[300005],top[300005];
void dfs2(int x,int Top){
	int i,y;top[pos[in[x]=++Time]=x]=Top;
	if(son[x])dfs2(son[x],Top);
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y!=son[x])dfs2(y,y);
	}
	out[x]=Time;
}
set<int>s[300005];set<int>::iterator it;
int p[300005];
int Belong(int x){
	int now=x;while(!s[top[now]].size()||p[top[now]]>in[now]){now=fa[top[now]];}
	it=s[top[now]].upper_bound(in[now]);--it;return pos[*it]; 
}
int sum[1200005],tag[1200005],len[1200005];
void pushup(int k){
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
void pushdown(int k){
	if(tag[k]){
		sum[k<<1]+=tag[k]*len[k<<1];tag[k<<1]+=tag[k];
		sum[k<<1|1]+=tag[k]*len[k<<1|1];tag[k<<1|1]+=tag[k];
		tag[k]=0;
	}
}
void build(int k,int l,int r){
	if(l==r){len[k]=1;return;}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	len[k]=len[k<<1]+len[k<<1|1];
}
void change(int k,int l,int r,int L,int R,int v){
	if(L<=l&&r<=R){sum[k]+=v*len[k];tag[k]+=v;return;}
	int mid=l+r>>1;pushdown(k);
	if(L<=mid)change(k<<1,l,mid,L,R,v);
	if(R>mid)change(k<<1|1,mid+1,r,L,R,v);
	pushup(k);
}
int query(int k,int l,int r,int L,int R){
	if(L<=l&&r<=R){return sum[k];}
	int mid=l+r>>1;pushdown(k);int ans=0;
	if(L<=mid)ans+=query(k<<1,l,mid,L,R);
	if(R>mid)ans+=query(k<<1|1,mid+1,r,L,R);
	return ans;
}
int Size[1200005],Sum[1200005],Val[1200005],Tag[1200005];
void Pushup(int k){
	Size[k]=Size[k<<1]+Size[k<<1|1];
	Sum[k]=Sum[k<<1]+Sum[k<<1|1];
	Val[k]=Val[k<<1]+Val[k<<1|1];
}
void ADD(int k,int v){
	Sum[k]+=v*Size[k];Val[k]+=v;Tag[k]+=v;
}
void Pushdown(int k){
	if(Tag[k]){
		ADD(k<<1,Tag[k]);
		ADD(k<<1|1,Tag[k]);
		Tag[k]=0;
	}
}
void Change(int k,int l,int r,int L,int R,int y){
	if(L<=l&&r<=R){ADD(k,y);return;}
	int mid=l+r>>1;Pushdown(k);
	if(L<=mid)Change(k<<1,l,mid,L,R,y);
	if(R>mid)Change(k<<1|1,mid+1,r,L,R,y);
	Pushup(k);
}
void changeS(int k,int l,int r,int x,int y){
	if(l==r){Size[k]+=y;Sum[k]+=y*Val[k];return;}
	int mid=l+r>>1;Pushdown(k);
	if(x<=mid)changeS(k<<1,l,mid,x,y);
	else changeS(k<<1|1,mid+1,r,x,y);
	Pushup(k);
}
void changeV(int k,int l,int r,int x,int y){
	if(l==r){Val[k]=y;Sum[k]=y*Size[k];return;}
	int mid=l+r>>1;Pushdown(k);
	if(x<=mid)changeV(k<<1,l,mid,x,y);
	else changeV(k<<1|1,mid+1,r,x,y);
	Pushup(k);
}
int Query(int k,int l,int r,int L,int R){
	if(L>R)return 0;
	if(L<=l&&r<=R){return Sum[k];}
	int mid=l+r>>1;Pushdown(k);int ans=0;
	if(L<=mid)ans+=Query(k<<1,l,mid,L,R);
	if(R>mid)ans+=Query(k<<1|1,mid+1,r,L,R);
	return ans;
}
int queryV(int k,int l,int r,int x){
	if(l==r){return Val[k];}
	int mid=l+r>>1;Pushdown(k);int ans=0;
	if(x<=mid)return queryV(k<<1,l,mid,x);
	else return queryV(k<<1|1,mid+1,r,x);
}
int queryS(int k,int l,int r,int L,int R){
	if(L>R)return 0;
	if(L<=l&&r<=R){return Size[k];}
	int mid=l+r>>1;Pushdown(k);int ans=0;
	if(L<=mid)ans+=queryS(k<<1,l,mid,L,R);
	if(R>mid)ans+=queryS(k<<1|1,mid+1,r,L,R);
	return ans;
}
signed main(){
//	system("fc pastel.out pastel2.ans");
	freopen("pastel/pastel2.in","r",stdin);
	freopen("pastel.ans","w",stdout);
	n=read();m=read();
	for(int i=2;i<=n;++i){
		fa[i]=read();add(fa[i],i);
	}
	dfs1(1);dfs2(1,1);build(1,1,n);
	s[1].insert(1);p[1]=1;
	changeS(1,1,n,1,n);
	for(int i=1;i<=m;++i){
		
		opt=read();x=read();
		if(opt==1){
			y=Belong(x);printnum(query(1,1,n,in[x],in[x])+queryV(1,1,n,in[y]),'\n');
		}
		else if(opt==2){
			y=read();changeV(1,1,n,in[x],queryV(1,1,n,in[x])+y);
		}
		else if(opt==3){
			cout<<i<<" : ";
			y=Belong(x);printnum(query(1,1,n,in[x],out[x])+Query(1,1,n,in[x]+1,out[x])+queryV(1,1,n,in[y])*(size[x]-queryS(1,1,n,in[x]+1,out[x])),'\n');	
			cout<<query(1,1,n,in[x],out[x])<<" and ";
			cout<<Query(1,1,n,in[x]+1,out[x])<<" and ";
			cout<<queryV(1,1,n,in[y])<<" * ";
			cout<<(size[x]-queryS(1,1,n,in[x]+1,out[x]))<<endl;
		}
		else if(opt==4){
			y=read();Change(1,1,n,in[x],out[x],y);
		}
		else if(opt==5){
			y=Belong(x);
			int tmp=size[x]-queryS(1,1,n,in[x]+1,out[x]);
			s[top[x]].insert(in[x]);p[top[x]]=*s[top[x]].begin();
			changeS(1,1,n,in[y],-tmp);changeS(1,1,n,in[x],tmp);changeV(1,1,n,in[x],queryV(1,1,n,in[y]));
		}
		else{
			y=Belong(fa[x]);
			int tmp=size[x]-queryS(1,1,n,in[x]+1,out[x]);
			changeS(1,1,n,in[y],tmp);changeS(1,1,n,in[x],-tmp);
			s[top[x]].erase(in[x]);if(s[top[x]].size())p[top[x]]=*s[top[x]].begin();
			tmp=queryV(1,1,n,in[x])-queryV(1,1,n,in[y]);
			change(1,1,n,in[x],out[x],tmp);Change(1,1,n,in[x],out[x],-tmp);
			changeV(1,1,n,in[x],0);
		}
	}
	return pc('o',true);
}
