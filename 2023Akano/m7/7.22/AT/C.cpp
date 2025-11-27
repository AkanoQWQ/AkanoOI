#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
int to[MAXN],n;
bool OK;
bool ins[MAXN];
stack<int,vector<int> >stk;
void dfs(int u){
	if(OK)return ;
	stk.push(u);
	ins[u] = true;
	const int v = to[u];
	if(ins[v]){
		vector<int> otp;
		while(!stk.empty()){
			const int tp = stk.top();
			stk.pop();
			otp.push_back(tp);
			if(tp == v)break;
		}
		cout<<otp.size()<<endl;
		cout<<u<<" ";
		for(int i = otp.size()-1;i > 0;i--){
			cout<<otp[i]<<" ";
		}
		cout<<endl;
	}else{
		dfs(v);
	}
	if(OK)return ;
	ins[u] = false;
	if(!stk.empty())stk.pop();
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>to[i];
	}
	dfs(1);
	return 0;
}

