#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 5e4 + 1018 + 1108;
int n,q,blk_len,kol[MAXN],arr[MAXN];
ll ans[MAXN][2];
struct Query{
	int l,r,blk,id;
}ask[MAXN];
bool operator<(Query q1,Query q2){
	if(q1.blk != q2.blk)return q1.blk < q2.blk;
	if(q1.blk & 1){
		return q1.r < q2.r;
	}else{
		return q1.r > q2.r;
	}
}
inline void ReadIn(){
	cin>>n>>q;
	blk_len = sqrt(n) + 1;
	for(int i = 1;i <= n;i++)cin>>arr[i];
	for(int i = 1;i <= q;i++){
		cin>>ask[i].l>>ask[i].r;
		ask[i].id = i,ask[i].blk = ((ask[i].l-1) / blk_len) + 1;
	}
	sort(ask+1,ask+q+1);
	return ;
}
inline void Add(int x,ll& nowans){
	nowans += kol[arr[x]];
	kol[arr[x]]++;
	return ;
}
inline void Del(int x,ll& nowans){
	kol[arr[x]]--;
	nowans -= kol[arr[x]];
	return ;
}
inline void Solve(){
	int l = 1,r = 0;
	ll nowans = 0;
	for(int i = 1;i <= q;i++){
		if(ask[i].l == ask[i].r){
			ans[ask[i].id][0] = 0;
			ans[ask[i].id][1] = 1;
			continue;
		}
		while(l > ask[i].l)Add(--l,nowans);
		while(r < ask[i].r)Add(++r,nowans);
		while(l < ask[i].l)Del(l++,nowans);
		while(r > ask[i].r)Del(r--,nowans);
		ans[ask[i].id][0] = nowans;
		ans[ask[i].id][1] = 1ll * (r - l + 1) * (r - l) / 2;
	}
	return ;
}
inline void Output(){
	for(int i = 1;i <= q;i++){
		ll gcd = __gcd(ans[i][0],ans[i][1]);
		cout<<ans[i][0] / gcd<<"/"<<ans[i][1] / gcd<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	Solve();
	Output();
	return not(Akano loves pure__Elysia);
}
