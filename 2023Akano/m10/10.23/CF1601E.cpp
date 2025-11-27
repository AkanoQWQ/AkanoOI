#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MAXN = 3e5 + 1018 + 1108;
const int INF = 1e9 + 1018 + 1108;
template<typename T,int SIZE>
class SparseTable{
private:
	T vals[SIZE][int(ceil(log2(SIZE)))];
	int logval[SIZE];
public:
	template<typename Itor>
	inline void Build(Itor _begin,Itor _end){//左闭右开
		int cnt = 0,nowlog = 0;
		for(Itor it = _begin;it != _end;it++){
			vals[++cnt][0] = *it;
		}
		for(int i = 2;i <= cnt;i++){
			logval[i] = logval[i/2] + 1;
		}
		nowlog = logval[cnt];
		for(int i = 1;i <= nowlog;i++){
			for(int j = 1;j <= cnt;j++){
				const int nxt = min(j + (1<<(i-1)),cnt);
				vals[j][i] = min(vals[j][i-1],vals[nxt][i-1]);
			}
		}
		return ;
	}
	inline T Query(int l,int r){
		int nowlog = logval[r - l + 1];
		return min(vals[l][nowlog],vals[r - (1<<nowlog) + 1][nowlog]);
	}
};
SparseTable<pii,MAXN> st;
int n,q,k;
pii pricePos[MAXN];
struct Query{
	int l,r,id;
	Query() = default;
	Query(int _l,int _r,int _id){
		l = _l,r = _r,id = _id;
		return ;
	}
};
vector<Query> query[MAXN];
int stk[MAXN];
ll tot[MAXN],ans[MAXN],price[MAXN];
inline int FindKnum(int l,int r,int mod) {
	int L = l / k * k,R = r / k * k;
	if(L+mod < l)L += k;
	if(R+mod > r)R -= k;
	if(L > R) return 0;
	return (R - L) / k + 1;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q>>k;
	for(int i = 1;i <= n;i++){
		cin>>price[i];
		pricePos[i] = {price[i],i};
	}
	for(int i = 1,l,r;i <= q;i++){
		cin>>l>>r;
		query[l].emplace_back(l,r,i);
	}
	st.Build(pricePos+1,pricePos+n+1);
	for(int mod = 0;mod < k;mod++){//mod == k  ===  mod == 0
		int tail = 0;
		vector<int> imp;
		for(int i = mod;i <= n;i += k){
			if(i == 0)continue;
			if(i-k >= 1 && k != 1){
				auto best = st.Query(i - k + 1,i - 1);
				imp.push_back(best.second);
			}
			imp.push_back(i);
		}
		reverse(imp.begin(),imp.end());
		for(auto i : imp){
			while(tail && price[stk[tail]] >= price[i])--tail;
			stk[++tail] = i;
			tot[tail] = tot[tail-1] + price[i] * FindKnum(i,stk[tail-1]-1,mod);
			if(i % k == mod){
				for(auto nowq : query[i]){
					int pos = ((nowq.r - nowq.l) / k) * k + nowq.l;
					int l = 1,r = tail + 1;
					while(l < r){
						const int mid = (l + r) >> 1;
						if(stk[mid] <= pos){
							r = mid;
						}else{
							l = mid + 1;
						}
					}
					ans[nowq.id] = tot[tail] - tot[r] + price[stk[r]] * FindKnum(stk[r],pos,mod);
				}
			}
		}
	}
	for(int i = 1;i <= q;i++){
		cout<<ans[i]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
