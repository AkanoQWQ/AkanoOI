#include<bits/stdc++.h>
using namespace std;
const int MAXN = 6006;
int n,k,a[MAXN][2],ans = 0;
struct seg{
	int l,r;
}s[MAXN];
void calc(){
	int ret = 0;
	for(int i = 1;i <= k;i++){
		ret += max(0,s[i].r-s[i].l);
	}
	if(ret > ans)ans = ret;
	return ;
}
namespace subtask1{
	void dfs(int dep){
		if(dep > n){
			calc();
			return ;
		}
		for(int i = 1;i <= k;i++){
			const int orgl = s[i].l;
			const int orgr = s[i].r;
			if(a[dep][0] > s[i].l)s[i].l = a[dep][0];
			if(a[dep][1] < s[i].r)s[i].r = a[dep][1];
			dfs(dep+1);
			s[i].l = orgl,s[i].r = orgr;
		}
		return ;
	}
}
namespace subtask2{
	seg s2[MAXN];
	void pre(){
		for(int i = 1;i <= k;i++){
			s2[i] = s[i];
		}
		return ;
	}
	void solve(){
		for(int i = 1;i <= k;i++){
			s[i] = s2[i];
		}
		for(int i = k+1;i <= n;i++){
			int bel = (rand()%k) + 1;
			if(a[i][0] > s[bel].l)s[bel].l = a[i][0];
			if(a[i][1] < s[bel].r)s[bel].r = a[i][1];
		}
		calc();
	}
	void mainsolve(){
		pre();
		while(clock() < 920){
			solve();
		}
		return ;
	}
}
int main(){
	freopen("lunatic.in","r",stdin);
	freopen("lunatic.out","w",stdout);
	srand(time(0));
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i][0]>>a[i][1];
		if(i <= k){
			s[i].l = a[i][0];
			s[i].r = a[i][1];
		}
	}
	if(n <= 12 || (k <= 4 && n <= 20)){
		subtask1::dfs(k+1);
	}else{
		subtask2::mainsolve();
	}
	cout<<ans;
	return 0;
}
