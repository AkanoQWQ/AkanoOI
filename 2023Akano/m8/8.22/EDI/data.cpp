#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 3e5 + 1018 + 1108;
ll fa[MAXN],a[MAXN],b[MAXN],dir[MAXN],ans,n;
int GetFa(int x){
	if(fa[x] == x)return x;
	return fa[x] = GetFa(fa[x]);
}
struct Node{
	ll a,b,id;
	Node(){a = b = id = 0;}
	Node(ll _a,ll _b,ll _id){a = _a,b = _b,id = _id;}
};
bool operator<(Node na,Node nb){
	if(na.a * nb.b != nb.a * na.b)return na.a * nb.b < nb.a * na.b;
	return na.id < nb.id;
}
set<Node> st;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++)fa[i] = i;
	for(int i = 2;i <= n;i++){
		cin>>dir[i];
	}
	for(int i = 1;i <= n;i++){
		Node nd;
		cin>>a[i]>>b[i];
		st.insert(Node(a[i],b[i],i));
	}
	while(!st.empty()){
		auto it = st.begin();
		const int id = (*it).id;
		st.erase(st.begin());
		if(!dir[id])continue;
		const int nowfa = GetFa(dir[id]);
		ans += b[nowfa] * a[id];
		auto fit = st.find(Node(a[nowfa],b[nowfa],nowfa));
		if(fit != st.end()){
			st.erase(fit);
		}
		fa[id] = nowfa;
		a[nowfa] += a[id],b[nowfa] += b[id];
		st.insert(Node(a[nowfa],b[nowfa],nowfa));
	}
	cout<<ans;
	return 0;
}
