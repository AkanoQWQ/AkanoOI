#include<bits/stdc++.h>
#pragma GCC target("avx")
using namespace std;
const int MAXN = 1e6 + 1018 + 1108;
const int SIZE = 1e6 + 6;
int n,q,val[MAXN],lst[MAXN];
inline int Read(){//no f
	int ret = 0;
	char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}
int otp[66];
inline void Write(int x){
	int len = 0;
	while(x){
		otp[++len] = x % 10;
		x /= 10;
	}
	for(int i = len;i >= 1;i--)putchar(otp[i] + '0');
	return ;
}
struct Node{
	int ls,rs,val,lazy,len;
};
class SegmentTree{
	private:
		Node node[MAXN * (1<<5)];
		int roots[MAXN],tot;
		inline void PushUp(int p){
			node[p].val = node[node[p].ls].val + node[node[p].rs].val;
			return ;
		}
		inline void PushDown(int p){
			if(!node[p].lazy)return ;
			const int ols = node[p].ls,ors = node[p].rs;
			node[p].ls = ++tot,node[p].rs = ++tot;
			node[node[p].ls] = node[ols],node[node[p].rs] = node[ors];
			node[node[p].ls].val += node[p].lazy * node[node[p].ls].len;
			node[node[p].rs].val += node[p].lazy * node[node[p].rs].len;
			node[node[p].ls].lazy += node[p].lazy,node[node[p].rs].lazy += node[p].lazy;
			node[p].lazy = 0;
			return ;
		}
		int Build(int l,int r){
			const int p = ++tot;
			node[p].len = (r - l + 1);
			if(l == r)return p;
			const int mid = (l + r) >> 1;
			node[p].ls = Build(l,mid),node[p].rs = Build(mid+1,r);
			return p;
		}
		int Change(int p,int l,int r,int OBJL,int OBJR,int _val){
			const int no = ++tot;
			node[no] = node[p];
			if(OBJL <= l && r <= OBJR){
				node[p].val += _val * node[p].len;
				node[p].lazy += _val;
				return no;
			}
			const int mid = (l + r) >> 1;
			PushDown(no);
			if(mid >= OBJL)node[no].ls = Change(node[no].ls,l,mid,OBJL,OBJR,_val);
			if(mid < OBJR)node[no].rs = Change(node[no].rs,mid+1,r,OBJL,OBJR,_val);
			PushUp(no);
			return no;
		}
		int Query(int p,int l,int r,int OBJ){
			if(l == r)return node[p].val;	
			const int mid = (l + r) >> 1;
			PushDown(p);
			if(mid >= OBJ)return Query(node[p].ls,l,mid,OBJ);
			return Query(node[p].rs,mid+1,r,OBJ);
		}
	public:
		inline void Build(){
			roots[0] = Build(1,SIZE);
			return ;
		}
		inline void Change(int OBJL,int OBJR,int _val,int history,int version){			
			roots[version] = Change(roots[history],1,SIZE,OBJL,OBJR,_val);
			return ;
		}
		inline int Query(int version,int pos){
			return Query(roots[version],1,SIZE,pos);
		}
}tr;
mt19937 rng(time(0));
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P1972.in","r",stdin);
	freopen("P1972.out","w",stdout);
	n = Read();
	tr.Build();
	for(int i = 1;i <= n;i++){
		val[i] = Read();
		if(lst[val[i]] == 0){
			tr.Change(i,n,1,i-1,i);
		}else{
			tr.Change(lst[val[i]],i-1,-1,i-1,i);
			tr.Change(i,n,1,i,i);
		}
		lst[val[i]] = i;
	}
	q = Read();
	for(int i = 1;i <= q;i++){
		int l = Read(),r = Read();
		Write(tr.Query(r,r) - tr.Query(r,l-1)),putchar('\n');
	}
	return 0;
}
