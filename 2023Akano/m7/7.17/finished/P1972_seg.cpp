#include<bits/stdc++.h>
#pragma GCC target("avx")
using namespace std;
const int MAXN = 1e6 + 1018 + 1108;
const int SIZE = 1e6 + 6;
int n,q,val[MAXN],lst[MAXN],ans[MAXN],nowr = 0;
struct Query{
	int l,r,id;
}ask[MAXN];
bool cmp4Query(Query qa,Query qb){
	if(qa.r == qb.r)return qa.id < qb.id;
	return qa.r < qb.r;
}
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
		Node node[MAXN * 4];
		inline void PushUp(int p){
			node[p].val = node[p*2].val + node[p*2+1].val;
			return ;
		}
		inline void PushDown(int p){
			if(!node[p].lazy)return ;
			node[p*2].val += node[p].lazy * node[p*2].len;
			node[p*2+1].val += node[p].lazy * node[p*2+1].len;
			node[p*2].lazy += node[p].lazy,node[p*2+1].lazy += node[p].lazy;
			node[p].lazy = 0;
			return ;
		}
		void Build(int p,int l,int r){
			node[p].len = (r - l + 1);
			if(l == r)return ;
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			return ;
		}
		void Change(int p,int l,int r,int OBJL,int OBJR,int _val){
			if(OBJL <= l && r <= OBJR){
				node[p].val += _val * node[p].len;
				node[p].lazy += _val;
				return ;
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,_val);
			if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,_val);
			PushUp(p);
			return ;
		}
		int Query(int p,int l,int r,int OBJ){
			if(l == r)return node[p].val;	
			const int mid = (l + r) >> 1;
			PushDown(p);
			if(mid >= OBJ)return Query(p*2,l,mid,OBJ);
			return Query(p*2+1,mid+1,r,OBJ);
		}
	public:
		inline void Build(){
			Build(1,1,n);
			return ;
		}
		inline void Change(int OBJL,int OBJR,int _val){
//			cout<<OBJL<<" to "<<OBJR<<" += "<<_val<<endl;		
			Change(1,1,n,OBJL,OBJR,_val);
			return ;
		}
		inline int Query(int pos){
			if(pos == 0)return 0;
			return Query(1,1,n,pos);
		}
}tr;
inline void AddVal(int no){
	const int _val = val[no];
	if(lst[_val] == 0){
		tr.Change(no,n,1);
	}else{
		tr.Change(lst[_val],n,-1);
		tr.Change(no,n,1);
	}
	lst[_val] = no;
	return ;
}
mt19937 rng(time(0));
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P1972_3.in","r",stdin);
	freopen("P1972.out","w",stdout);
	n = Read();
	for(int i = 1;i <= n;i++){
		val[i] = Read();
	}
	tr.Build();
	q = Read();
	for(int i = 1;i <= q;i++){
		ask[i].l = Read(),ask[i].r = Read();
		ask[i].id = i;
	}
	sort(ask+1,ask+q+1,cmp4Query);
	for(int i = 1;i <= q;i++){
//		cout<<ask[i].l<<" to "<<ask[i].r<<endl;
		while(nowr < ask[i].r){
			AddVal(++nowr);
		}
//		for(int i = 1;i <= n;i++){
//			cout<<tr.Query(i)<<" ";
//		}
//		cout<<endl;
		ans[ask[i].id] = tr.Query(ask[i].r) - tr.Query(ask[i].l-1);
	}
	for(int i = 1;i <= q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
