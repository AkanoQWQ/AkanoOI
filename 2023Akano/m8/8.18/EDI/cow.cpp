#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MOD = 1e9 + 7;
const int inv2 = (MOD+1) / 2;
const int MAXN = 1e5 + 1018 + 1108;
const ll INF = 1e18 + 10181108;
int u;
inline ll Sum(ll l,ll r){
	if(l > r)return 0;
	return (((((r - l + 1) % MOD) * ((l + r) % MOD)) % MOD) * inv2) % MOD;
}
struct Node{
	ll overflow,cnt,ans,lof;//left overflow
};
ll arr[MAXN],tail;
class SegmentTree{
	private:
		Node node[MAXN * 4];
		pll Query(int p,int l,int r,ll left){
			if(l == r)return make_pair(arr[l] + node[p].cnt + left - 1,node[p].ans);
			const int mid = (l + r) >> 1;
			const ll nowl = arr[mid+1] - arr[l] - node[p*2].cnt;
			if(left <= nowl)return Query(p*2,l,mid,left);
			pll ret = Query(p*2+1,mid+1,r,left - nowl + node[p*2].overflow);
			ret.second += node[p*2].ans + node[p].lof;
			return ret;
		}
		inline void PushUp(int p,int l,int r){
			const int mid = (l + r) >> 1;
			const int ls = p*2,rs = p*2+1;
			const ll res = arr[r+1] - arr[mid+1] - node[rs].cnt;
			if(node[ls].overflow > res){
				node[p].cnt = node[ls].cnt + arr[r+1] - arr[mid+1];
				node[p].ans = node[ls].ans + Sum(arr[mid+1],arr[r+1]-1);
				node[p].overflow = node[ls].overflow + node[rs].overflow - res;
				node[p].lof = -1;
			}else{
				node[p].cnt = node[ls].cnt + node[rs].cnt + node[ls].overflow;
				node[p].overflow = node[rs].overflow;
				pll far = make_pair(arr[mid+1]-1,0);
				if(node[ls].overflow)far = Query(rs,mid+1,r,node[ls].overflow);
				node[p].lof = Sum(arr[mid+1],far.first) - far.second;
				node[p].ans = node[ls].ans + node[rs].ans + node[p].lof;
			}
			return ;
		}
		void Change(int p,int l,int r,int OBJ,ll _val){
			if(l == r){
				node[p].cnt = min(_val,arr[l+1]-arr[l]);
				node[p].ans = Sum(arr[l],arr[l] + node[p].cnt - 1);
				node[p].overflow = _val - node[p].cnt;
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJ)Change(p*2,l,mid,OBJ,_val);
			if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,_val);
			PushUp(p,l,r);
			return ;
		}
	public:
		inline void Change(int OBJ,ll _val){
			Change(1,1,tail,OBJ,_val);
			return ;
		}
		inline ll Query(){
			return node[1].ans;
		}
}tr;
vector<ll> vec;
ll d[MAXN],b[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>u;
	for(int i = 1;i <= u;i++){
		cin>>d[i]>>b[i];
		vec.push_back(d[i]);
	}
	sort(vec.begin(),vec.end());
	auto it = unique(vec.begin(),vec.end());
	vec.erase(it,vec.end());
	for(auto i : vec)arr[++tail] = i;
	arr[tail+1] = INF;
	for(int i = 1;i <= u;i++){
		int pos = lower_bound(arr+1,arr+tail+1,d[i]) - arr;
		tr.Change(pos,b[i]);
		cout<<((tr.Query() % MOD) + MOD) % MOD<<'\n';
	}
	return 0;
}
