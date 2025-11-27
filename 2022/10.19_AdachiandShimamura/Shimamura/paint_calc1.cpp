#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n,m,koloro,k[206],cnt,ans;
struct edge{
	int a,b;
}ce;
vector<edge> e;
bool calc(){
	for(int i = 0;i < e.size();i++){
		if(k[e[i].a] == k[e[i].b])return false;
	}
	return true;
}
void dfs(int dep){
	if(dep >= n+1){
		cnt += calc();
		if(cnt >= MOD)cnt -= MOD;
		return ;
	}
	for(int i = 1;i <= koloro;i++){
		k[dep] = i;
		dfs(dep+1);
	}
	return ;
}
int main(){
	freopen("paintr2.in","r",stdin);
	freopen("paint2.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int a,b;
		cin>>a>>b;
		ce.a = a,ce.b = b;
		e.push_back(ce);
	}
	for(int i = 2;i <= n;i++){
		koloro = i,cnt = 0;
		dfs(1);
		cout<<i<<" finished "<<endl;
		cnt %= MOD;
		ans ^= cnt;
	}
	cout<<ans;
	
	return 0;
}

