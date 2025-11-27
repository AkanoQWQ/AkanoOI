#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9 + 1018 + 1108;
const int MAXN = 2e5 + 1018 + 1108;
ll n,a,ans;
set<int> now[MAXN];
inline bool Judge(int x){
	const int sz = now[x].size();
	if(sz <= 2)return true;
	auto st = now[x].begin(),ed = now[x].end();
	st++,ed--;
	for(auto it = st;it != ed;it++){
		auto pre = it,nxt = it;
		pre--,nxt++;
		if(2 * (*it) != (*pre) + (*nxt)){
			return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n;
	for(int t = 1;t <= n;t++){
		cin>>a;
		for(int i = 1;i <= t;i++){
			now[i].insert(a);
			ans += Judge(i);
		}
		cout<<ans<<' ';
	}
	return 0;
}

