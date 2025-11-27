#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXB = 1018;
const int MOD = 1e9 + 7;
int n,q,a[MAXN],blk_len,blk_cnt,belong[MAXN];
vector<pii> save;
inline void Prepare(){
	ll last = 0;
	for(int i = 0;i*i <= 1e9 + 3e4;i++){
		int l = i*i,r = (i+1) * (i+1) - 1;
		last += 1ll * (r - l + 1) * i;
		last %= MOD;
		save.emplace_back(r,last);
	}
	return ;
}
inline ll GetG(ll x){
	ll f = sqrt(x);
	return (-2 * (f*f*f) - 3 * (f*f) + 5 * f) / 6 + x * f;
}
ll arrval[MAXN];
class Cmper{
public:
	bool operator()(pii pii1,pii pii2){
		if(pii1.first != pii2.first)return pii1.first > pii2.first;
		return pii1.second < pii2.second;
	}
};
struct Block{
	int l,r,lazy,usedlazy;
	priority_queue<pii,vector<pii>,Cmper> deltaChange;
	ll blockDelta,val;
	inline void Build(){
		val = blockDelta = 0;
		assert(lazy == usedlazy);
		lazy = usedlazy = 0;
		while(!deltaChange.empty())deltaChange.pop();
		for(int i = l;i <= r;i++){
			int delta = sqrt(a[i]);
			int deltaDelta = (delta+1) * (delta+1) - a[i];
			deltaChange.push(make_pair(deltaDelta,delta+1));
			blockDelta += delta;
			arrval[i] = GetG(a[i]);
			val += arrval[i];
		}
		return ;
	}
	inline void Check(){
		while(lazy >= deltaChange.top().first){
			int nowdeltaC = deltaChange.top().first,nowdelta = deltaChange.top().second;
			blockDelta++;
			nowdeltaC += (nowdelta+1) * (nowdelta+1) - (nowdelta * nowdelta);
			deltaChange.pop();
			deltaChange.push(make_pair(nowdeltaC,nowdelta+1));
		}
		return ;
	}
	inline void PushDown(){//PushDown完了并修改以后一定要Build,原因为Check对lazy有依赖
		if(lazy == usedlazy)return ;
		for(int i = l;i <= r;i++){
			a[i] += lazy - usedlazy;
			arrval[i] = GetG(a[i]);
		}
		usedlazy = lazy;
		return ;
	}
}block[MAXB];
inline void BF_Change(int blk,int l,int r){
	block[blk].PushDown();
	for(int i = l;i <= r;i++){
		a[i]++;
		arrval[i] += sqrt(a[i]);
		if(arrval[i] >= MOD)arrval[i] -= MOD;
	}
	block[blk].Build();
	return ;
}
inline ll BF_Query(int blk,int l,int r){
	ll ret = 0;
	block[blk].PushDown();
	for(int i = l;i <= r;i++){
		ret += arrval[i];
		if(ret >= MOD)ret -= MOD;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("play.in","r",stdin);
	freopen("play.out","w",stdout);
	cin>>n>>q;
	blk_len = sqrt(n);
	Prepare();
	for(int i = 1;i <= n;i++){
		belong[i] = ((i-1) / blk_len) + 1;
		if(block[belong[i]].l == 0)block[belong[i]].l = i;
		block[belong[i]].r = i;
		blk_cnt = belong[i];
		cin>>a[i];
	}
	for(int i = 1;i <= blk_cnt;i++){
		block[i].Build();
	}
	while(q--){
		int opt,l,r,blockL,blockR;
		cin>>opt>>l>>r;
		blockL = belong[l],blockR = belong[r];
		if(opt == 1){
			if(blockL == blockR){
				BF_Change(blockL,l,r);
			}else{
				BF_Change(blockL,l,block[blockL].r);
				BF_Change(blockR,block[blockR].l,r);
				for(int i = blockL + 1;i <= blockR - 1;i++){
					block[i].lazy++;
					block[i].Check();
					block[i].val += block[i].blockDelta;
					block[i].val %= MOD;
				}
			}
		}else if(opt == 2){
			ll ans = 0;
			if(blockL == blockR){
				ans = BF_Query(blockL,l,r);
			}else{
				ans += BF_Query(blockL,l,block[blockL].r);
				if(ans >= MOD)ans -= MOD;
				ans += BF_Query(blockR,block[blockR].l,r);
				if(ans >= MOD)ans -= MOD;
				for(int i = blockL + 1;i <= blockR - 1;i++){
					ans += block[i].val;
					if(ans >= MOD)ans -= MOD;
				}
			}
			cout<<ans % MOD<<'\n';
		}
	}
	return not(Akano loves pure__Elysia);
}
