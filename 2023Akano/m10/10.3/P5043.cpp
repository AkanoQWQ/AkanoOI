#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ull = unsigned long long;
const int MAXN = 108;
const ull base = 2006101811082121;
ull basePow[MAXN];
struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m;
inline void Clear(){
	for(int i = 1;i <= n;i++)head[i] = 0;
	cnt = 0;
	return ;
}

int root1,root2,mss[MAXN],siz[MAXN];
void Find(int u,int fa){
	siz[u] = 1,mss[u] = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		Find(v,u);
		siz[u] += siz[v];
		mss[u] = max(mss[u],siz[v]);
	}
	mss[u] = max(mss[u],n - siz[u]);
	if(mss[u] < mss[root1]){
		root1 = u,root2 = 0;
	}else if(mss[u] == mss[root1]){
		root2 = u;
	}
	return ;
}
unordered_map<ull,int> minNo;
ull GetHash(int u,int fa){
	ull ret = 1;
	siz[u] = 1;
	vector<pair<int,ull> > vec;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		ull nxt = GetHash(v,u);
		siz[u] += siz[v];
		vec.emplace_back(siz[v],nxt);
	}
	sort(vec.begin(),vec.end());
	for(auto node : vec){
		ret *= basePow[node.first];
		ret += node.second;
	}
	ret *= base;
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("P5043_2.in","r",stdin);
	mss[0] = 1e9;
	cin>>m;
	basePow[0] = 1;
	for(int i = 1;i < MAXN;i++){
		basePow[i] = basePow[i-1] * base;
	}
	for(int i = 1;i <= m;i++){
		cin>>n;
		Clear();
		for(int i = 1;i <= n;i++){
			int fa;
			cin>>fa;
			if(fa == 0)continue;
			AddEdge(i,fa),AddEdge(fa,i);
		}
		root1 = root2 = 0;
		Find(1,0);
		ull hashVal = GetHash(root1,0);
		if(root2 != 0)hashVal = min(hashVal,GetHash(root2,0));
		if(minNo[hashVal] == 0)minNo[hashVal] = i;
		cout<<minNo[hashVal]<<endl;
	}
	return not(Akano loves pure__Elysia);
}

