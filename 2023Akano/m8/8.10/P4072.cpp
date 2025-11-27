#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MAXN = 2006 + 1018;
const int MAXM = MAXN;
const ll INF = 1e16;
ll len[MAXN],sum[MAXN],dp[MAXM][MAXN],n,m,arr[2];
struct KDP{
	set<pll> st;
	inline void Insert(ll x,ll y){
		while(st.size() > 1){
			auto it = --st.end(),pre = --st.end();
			pre--;
			
			if(double((*pre).second - (*it).second) / double((*pre).first - (*it).first) > double(y - (*it).second) / double(x - (*it).first)){
				st.erase(it);
			}else{
				break;
			}
		}
		st.insert(make_pair(x,y));
		return ;
	}
	inline void Clear(){
		st.clear();
		return ;
	}
	inline ll Query(ll k,ll j){
		while(st.size() > 1){
			auto it = st.begin(),nxt = ++st.begin();
			if((*nxt).second - (*it).second < ((*nxt).first - (*it).first) * k){
				st.erase(it);
			}else{
				break;
			}
		}
		auto now = *(st.begin());
		return now.second - k * now.first + m * sum[j] * sum[j] - 2 * sum[n] * sum[j];
	}
}kdp;
inline void Insert(ll i,ll j){
	kdp.Insert(sum[j],m * sum[j] * sum[j] + 2 * sum[n] * sum[j] + dp[i][j]);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("P4072.in","r",stdin);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>len[i];
		sum[i] = sum[i-1] + len[i];
	}
	for(int i = 1;i <= n;i++)dp[0][i] = INF;
	for(int i = 0;i <= m;i++)dp[i][0] = sum[n] * sum[n];
	for(int i = 1;i <= m;i++){
		kdp.Clear();
		for(int j = 1;j <= n;j++){
			Insert(i-1,j-1);
			dp[i][j] = kdp.Query(2 * m * sum[j],j);
		}
	}
	cout<<dp[m][n]<<endl;
	return 0;
}
