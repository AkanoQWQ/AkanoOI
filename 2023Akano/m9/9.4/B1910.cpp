#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 56;
const int MAXP = 2006 + 1018 + 1108;
int l[MAXP],r[MAXP],nnt,n;
struct BinaryTree{
	int id,val;
	BinaryTree(int _id,int _val){id = _id,val = _val;}
};
bool operator<(BinaryTree bt1,BinaryTree bt2){//大小根堆要反着来awa 
	if(bt1.val != bt2.val)return bt1.val > bt2.val;
	return bt1.id > bt2.id;
}
priority_queue<BinaryTree> q;
vector<string> ans;
void dfs(int u,string code){
	if(l[u] == 0 || r[u] == 0){
		ans.push_back(code);
		return ;
	}
	dfs(l[u],code+"0"),dfs(r[u],code+"1");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		++nnt;
		int val;
		cin>>val;
		q.push(BinaryTree(nnt,val));
	}
	while(q.size() >= 2){
		const BinaryTree bt1 = q.top();
		q.pop();
		const BinaryTree bt2 = q.top();
		q.pop();
		++nnt;
		l[nnt] = bt1.id,r[nnt] = bt2.id;
		q.push(BinaryTree(nnt,bt1.val + bt2.val));
	}
	dfs(nnt,"");
	sort(ans.begin(),ans.end());
	for(auto i : ans)cout<<i<<endl;
	return not(Akano loves pure__Elysia);
}
