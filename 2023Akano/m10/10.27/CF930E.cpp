#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
const int MOD = 1e9 + 7;
const int SEC = 106;
int n,m,k,tail,tot;
struct Segment{
	enum typeType{
		up,down
	};
	int l,r;
	typeType type;
}seg[MAXN];
ll f[MAXN][SEC],ans;

inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(n & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}


bool Cmp(Segment seg1,Segment seg2){
	if(seg1.l != seg2.l)return seg1.l < seg2.l;
	if(seg1.r != seg2.r)return seg1.r < seg2.r;
	return seg1.type < seg2.type;
	cerr<<"shounld appear!"<<endl;
	assert(false);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>k>>n>>m;
	for(int i = 1;i <= n;i++){
		tail++;
		cin>>seg[tail].l>>seg[tail].r;
		seg[tail].type = Segment::up;
	}
	for(int i = 1;i <= m;i++){
		tail++;
		cin>>seg[tail].l>>seg[tail].r;
		seg[tail].type = Segment::down;
	}
	tot = n + m;
	sort(seg+1,seg+tot+1,Cmp);
	f[1][1] = 1;
	for(int i = 1;i <= tot;i++){
		cerr<<"from "<<seg[i].l<<" to "<<seg[i].r<<endl;
		for(int lst = 1;lst <= seg[i].r;lst++){
			cerr<<i<<","<<lst<<" is "<<f[i][lst]<<endl;
			if(lst+1 <= seg[i].r){//留到下面管辖,不能选需求的颜色,不然会算重
				f[i][lst+1] = (f[i][lst+1] + f[i][lst]) % MOD;
			}
			for(int pst = lst + 1;pst <= seg[i].r;pst++){
				ll poss = KSM(2,pst - lst);
				f[i+1][lst+1] = (f[i+1][lst+1] + f[i][lst] * poss) % MOD;
			}
		}
	}
	for(int i = 1;i <= k;i++){
		ans += f[tot+1][i];
		ans %= MOD;
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
