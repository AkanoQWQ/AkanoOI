#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 1018 + 1108;
int to[MAXN];
int t,n,a;
bool ins[MAXN],OK;
stack<int,vector<int> >stk;
vector<int> otp;
inline void Clear(){
	OK = false;
	for(int i = 1;i <= n;i++){
		ins[i] = false;
	}
	while(!stk.empty())stk.pop();
	return ;
}
void dfs(int u){
	if(OK)return ;
	stk.push(u);
	ins[u] = true;
	const int v = to[u];
	if(ins[v]){
		OK = true;
		otp.clear();
		while(!stk.empty()){
			const int tp = stk.top();
			stk.pop();
			otp.push_back(tp);
			if(tp == v)break;
		}
		cout<<otp.size()<<'\n';
		for(auto i : otp){
			cout<<i<<" ";
		}
		cout<<'\n';
		return ;
	}
	dfs(v);
	if(OK)return ;
	ins[u] = false;
	if(!stk.empty())stk.pop();
	return ;
}
inline void Solve(){
	cin>>n;
	otp.reserve(n);
	Clear();
	for(int i = 1;i <= n;i++){
		cin>>a;
		to[i] = i-a;
	}
	dfs(1);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		Solve();
	}
	return 0;
}
