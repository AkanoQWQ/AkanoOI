#include<bits/stdc++.h>
namespace iobuff{
	const int LEN=10000000;
	char in[LEN+5],out[LEN+5];
	char *pin=in,*pout=out,*ed=in,*eout=out+LEN;
	inline char gc(void){
		#ifdef TQX
		return getchar();
		#endif 
		return pin==ed&&(ed=(pin=in)+fread(in,1,LEN,stdin),ed==in)?EOF:*pin++;
	}
	inline void pc(char c){
		pout==eout&&(fwrite(out,1,LEN,stdout),pout=out);
		(*pout++)=c;
	}
	inline void flush(){fwrite(out,1,pout-out,stdout),pout=out;}
	template<typename T> inline void read(T &x){
		static int f;
		static char c;
		c=gc(),f=1,x=0;
		while(c<'0'||c>'9') f=(c=='-'?-1:1),c=gc();
		while(c>='0'&&c<='9') x=10*x+c-'0',c=gc();
		x*=f;
	}
	template<typename T> inline void putint(T x,char div='\n'){
		static char s[20];
		static int top;
		top=0;
		x<0?pc('-'),x=-x:0;
		while(x) s[top++]=x%10,x/=10;
		!top?pc('0'),0:0;
		while(top--) pc(s[top]+'0');
		pc(div);
	}
}
using namespace iobuff;
using namespace std;
typedef long long ll;
const int N=2e5+10,mod=998244353,B=20; 
char s[N];
int n,q,stk[N],top,pze[N],pre[N],mx,lim[N];
ll suf[N],ret[N],ppze[N],anq[N],ssuf[N];
int ql[24][N],qr[24][N];
inline int calc(int bef,int height){
	if(height>=22) return 0x3f3f3f3f;
	return (1<<height+1)-(1<<height-bef)-1;
}
inline int space(int bef,int height){
	if(height>=22) return 0x3f3f3f3f;
	return (1<<height+1)-(1<<height-bef+1);
}
inline void init(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	pre[0]=0;
	for(int i=0;i<=22;++i) lim[i]=n;//lim是什么?待解决 
	for(int i=1,now=0;i<=n;++i){
		while((1<<now+1)-1<i) ++now;//lim_i 表示容量为i的子树的最小高度 
		pre[i]=pre[i-1]+now;lim[now]=i;//pre是lim的前缀数组 
	}
	
	pze[0]=ppze[0]=0;//两个前缀和是a > logn 情况下需要求的前缀和 
	for(int i=1;i<=n;++i){//但是,为什么只需要预处理出这个东西就可以了? 
		pze[i]=pze[i-1]+(s[i]=='0');//难道答案不是还和 a 挂钩吗 
		ppze[i]=ppze[i-1]+pze[i-1]; 
	} 
	suf[n+1]=ssuf[n+1]=0;//上面维护的值的后缀和版本 
	for(int i=n;i>=1;--i){
		suf[i]=suf[i+1]+pze[i];
		ssuf[i]=ssuf[i+1]+suf[i];
	}
	
	ll ans=0;
	stk[top=1]=n+1;//stk是用于维护什么的栈?
	//其实应该不是栈,只是一个存0位置的数组 
	for(int i=n;i>=1;--i){//逆序遍历,所以ans是后缀形式的?(ans没置零)
		if(s[i]=='0') stk[++top]=i;//将0的位置压入栈
		int bef=stk[top]-i,ct=0,now=bef;//bef:最后一个0的位置与当前位置差
		if(bef) ans+=pre[bef];//如果当前0与最后一个0有位置差,则答案累加 pre_bef(?) 
		for(int j=0;j<=22;++j) ql[j][i]=n+1,qr[j][i]=0;
		for(int j=1;j<=22;++j){
			int ll=lim[j-1]+1,rr=min(lim[j],bef);
			if(ll<=rr) ql[j][i]=min(ql[j][i],ll+i-1),qr[j][i]=max(qr[j][i],rr+i-1);
						
			mx=max(mx,j);//upd upd upd upd upd

			if(lim[j]>=bef) break;
		}
		int las=0;
		for(int j=top;j>1;--j){
			int x=stk[j];++ct;
			if(ct>B){
				if(bef) ans+=suf[x];
				else ans+=suf[x]-(n-x+1);
				ans-=1ll*pze[i-1]*(n-x+1);
				break;
			}
			int be=min(bef,1),height=ct+be-1;
			while(space(be,height)<bef) ++be,++height;
			int l=now,las=now;now+=stk[j-1]-stk[j]-1;int r=now;
			while(l<=r){
				while(calc(be,height)<l){
					if(be<bef) ++be;++height;
				}
				int nr=min(calc(be,height),r);
				mx=max(mx,height);
				ql[height][i]=min(ql[height][i],(l-las)+stk[j]);
				qr[height][i]=max(qr[height][i],(nr-las)+stk[j]);
				ans+=1ll*height*(nr-l+1);
				l=nr+1;
			}
		}
		ret[i]=ans;
	}
	reverse(stk+1,stk+top+1);
}
inline ll calc(int l1,int r1,int l2,int r2){
	if(l1>r1||l2>r2) return 0;
	ll ans=0;
	int x2=pze[r1]-pze[l1-1],x1=r1-l1+1-x2;
	ans+=(suf[l2]-suf[r2+1])*x1;
	ans+=(suf[l2]-suf[r2+1]-(r2-l2+1))*x2;
	ans-=1ll*(r2-l2+1)*(ppze[r1]-ppze[l1-1]);
	return ans; 
}
int L[N],R[N],tot,first[N],nxt[N<<1];
pair<int,int> val[N<<1];
inline void add(int x,pair<int,int> y){
	val[++tot]=y;
	nxt[tot]=first[x];first[x]=tot;
}
inline ll solve(int id,int l,int r){
	L[id]=l;R[id]=r;
	ll ans=ret[l]-ret[r+1];
	int pos=lower_bound(stk+1,stk+top+1,r+1)-stk;
	if(pos>B+1) ans-=calc(l,stk[pos-B-1],r+1,stk[pos]-1);
	for(int i=pos;i<top;++i){
		if(i>B){
			if(stk[i-B]>=r){
				ans-=calc(l,r,stk[i],n);
				break;
			}
			ans-=calc(l,stk[i-B],stk[i],stk[i+1]-1);
		}
	}		
	return ans;
}
namespace BIT{
	ll t1[N],t2[N],sum;
	inline void update(int l,int r,ll v){
		sum+=(r-l+1)*v;
		for(int x=l;x<=n;x+=(x&-x)) t1[x]+=v,t2[x]+=v*l;
		for(int x=r+1;x<=n;x+=(x&-x)) t1[x]-=v,t2[x]-=v*(r+1);
	}
	inline ll qry(int r){
		ll res=0;
		for(int i=r;i>0;i-=(i&-i)) res+=t1[i]*(r+1)-t2[i];
		return res;
	}
	inline ll query(int l){return sum-qry(l-1);}
}
int main(){
	init();
	for(int i=1,l,r;i<=q;++i){
		read(l);read(r);
		anq[i]=solve(i,l,r);
	}
	for(int j=1;j<=q;++j){
		int l=L[j],r=R[j];
		if(l>1) add(l-1,make_pair(j,r+1));
		add(r,make_pair(-j,r+1));
	}
	for(int j=1;j<=n;++j){
		for(int i=1;i<=mx;++i)
			if(ql[i][j]<=qr[i][j])
				BIT::update(ql[i][j],qr[i][j],i);
		for(int v=first[j];v;v=nxt[v]){
			ll ans=BIT::query(val[v].second);
			if(val[v].first>0) anq[val[v].first]+=ans;
			else anq[-val[v].first]-=ans;  
		}
	}
	for(int i=1;i<=q;++i) putint((anq[i]+mod)%mod,'\n');flush();
	return 0;
}
