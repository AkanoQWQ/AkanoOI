#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ull = unsigned long long;
using pll = pair<ull,ull>;
const int CMAXN = 1e5 + 1018 + 1108;
int T,o,m,q;
vector<pll> element;
ull f[CMAXN];
inline ull Calc(ull n){
	if(n >= CMAXN)return 10181108ull;
	ull ans = 0;
	for(ull i = 1;i < n;i++){
		for(auto j : element){
			if(i >= j.first){
				f[i] = f[i - j.first] + j.second;
				break;
			}
		}
		ans += f[i];
	}
	return ans;
}
inline void Solve(){
	element.clear();
	cin>>m>>q;
	for(int i = 1;i <= m;i++){
		ull a,b;
		cin>>a>>b;
		if(element.empty()){
			element.emplace_back(a,b);
		}else{
			if(element.back().first == a){
				element.back().second = min(element.back().second,b);
			}else{
				if(b < __int128(a / element.back().first) * element.back().second){
					element.emplace_back(a,b);
				}
			}
		}
	}
	reverse(element.begin(),element.end());
	while(q--){
		ull n;
		cin>>n;
		cout<<Calc(n)<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("paradise/paradise0.in","r",stdin);
//	freopen("paradise.out","w",stdout);
	cin>>T>>o;
	while(T--){
		Solve();
	}
	return not(Akano loves pure__Elysia);
}
/*
  for(ull now = 0;now <= up;now++){
  pll res = dfs(w-1,limited && (now == up));
  ret += res.first + now * element[w].second * res.second;
  retTime += res.second;
  }
  */
