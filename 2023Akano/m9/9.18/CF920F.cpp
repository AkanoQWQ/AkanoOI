#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 3e5 + 1018 + 1108;
struct Node{
	ll val,not12;
};
ll arr[MAXN],n,m;
inline int D(int x){
	int ret = 0;
	for(int i = 1;i*i <= x;i++){
		if(x % i == 0){
			ret += 2;
			if(i*i == x)ret--;
		}
	}
	return ret;
}
class SegmentTree{
	private:
		Node node[MAXN * 4];
		void PushUp(int p){
			node[p].val = node[p*2].val + node[p*2+1].val;
			node[p].not12 = node[p*2].not12 + node[p*2+1].not12;
			return ;
		}
		void Build(int p,int l,int r){
			if(l == r){
				node[p].val = arr[l];
				node[p].not12 = (node[p].val != 1 && node[p].val != 2);
				return ;
			}
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			PushUp(p);
			return ;
		}
		void Change(int p,int l,int r,int OBJL,int OBJR){
			if(node[p].not12 == 0)return ;
			if(l == r){
				node[p].val = D(node[p].val);
				node[p].not12 = (node[p].val != 1 && node[p].val != 2);
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR);
			PushUp(p);
			return ;
		}
		ll Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				return node[p].val;
			}
			const int mid = (l + r) >> 1;
			ll ret = 0;
			if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
			return ret;
		}
	public:
		inline void Build(){
			Build(1,1,n);
			return ;
		}
		inline void Change(int l,int r){
			Change(1,1,n,l,r);
			return ;
		}
		inline ll Query(int l,int r){
			return Query(1,1,n,l,r);
		}
}tr;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>arr[i];
	tr.Build();
	while(m--){
		int opt,l,r;
		cin>>opt>>l>>r;
		if(opt == 1){
			tr.Change(l,r);
		}else{
			cout<<tr.Query(l,r)<<'\n';
		}
	}
	return not(Akano loves pure__Elysia);
}
