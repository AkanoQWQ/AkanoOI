#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
namespace Subtask1{
	const int MAXN = 2e5 + 1018 + 1108;
	const int TOT_MAXNM = 2e5 + 1018 + 1108;
	int n,m,k,tp,q;
	pii e[TOT_MAXNM];
	unsigned int lastans;
	int l,r,fa[MAXN];
	int GetFa(int x){
		if(fa[x] == x)return x;
		return fa[x] = GetFa(fa[x]);
	}
	inline void Solve(){
		cin>>n>>m>>k>>tp;
		for(int i = 1;i <= m;i++)cin>>e[i].first>>e[i].second;
		cin>>q;
		while(q--){
			cin>>l>>r;
			if(tp == 1){
				l = (l + lastans) % m + 1;
				r = (r + lastans) % m + 1;
				if(l > r)swap(l,r);
			}
			lastans <<= 1;
			for(int i = 1;i <= n;i++)fa[i] = i;
			for(int i = l;i <= r;i++){
				int u = GetFa(e[i].first),v = GetFa(e[i].second);
				fa[u] = v; 
			}
			int cnt = 0;
			for(int i = 1;i <= n;i++){
				cnt += (GetFa(i) == i);
			}
			if(cnt <= k){
				cout<<"Yes"<<'\n';
				lastans++;
			}else{
				cout<<"No"<<'\n';
			}
		}
		return ;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("data/darkduck/ex_darkduck1.in","r",stdin);
//	freopen("darkduck.out","w",stdout);
	Subtask1::Solve();
	return 0;
}
