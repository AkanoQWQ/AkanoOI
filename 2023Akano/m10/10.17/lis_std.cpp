#include<bits/stdc++.h>
typedef long long ll;
const int maxn=3e5+5;
struct memo{
	ll v;
	int l,r;
	friend memo operator+(memo now,memo oth){return (memo){now.v+oth.v,now.l,oth.r};}
	friend bool operator<(memo now,memo oth){return now.v<oth.v;}
	void turn(){
		v=-v;
		return;
	}
};
struct info{
	memo pre,suf,ans,sum;
	friend info operator+(info now,info oth){
		info ret;
		ret.pre=std::max(now.pre,now.sum+oth.pre),ret.suf=std::max(oth.suf,now.suf+oth.sum);
		ret.sum=now.sum+oth.sum,ret.ans=std::max(std::max(now.ans,oth.ans),now.suf+oth.pre);
		return ret;
	}
	void set(ll x,int p){
		pre=suf=ans=sum=(memo){x,p,p};
		return;
	}
	void turn(){
		pre.turn(),suf.turn(),ans.turn(),sum.turn();
		return;
	}
};
struct node{
	int l,r;
	info now,oth;
	bool turn;
}tree[maxn*4];
ll sum[maxn],val[maxn];
void update(int i){
	tree[i].now=tree[i*2].now+tree[i*2+1].now;
	tree[i].oth=tree[i*2].oth+tree[i*2+1].oth;
	return;
}
void build(int i,int l,int r){
	tree[i].l=l,tree[i].r=r;
	if(l==r){
		tree[i].now.set(val[l],l),tree[i].oth.set(-val[l],l);
		return;
	}
	int mid=(l+r)>>1;
	build(i*2,l,mid),build(i*2+1,mid+1,r);
	update(i);
	std::cerr<<l<<" to "<<r<<" is "<<tree[i].now.ans.l<<","<<tree[i].now.ans.r<<":"<<tree[i].now.ans.v<<'\n';
	if(l == 14 && r == 17){
		auto segs = tree[i*2].now.suf + tree[i*2+1].now.pre;
		std::cerr<<tree[i*2].now.suf.l<<","<<tree[i*2].now.suf.r<<","<<tree[i*2].now.suf.v<<","<<std::endl;
		std::cerr<<tree[i*2+1].now.pre.l<<","<<tree[i*2+1].now.pre.r<<","<<tree[i*2+1].now.pre.v<<","<<std::endl;
	}
	return;
}
void put(int x){
	std::swap(tree[x].now,tree[x].oth);
	tree[x].turn^=1;
	return;
}
void pushdown(int x){
	if(tree[x].turn)put(x*2),put(x*2+1),tree[x].turn=false;
	return;
}
void invert(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		put(i);
		std::cerr<<"after reverse "<<l<<" to "<<r<<" is "<<tree[i].now.ans.l<<","<<tree[i].now.ans.r<<":"<<tree[i].now.ans.v<<'\n';
		return;
	}
	pushdown(i);
	if(tree[i*2].r>=l)invert(i*2,l,r);
	if(tree[i*2+1].l<=r)invert(i*2+1,l,r);
	update(i);
	return;
}
int n,m;
struct pii{int v,l;}par[maxn];
ll ans;
signed main(){
	freopen("lis/lis3.in","r",stdin);
//	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++)scanf("%d%d",&par[i].v,&par[i].l),val[i]=(par[i].v==0?1:-1)*par[i].l,
		sum[i]=sum[i-1]+val[i],ans+=(par[i].v==1)*par[i].l;
	build(1,1,n);
	ll mx=0;
	int pos=-1;
	for(int i=1;i<=n;i++)if(sum[i]>mx)mx=sum[i],pos=i;
	if(pos!=-1)invert(1,1,pos),ans+=mx;
	std::cerr<<"to "<<pos<<" is "<<mx<<std::endl;
	return 0;
	printf("%lld\n",ans);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		memo now=tree[1].now.ans;
		std::cerr<<now.l<<"~"<<now.r<<" is "<<now.v<<std::endl;
//		printf("now={%lld,%d,%d}\n",now.v,now.l,now.r);
		if(now.v>0)ans+=now.v,invert(1,now.l,now.r);
		printf("%lld\n",ans);
	}
	return 0;
}
