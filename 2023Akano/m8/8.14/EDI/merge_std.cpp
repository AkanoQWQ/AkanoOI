#include<bits/stdc++.h>

const int maxn=5e5+35;

int n,m,f[maxn],max=maxn-5,ans,a[maxn];
int t[maxn<<2],t1[maxn<<2],t2[maxn<<2],tmp,num;
int tag[maxn<<2],tag1[maxn<<2],g[maxn],pos;
bool flag;

int ls(int p){return p<<1;}
int rs(int p){return p<<1|1;}

void push_up(int p){
	t[p]=std::min(t[ls(p)],t[rs(p)]);
	t1[p]=std::min(t1[ls(p)],t1[rs(p)]);
	t2[p]=std::max(t2[ls(p)],t2[rs(p)]);
}

void push_down(int p,int l,int r){
	if(tag[p]!=0){
		t[ls(p)]+=tag[p];t[rs(p)]+=tag[p];
		t2[ls(p)]+=tag[p];t2[rs(p)]+=tag[p];
		tag[ls(p)]+=tag[p];tag[rs(p)]+=tag[p];
		tag[p]=0;
	}
	if(tag1[p]!=0){
		t1[ls(p)]+=tag1[p];t1[rs(p)]+=tag1[p];
		tag1[ls(p)]+=tag1[p];tag1[rs(p)]+=tag1[p];
		tag1[p]=0;
	}
}

void update(int p,int l,int r,int nl,int nr,int val){
	if(nl<=l&&r<=nr){
		t[p]+=val;t2[p]+=val;
		tag[p]+=val;
		return;
	}
	int mid=l+r>>1;
	push_down(p,l,r);
	if(nl<=mid)update(ls(p),l,mid,nl,nr,val);
	if(nr>mid)update(rs(p),mid+1,r,nl,nr,val);
	push_up(p);
}

void update1(int p,int l,int r,int nl,int nr,int val){
	if(nl<=l&&r<=nr){
		t1[p]+=val;
		tag1[p]+=val;
		return;
	}
	int mid=l+r>>1;
	push_down(p,l,r);
	if(nl<=mid)update1(ls(p),l,mid,nl,nr,val);
	if(nr>mid)update1(rs(p),mid+1,r,nl,nr,val);
	push_up(p);
}

int query(int p,int l,int r,int nl,int nr){
	if(nl<=l&&r<=nr){
		return t[p];
	}
	int mid=l+r>>1,res=1000000;
	push_down(p,l,r);
	if(nl<=mid)res=std::min(res,query(ls(p),l,mid,nl,nr));
	if(nr>mid)res=std::min(res,query(rs(p),mid+1,r,nl,nr));
	return res;
}

int query1(int p,int l,int r,int nl,int nr){
	if(nl<=l&&r<=nr){
		return t1[p];
	}
	int mid=l+r>>1,res=1000000;
	push_down(p,l,r);
	if(nl<=mid)res=std::min(res,query1(ls(p),l,mid,nl,nr));
	if(nr>mid)res=std::min(res,query1(rs(p),mid+1,r,nl,nr));
	return res;
}

int query2(int p,int l,int r,int nl,int nr){
	if(nl<=l&&r<=nr){
		return t2[p];
	}
	int mid=l+r>>1,res=0;
	push_down(p,l,r);
	if(nl<=mid)res=std::max(res,query2(ls(p),l,mid,nl,nr));
	if(nr>mid)res=std::max(res,query2(rs(p),mid+1,r,nl,nr));
	return res;
}

int get(int p,int l,int r,int nl,int nr){
	if(t[p]==2)return r;
	if(l==r)return l-1;
	push_down(p,l,r);
	int mid=l+r>>1;
	if(nr<=mid)return get(ls(p),l,mid,nl,nr);
	else if(nl>mid)return get(rs(p),mid+1,r,nl,nr);
	else{
		int res=get(ls(p),l,mid,nl,nr);
		if(res<mid)return res;
		else return get(rs(p),mid+1,r,nl,nr);
	}
}

int get1(int p,int l,int r,int nl,int nr){
	if(t1[p]>=1&&t2[p]==1)return r;
	if(l==r)return l-1;
	push_down(p,l,r);
	int mid=l+r>>1;
	if(nr<=mid)return get1(ls(p),l,mid,nl,nr);
	else if(nl>mid)return get1(rs(p),mid+1,r,nl,nr);
	else{
		int res=get1(ls(p),l,mid,nl,nr);
		if(res<mid)return res;
		else return get1(rs(p),mid+1,r,nl,nr);
	}
}

void add(int x){
	tmp=query(1,1,max,x,x);
	if(tmp<2){
		if(tmp==0)ans++;
		update(1,1,max,x,x,1);
		return;
	}
	pos=get(1,1,max,x,max);
	update(1,1,max,x,pos,-1);
	update1(1,1,max,x,pos,1);
	update(1,1,max,pos+1,pos+1,1);
	if(query(1,1,max,pos+1,pos+1)==1)ans++;
}

void del(int x){
	tmp=query(1,1,max,x,x);
	if(tmp==2){
		update(1,1,max,x,x,-1);
		return;
	}
	num=query1(1,1,max,x,x);
	if(num==0){
		std::cout<<"CASE1"<<std::endl;
		update(1,1,max,x,x,-1);
		ans--;
		return;
	}
	pos=get1(1,1,max,x,max);
	update(1,1,max,x,pos,1);
	update1(1,1,max,x,pos,-1);
	update(1,1,max,pos+1,pos+1,-1);
	if(query(1,1,max,pos+1,pos+1)==0)ans--;
}

void build(int p,int l,int r){
	if(l==r){
		t[p]=t2[p]=f[l];
		t1[p]=g[l];
		return;
	}
	int mid=l+r>>1;
	build(ls(p),l,mid);build(rs(p),mid+1,r);
	push_up(p);
}

int main(){
	freopen("merge/merge2.in","r",stdin);
	freopen("merge.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);f[x]++;a[i]=x;
	}
	for(int i=1;i<=max;i++){
		if(f[i])ans++;
		if(f[i]>=3){
			f[i+1]+=(f[i]-1)/2;
			g[i]=(f[i]-1)/2;
			f[i]-=((f[i]-1)/2)*2;
		}
	}
	build(1,1,max);
	for(int i=1,op,x,y;i<=m;i++){
		scanf("%d",&op);
		if(op==2)printf("%d\n",ans);
		else{
			scanf("%d%d",&x,&y);
			del(a[x]);a[x]=y;add(y);
		}
	}
	return 0;
}
