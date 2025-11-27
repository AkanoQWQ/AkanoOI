#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 1018 + 1108;
constexpr int INF = 20061018 + 20061108;
int lst[MAXN],ch2pos[MAXN],minr[MAXN];
int T,n,m,s[MAXN],t[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("qlx.in","r",stdin);
	freopen("qlx.out","w",stdout);
	for(int i = 0;i < MAXN;i++){
		ch2pos[i] = -1;
		lst[i] = INF;
	}
	cin>>T;
	while(T--){
		cin>>n>>m;
		int maxt = 0;
		for(int i = 1;i <= n;i++){
			cin>>s[i];
		}
		for(int i = 1;i <= m;i++){
			cin>>t[i];
			maxt = max(maxt,t[i]);
		}
		for(int i = 1;i <= m;i++){
			ch2pos[t[i]] = i;
		}
		int ans = INF,anspos = -1;
		for(int i = n;i >= 1;i--){
			minr[i] = INF;
			if(s[i] > maxt)continue; 
			if(ch2pos[s[i]] == m){
				minr[i] = i;
			}else if(ch2pos[s[i]] > 0){
				if(lst[t[ch2pos[s[i]]+1]] <= n){
					minr[i] = minr[lst[t[ch2pos[s[i]]+1]]];
				}
			}
			if(ch2pos[s[i]] == 1){
				if(minr[i] <= n && minr[i] - i <= ans){
					anspos = i;
					ans = minr[i] - i;
				}
			}
			lst[s[i]] = i;
		}
		if(anspos == -1){
			cout<<anspos<<'\n';
		}else{
			cout<<anspos<<' '<<minr[anspos]<<'\n';
		}
		for(int i = 1;i <= m;i++){
			ch2pos[t[i]] = -1;
		}
		for(int i = 1;i <= n;i++){
			if(s[i] <= maxt)lst[s[i]] = INF;
		}
	}
	return 0;
}

