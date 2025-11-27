#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ull base = 200610181108131437;
const int MAXN = 1e5 + 1018 + 1108;
const int MOD = 1e9 + 7;
mt19937_64 rng(time(0));
//前向星部分
struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],eCnt;
inline void AddEdge(int from,int to){
	e[++eCnt].to = to;
	e[eCnt].nxt = head[from];
	head[from] = eCnt;
	return ;
}
//基础部分
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
inline ll Div(ll a,ll b){
	return (a * KSM(b,MOD-2)) % MOD;
}
inline vector<int> KMP(const vector<ull>& vec){
	int sizVec = vec.size();
	vector<int> pi(sizVec);
	for(int i = 1;i < sizVec;i++){
		int j = pi[i-1];
		while(j > 0 && vec[i] != vec[j])j = pi[j-1];
		if(vec[i] == vec[j])j++;
		pi[i] = j;
	}
	return pi;
}

//预处理部分
ll step[MAXN],basePow[MAXN],invStep[MAXN];
inline void Init(){
	step[0] = basePow[0] = 1;
	for(int i = 1;i <= 1e5+20;i++){
		step[i] = (step[i-1] * i) % MOD;
		basePow[i] = (basePow[i-1] * base) % MOD;
		invStep[i] = KSM(step[i],MOD-2);
	}
	return ;
}
ll T,n;

struct Count{//说实话,这个结构其实是贺过来的()
	ll ans/*答案*/,siz/*当前大小*/,appear/*出现次数*/;
	Count() = default;
	Count(ll _ans,ll _siz,ll _appear){
		ans = _ans,siz = _siz,appear = _appear;
		return ;
	}
};

namespace DisjointSet{//并查集
	int fa[MAXN];
	int Find(int x){
		if(fa[x] == x)return x;
		return fa[x] = Find(fa[x]);
	}
	inline bool Merge(int x,int y){
		x = Find(x),y = Find(y);
		if(x == y)return false;
		fa[x] = y;
		return true;
	}
	inline void Init(){
		for(int i = 1;i <= n;i++)fa[i] = i;
		return ;
	}
}

//图相关信息
bool vis[MAXN],onCircle[MAXN];
int pre[MAXN];
int siz[MAXN],hashVal[MAXN],ansCnt[MAXN];

inline void ReadIn(){
	for(int u = 1;u <= n;u++){
		int a;
		cin>>a;
		AddEdge(a,u);
		pre[u] = a;
	}
	return ;
}
inline void Clear(){
	for(int i = 1;i <= n;i++){
		vis[i] = onCircle[i] = false;
		head[i] = false;
	}
	eCnt = 0;
	DisjointSet::Init();
	return ;
}
inline ll UniqueCount(map<ull,Count>& mp){
	ll ret = 1,totSize = 0;
	for(auto pr : mp){
		const Count& cnt = pr.second;
		for(int t = 1;t <= cnt.appear;t++){
			ret = (((ret * cnt.ans) % MOD) * invStep[cnt.siz]) % MOD;
		}
		totSize += cnt.siz * cnt.appear;
		ret = (ret * invStep[cnt.appear]) % MOD;
	}
	ret = (ret * step[totSize]) % MOD;
	return ret;
}
void dfs(int u){
	siz[u] = 1,vis[u] = true;
	map<ull,Count> mp;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(vis[v])continue;
		dfs(v);
		siz[u] += siz[v];
		int oldAPPEAR = mp[hashVal[v]].appear;
		mp[hashVal[v]] = Count(ansCnt[v],siz[v],oldAPPEAR+1);
	}
	ansCnt[u] = (UniqueCount(mp) * siz[u]) % MOD;
	hashVal[u] = 1;
	for(auto pr : mp){
		const Count& cnt = pr.second;
		for(int i = 1;i <= cnt.appear;i++){
			hashVal[u] *= basePow[cnt.siz];//为什么这个地方要乘2?????
			hashVal[u] += pr.first;
		}
	}
	hashVal[u] *= base;
	return ;
}
inline int MinRep(vector<ull>& vec){//最小表示法
	const int sizeVec = vec.size();
	int k = 0,i = 0,j = 1;
	while(k < sizeVec && i < sizeVec && j < sizeVec) {
		if(vec[(i + k) % sizeVec] == vec[(j + k) % sizeVec]){
			k++;
		}else{
			if(vec[(i + k) % sizeVec] > vec[(j + k) % sizeVec]){
				i += k + 1;
			}else{
				j += k + 1;
			}
			if(i == j)i++;
			k = 0;
		}
	}
	return min(i,j);
}
inline void SolveCircle(int ST,ull& treeHash,ll& treeAns,ll& treeSize){
	treeSize = 0,treeAns = 1;
	vis[ST] = true;
	vector<ull> hashSet,nxt;
	for(int u = -pre[ST];u != pre[ST];u = pre[u]){
		if(u < 0)u = -u;
		dfs(u);
		treeSize += siz[u];
		treeAns = (((treeAns * ansCnt[u]) % MOD) * invStep[siz[u]]) % MOD;//step[siz[u]]
		hashSet.push_back(hashVal[u]);
	}
	treeAns = (treeAns * step[treeSize]) % MOD;//这是为什么?
	int start = MinRep(hashSet);
	treeHash = 0;
	for(int i = start;i < int(hashSet.size());i++){
		nxt.push_back(hashSet[i]);
	}
	for(int i = 0;i < start;i++){
		nxt.push_back(hashSet[i]);
	}
	for(auto i : nxt){
		treeHash = treeHash * base + i;
	}
	vector<int> border = KMP(nxt);
	int vecT = int(nxt.size()) - border.back();
	treeAns = Div(treeAns,int(nxt.size()) / vecT);
	return ;
}
inline ll Solve(){
	ll ret = 0;
	Clear();
	ReadIn();
	for(int u = 1;u <= n;u++){
		const int v = pre[u];
		if(DisjointSet::Find(u) == DisjointSet::Find(v)){
			onCircle[u] = true;
		}else{
			DisjointSet::Merge(u,v);
		}
	}
	map<ull,Count> count;
	for(int u = 1;u <= n;u++){
		if(!onCircle[u])continue;
		ull treeHash = 0;
		ll treeAns = 0,treeVal = 0;
		SolveCircle(u,treeHash,treeAns,treeVal);
		int oldAPPEAR = count[treeHash].appear;
		count[treeHash] = Count(treeAns,treeVal,oldAPPEAR+1);
	}
	ret = UniqueCount(count);
	ret = (ret - 1 + MOD) % MOD;//减去开头的一种情况
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	Init();
	cin>>T;
	while(T--){
		cin>>n;
		cout<<Solve()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
