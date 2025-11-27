#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ull = unsigned long long;
using pll = pair<ull,ull>;
const int MAXW = 106;
int T,o,m,q;
vector<pll> element;
ull lim[MAXW],siz[MAXW];
pll dp[MAXW];
ull Sum(ull l,ull r){
	if(l > r)return 0;
	return __int128(r - l + 1) * (l + r) / 2;
}
pll dfs(int w,bool limited){//返回答案统计和次数
	if(w == 0)return {0,1};
	if(limited == false && dp[w] != make_pair(-1ull,-1ull))return dp[w];
	ull ret = 0,retTime = 0;
	ull up = limited ? lim[w] : (siz[w] - 1);
	
	//单独处理now == up
	if(limited == true){
		pll res = dfs(w-1,true);
		ret += res.first + up * element[w].second * res.second;
		retTime += res.second;
	}else{
		pll res = dfs(w-1,false);
		ret += res.first + up * element[w].second * res.second;
		retTime += res.second;
	}
	//0 ~ up-1
	if(up >= 1){
		pll res = dfs(w-1,false);
		ret += res.first * up;
		ret += Sum(0,up-1) * element[w].second * res.second;
		retTime += res.second * up;
	}
	if(limited == false)dp[w] = {ret,retTime};
	return {ret,retTime};
}
inline ull Calc(ull n){
	if(n == 0)return 0;
	ull val = n-1;
	int x = int(element.size()) - 1;
//	element.emplace_back(0ull,0ull);
	element[x+1].first = val + element[x].first;//可以选到顶
	for(int i = x;i >= 1;i--){
		siz[i] = element[i+1].first / element[i].first;
		lim[i] = val / element[i].first;
		val %= element[i].first;
		dp[i] = {-1,-1};
	}
	siz[x]++;
	return dfs(x,true).first;
}
inline void Solve(){
	element.clear();
	element.emplace_back(1,1);//1下标
	cin>>m>>q;
	for(int i = 1;i <= m;i++){
		ull a,b;
		cin>>a>>b;
		if(int(element.size()) <= 1){
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
