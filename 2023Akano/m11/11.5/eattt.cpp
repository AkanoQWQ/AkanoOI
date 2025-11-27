#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1018 + 1108;
constexpr int TMOD = 1e9 + 7;

template<typename T>
class InverseFactory{
private:
	vector<pair<T&,T> > arr;
	vector<T> sum,inv;
	inline void Build(){
		T cacheval;
		arr.clear(),sum.clear(),inv.clear();
		arr.emplace_back(cacheval,T(1)),sum.push_back(T(1)),inv.push_back(T(1));
		return ;
	}
	inline T KSM(T a,T b){
		T ret = 1;
		while(b){
			if(b & 1)ret = (ret * a) % MOD;
			a = (a * a) % MOD;
			b >>= 1;
		}
		return ret;
	}
public:
	T MOD;
	InverseFactory(){
		MOD = 1;
		Build();
		return ;
	}
	InverseFactory(T _mod){
		MOD = _mod;
		Build();
		return ;
	}
	inline void Insert(T& pos,T val){
		arr.emplace_back(pos,val),sum.push_back((sum.back() * val) % MOD);
		return ;
	}
	inline void Solve(){
		const int nowSize = int(sum.size()) - 1;
		inv.resize(sum.size());
		for(int i = 1;i <= nowSize;i++){
			sum[i] = (sum[i-1] * arr[i].second) % MOD;
		}
		inv[nowSize] = KSM(sum[nowSize],MOD-2);
		for(int i = nowSize;i >= 1;i--){
			inv[i-1] = (inv[i] * arr[i].second) % MOD;
		}
		for(int i = nowSize;i >= 1;i--){
			inv[i] = (inv[i] * sum[i-1]) % MOD;
			arr[i].first = inv[i];
		}
		Build();
		return ;
	}
};
InverseFactory<ll> invfactory(TMOD);

int n,k,a[MAXN];
ll fac[MAXN],facInv[MAXN];
inline ll C(ll x,ll y){
	if(x < y)return 0;
	return (((fac[x] * facInv[y]) % TMOD) * facInv[x-y]) % TMOD;
}
ll val1 = 1,val2 = 1,val3 = 1,delta = 0,ans = 0,sum = 0,divv = 1;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("eattt.in","r",stdin);
//	freopen("eattt.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	fac[0] = facInv[0] = 1;
	for(int i = 1;i <= n+2;i++){
		fac[i] = (fac[i-1] * i) % TMOD;
		invfactory.Insert(facInv[i],fac[i]);
	}
	for(int i = 1;i <= k;i++){
		val1 = (val1 * (n - i)) % TMOD;
		val3 = (val3 * (n - 2 - i)) % TMOD;
		divv = (divv * (n-i)) % TMOD;
	}
	invfactory.Insert(divv,divv);
	invfactory.Solve();
	if(k == 1){
		delta = 0;
	}else if(k == 2){
		delta = 2;
	}else{
		ll basic = 1;
		for(int j = 1;j <= k;j++){
			basic = (basic * j) % TMOD;
		}
		delta = 0;
		for(int j = 3;j < n;j++){
			delta += basic * C(j-3,k-3);
			delta %= TMOD;
		}
	}
	val2 = (((val3 - delta) % TMOD) + TMOD) % TMOD;
	ans = (((val1 * a[1] + val2 * a[2]) % TMOD) + TMOD) % TMOD;
	for(int i = 3;i <= n;i++){
		sum = (sum + a[i]) % TMOD;
	}
	ans += val3 * sum;
	ans = ((ans % TMOD) + TMOD) % TMOD;
	ans = (ans * divv) % TMOD;
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
