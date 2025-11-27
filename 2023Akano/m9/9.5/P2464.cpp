#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 2006 + 1018 + 1108;
int n,q,blk_len,bel[MAXN],kol[MAXN],kol2[MAXN],trans[MAXN][3],ans[MAXN];
int cnt[MAXN * 2];
vector<int> vec;
struct Query{
	int l,r,t,k,id;
}ask[MAXN];
bool operator<(Query q1,Query q2){
	if(bel[q1.l] != bel[q2.l])return bel[q1.l] < bel[q2.l];
	if(bel[q1.r] != bel[q2.r])return bel[q1.r] < bel[q2.r];
	return q1.t < q2.t;
}
inline void ReadIn(){
	int cacheQ;
	cin>>n>>cacheQ;
	blk_len = pow(n,0.66);
	for(int i = 1;i <= n;i++){
		bel[i] = ((i-1) / blk_len) + 1;
		cin>>kol[i];
		vec.push_back(kol[i]);
		kol2[i] = kol[i];
	}
	int nowt = 1;
	for(int i = 1;i <= cacheQ;i++){
		char opt;
		cin>>opt;
		if(opt == 'Q'){
			++q;
			cin>>ask[q].l>>ask[q].r>>ask[q].k;
			ask[q].t = nowt,ask[q].id = q;
		}else{
			++nowt;
			cin>>trans[nowt][0]>>trans[nowt][2];
			trans[nowt][1] = kol2[trans[nowt][0]];
			kol2[trans[nowt][0]] = trans[nowt][2];
			vec.push_back(trans[nowt][2]);
		}
	}
	sort(vec.begin(),vec.end());
	auto it = unique(vec.begin(),vec.end());
	vec.erase(it,vec.end());
	for(int i = 1;i <= n;i++){
		kol[i] = lower_bound(vec.begin(),vec.end(),kol[i]) - vec.begin();
	}
	for(int i = 2;i <= nowt;i++){
		trans[i][1] = lower_bound(vec.begin(),vec.end(),trans[i][1]) - vec.begin();
		trans[i][2] = lower_bound(vec.begin(),vec.end(),trans[i][2]) - vec.begin();
	}
	for(int i = 1;i <= q;i++){
		ask[i].k = lower_bound(vec.begin(),vec.end(),ask[i].k) - vec.begin();
	}
	for(int i = 1;i <= n;i++){
		bel[i] = ((i-1) / blk_len) + 1;
	}
	sort(ask+1,ask+q+1);
	return ;
}
inline void AddKolor(int x){
	cnt[x]++;
	return ;
}
inline void DelKolor(int x){
	cnt[x]--;
	return ;
}
inline void Add(int x){
	AddKolor(kol[x]);
	return ;
}
inline void Del(int x){
	DelKolor(kol[x]);
	return ;
}
inline void Travel(int l,int r,int x,bool f){
	int from = trans[x][1],to = trans[x][2];
	if(f)swap(from,to);
	if(l <= trans[x][0] && trans[x][0] <= r){
		DelKolor(from),AddKolor(to);
	}
	kol[trans[x][0]] = to;
	return ;
}
inline void Solve(){
	int l = 1,r = 0,t = 1;
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
		while(t < ask[i].t){
			Travel(l,r,++t,false);
		}
		while(t > ask[i].t){
			Travel(l,r,t--,true);
		}
		ans[ask[i].id] = cnt[ask[i].k];
	}
	return ;
}
inline void Output(){
	for(int i = 1;i <= q;i++){
		cout<<ans[i]<<'\n';
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
