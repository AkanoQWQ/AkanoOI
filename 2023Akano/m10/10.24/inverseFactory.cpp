#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
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
const int MAXN = 3e6 + 1018 + 1108;
InverseFactory<long long> invfac;
long long n,p,ans[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>p;
	invfac.MOD = p;
	for(int i = 1;i <= n;i++){
		invfac.Insert(ans[i],i);
	}
	invfac.Solve();
	for(int i = 1;i <= n;i++){
		cout<<ans[i]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
