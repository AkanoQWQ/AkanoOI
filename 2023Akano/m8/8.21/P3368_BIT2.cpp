#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 1018 + 1108;
template<typename T,int SIZE>
class BIT{
	private:
		T val[SIZE];
		inline int Lowbit(int x){
			return x & (-x);
		}
		inline T QueryPre(int x){
			T ret = 0;
			while(x){
				ret += val[x];
				x -= Lowbit(x);
			}
			return ret;
		}
	public:
		inline void Change(int x,T _val){
			while(x <= SIZE){
				val[x] += _val;
				x += Lowbit(x);
			}
			return ;
		}
		inline T Query(int l,int r){
			return QueryPre(r) - QueryPre(l-1);
		}
};
BIT<int,MAXN> bit;
int n,q,arr[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
		bit.Change(i,arr[i] - arr[i-1]);
	}
	while(q--){
		int opt,x,y,k;
		cin>>opt;
		if(opt == 1){
			cin>>x>>y>>k;
			bit.Change(x,k);
			bit.Change(y+1,-k);
		}else{
			cin>>x;
			cout<<bit.Query(1,x)<<'\n';
		}
	}
	return 0;
}
