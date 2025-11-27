#include<bits/stdc++.h>
#define int long long

const int maxn=4e5+5;

struct node{
	int x,xx,y,op;
}q[maxn];
struct node1{
	int x,y,xx,yy,op;
}b[maxn],d1[maxn],d2[maxn];
int num,n,m,T,c,a[maxn],tot,t[maxn<<3],t1[maxn<<3],ans,cnt,c1,c2,now;
std::map<std::pair<int,int>,int>map;

bool cmp(node x,node y){
	return x.y<y.y;
}

int ls(int p){return p<<1;}
int rs(int p){return p<<1|1;}

void push_up(int p,int l,int r){
	if(t[p])t1[p]=a[r+1]-a[l];
	else t1[p]=t1[ls(p)]+t1[rs(p)];
}

void update(int p,int l,int r,int nl,int nr,int val){
	if(a[r+1]<=nl||a[l]>=nr)return;
	if(nl<=a[l]&&a[r+1]<=nr){
		t[p]+=val;
		push_up(p,l,r);
		return;
	}
	int mid=l+r>>1;
	update(ls(p),l,mid,nl,nr,val);
	update(rs(p),mid+1,r,nl,nr,val);
	push_up(p,l,r);
}

signed main(){
//	freopen("color.in","r",stdin); 3 1 2 1 2
//	freopen("color.out","w",stdout);
	scanf("%lld%lld%lld%lld",&c,&n,&m,&T);
	for(int i=1,x,xx,y,yy,op;i<=T;i++){
		scanf("%lld%lld%lld%lld%lld",&op,&x,&y,&xx,&yy);
//		if(x > xx){
//			std::swap(x,xx);
//		}
//		if(y > yy){
//			std::swap(y,yy);
//		}
		if(op==1){
			d1[++c1]={x,y,xx,yy,0};
			q[++cnt]={x,xx+1,y,1};a[cnt]=x;
			q[++cnt]={x,xx+1,y+1,-1};a[cnt]=xx+1;
		}else if(op==2){
			d2[++c2]={x,y,xx,yy,0};
			q[++cnt]={x,x+1,y,1};a[cnt]=x;
			q[++cnt]={x,x+1,yy+1,-1};a[cnt]=x+1;
		}else{
			bool flag=0;
			for(int j=1;j<=num;j++){
				if(b[j].x-b[j].y==x-y){
					if((x>=b[j].x&&x<=b[j].xx)||(xx>=b[j].x&&xx<=b[j].xx)||(b[j].x>=x&&b[j].x<=xx)||(b[i].xx>=x&&b[j].xx<=xx)){
						flag=1;b[now].op=1;
						b[j].x=std::min(b[j].x,x);b[j].xx=std::max(b[j].xx,xx);
						b[j].y=y-x+b[j].x;b[j].yy=y-x+b[j].xx;
						x=b[j].x,y=b[j].y,xx=b[j].xx,yy=b[j].yy,now=j;
					}
				}
			}
			if(flag==0)b[++num]={x,y,xx,yy,0};
		}
	}
	for(int i=1;i<=num;i++){
		if(b[i].op)continue;
		for(int j=1;j<=c1;j++){
			int cx=b[i].x-b[i].y+d1[j].y;
			if(cx>=b[i].x&&cx<=b[i].xx&&cx>=d1[j].x&&cx<=d1[j].xx){
				map[{cx,d1[j].y}]=1;
			}
		}
	}
	for(int i=1;i<=num;i++){
		if(b[i].op)continue;
		for(int j=1;j<=c2;j++){
			int cy=b[i].y-b[i].x+d2[j].x;
			if(cy>=b[i].y&&cy<=b[i].yy&&cy>=d2[j].y&&cy<=d2[j].yy){
				map[{d2[j].x,cy}]=1;
			}
		}
	}
	ans-=map.size();
	for(int i=1;i<=num;i++){
		if(b[i].op)continue;
		ans+=(b[i].xx-b[i].x+1);
	}
	std::sort(a+1,a+cnt+1);
	tot=std::unique(a+1,a+cnt+1)-a-1;
	std::sort(q+1,q+cnt+1,cmp);
	for(int i=1;i<cnt;i++){
		update(1,1,tot-1,q[i].x,q[i].xx,q[i].op);
		ans=ans+t1[1]*(q[i+1].y-q[i].y);
	}
	printf("%lld",num);
	return 0;
}
/*
0
5 5 3
3 1 1 2 2
3 3 3 4 4
3 2 2 3 3
*/

