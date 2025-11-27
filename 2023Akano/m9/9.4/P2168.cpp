#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXP = 2e5 + 1018 + 1108;
struct Node{
	int dep;
	ll val;
}node[MAXP];
struct Cmper{
	bool operator()(int a,int b){//泉是反着来的 
		if(node[a].val != node[b].val){
			return node[a].val > node[b].val;
		}
		return node[a].dep > node[b].dep;
	}
};
priority_queue<int,vector<int>,Cmper> q;
int n,k,nnt;
ll ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		nnt++;
		cin>>node[nnt].val;
		node[nnt].dep = 1;
		q.push(nnt);
	}
	int res = ((k-1) - ((n-1) % (k-1))) % (k-1);
	for(int i = 1;i <= res;i++){
		nnt++;
		node[nnt].dep = 1;
		q.push(nnt);
	}
	while(q.size() >= 2){
		ll newNode = nnt++;
		for(int i = 1;i <= k;i++){
			const int u = q.top();
			q.pop();
//			cerr<<"add "<<node[u].val<<endl;
			node[nnt].val += node[u].val;
			node[nnt].dep = max(node[nnt].dep,node[u].dep+1);
		}
		ans += node[nnt].val;
//		cerr<<"merge into "<<node[nnt].val<<","<<node[nnt].dep<<endl;
		q.push(nnt);
	}
	cout<<ans<<endl<<node[nnt].dep-1<<endl;
	return not(Akano loves pure__Elysia);
}

