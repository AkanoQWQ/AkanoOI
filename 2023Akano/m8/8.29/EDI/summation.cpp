#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
ll n,q,arr[MAXN],ans[MAXN],blk_len;
struct Query{
	int l,r,id,blk;
}ask[MAXN];
bool Cmp(Query q1,Query q2){
	if(q1.blk != q2.blk)return q1.blk < q2.blk;
	if(q1.r != q2.r){
		if(q1.blk & 1){
			return q1.r < q2.r;
		}else{
			return q1.r > q2.r;
		}
	}
	return q1.id < q2.id;
}
ll sum = 0,res = 0;
inline void Add(int x){
	sum += arr[x];
	res += arr[x] * sum;
	return ;
}
inline void Del(int x){
	res -= arr[x] * sum;
	sum -= arr[x];
	return ;
}
inline void Solve(){
	int l = 1,r = 0;
	for(int i = 1;i <= q;i++){
		while(l > ask[i].l){
			Add(--l);
		}
		while(r < ask[i].r){
			Add(++r);
		}
		while(l < ask[i].l){
			Del(l++);
		}
		while(r > ask[i].r){
			Del(r--);
		}
		ans[ask[i].id] = res;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("summation.in","r",stdin);
	freopen("summation.out","w",stdout);
	cin>>n>>q;
	blk_len = sqrt(n);
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	for(int i = 1;i <= q;i++){
		cin>>ask[i].l>>ask[i].r;
		ask[i].id = i,ask[i].blk = (ask[i].l / blk_len) + 1;
	}
	sort(ask+1,ask+q+1,Cmp);
	Solve();
	for(int i = 1;i <= q;i++){
		cout<<ans[i]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
