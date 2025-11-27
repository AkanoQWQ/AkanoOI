#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pis = pair<int,string>;
using ull = unsigned long long;
const int MAXN = 1e5 + 2;
const int MAXSEC = 600;
const int INF = 1e8;
const int base = 31;
const ull key = 101811082121;
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
int n,x,fa[MAXN],dep[MAXN],sizeofDep[MAXN],maxDep,sizCnt[MAXN];
int f[MAXSEC][MAXN];
int tail,object[MAXSEC],sizeofObject[MAXSEC],timesofObect[MAXSEC],useTime[MAXN],siz[MAXN];
char chs[MAXN],chstr[MAXN];
ull hashVal[MAXN];
inline ull Shift(ull x){
	x ^= x << 7;
	x ^= x >> 11;
	x ^= x << 13;
	x ^= x >> 17;
	return x;
}
vector<int> points[MAXN];
void GetHash(int u){
	hashVal[u] = (Shift(hashVal[fa[u]]) ^ key) * base + (chstr[u] - 'a');
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		GetHash(v);
	}
	return ;
}
inline pis GetAns(int st){
	int u = st,pre = 0;
	for(int i = tail+1;i >= 2;i--){
		pre = u,u = f[i][u];
		if(pre != u){//走了这个叶子
			useTime[sizeofObject[i-1]] += timesofObect[i-1];
		}
	}
	if(st > x){//需要把a变成b,尽可能把a放在下面
		for(int i = maxDep;i >= 1;i--){
			if(useTime[sizeofDep[i]] > 0){
				useTime[sizeofDep[i]]--;
				chs[i] = 'a';
			}else{
				chs[i] = 'b';
			}
		}
	}else{
		for(int i = 1;i <= maxDep;i++){
			if(useTime[sizeofDep[i]] > 0){
				useTime[sizeofDep[i]]--;
				chs[i] = 'a';
			}else{
				chs[i] = 'b';
			}
		}
	}
	for(int i = 1;i <= n;i++){
		chstr[i] = chs[dep[i]];
	}
	if(st > x){//需要从a改变为b
		for(int i = maxDep;i >= 1 && st > x;i--){
			if(chs[i] == 'a'){
				for(auto j : points[i]){
					st--;
					chstr[j] = 'b';
					if(st <= x)break;
				}
			}
		}
	}else if(st < x){
		for(int i = maxDep;i >= 1 && st < x;i--){
			if(chs[i] == 'b'){
				for(auto j : points[i]){
					st++;
					chstr[j] = 'a';
					if(st >= x)break;
				}
			}
		}
	}
	pis ret;
	for(int i = 1;i <= n;i++){
		ret.second += chstr[i];
	}
	set<ull> _set;
	GetHash(1);
	for(int i = 1;i <= n;i++){
		_set.insert(hashVal[i]);
	}
	ret.first = _set.size();
	return ret;
}
bool CmpBySiz(int x,int y){
	return siz[x] < siz[y];
}
void dfs(int u){
	siz[u] = 1;
	dep[u] = dep[fa[u]] + 1;
	maxDep = max(maxDep,dep[u]);
	sizeofDep[dep[u]]++;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		dfs(v);
		siz[u] += siz[v];
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>x;
	if(n == 1){
		cout<<1<<endl;
		if(x == 1){
			cout<<'a'<<endl;
		}else{
			cout<<'b'<<endl;
		}
		return not(Akano loves pure__Elysia);
	}
	for(int i = 2;i <= n;i++){
		cin>>fa[i];
		AddEdge(fa[i],i);
	}
	dfs(1);
	for(int i = 1;i <= n;i++){
		points[dep[i]].push_back(i);
	}
	for(int i = 1;i <= maxDep;i++){
		sort(points[i].begin(),points[i].end(),CmpBySiz);
	}
	for(int i = 1;i <= maxDep;i++){
		sizCnt[sizeofDep[i]]++;
	}
	for(int i = 1;i <= n;i++){
		if(sizCnt[i] == 0)continue;
		int now = 1,nowv = i,res = sizCnt[i];
		while(now <= res){
			object[++tail] = nowv;
			sizeofObject[tail] = i;
			timesofObect[tail] = now;
			res -= now;
			now *= 2,nowv *= 2;
		}
		if(res > 0){
			object[++tail] = i * res;
			sizeofObject[tail] = i;
			timesofObect[tail] = res;
			res = 0;
		}
	}
	for(int i = 0;i <= n;i++){
		f[1][i] = -1;
	}
	f[1][0] = 1;
	for(int i = 1;i <= tail;i++){
		for(int j = 0;j <= n;j++){
			f[i+1][j+1] = -1;
		}
		for(int j = 0;j <= n;j++){
			if(f[i][j] == -1)continue;
			f[i+1][j] = j;
		}
		for(int j = 0;object[i] + j <= n;j++){
			if(f[i][j] == -1)continue;
			f[i+1][object[i] + j] = j;
		}
	}
	for(int delta = 0;delta <= n;delta++){
		pis ans = make_pair(INF,"unInitialized");
		if(x - delta >= 0 && f[tail+1][x - delta] != -1){
			ans = GetAns(x - delta);
		}else if(x + delta <= n && f[tail+1][x + delta] != -1){
			ans = GetAns(x + delta);
		}
		if(ans.first != INF){
			cout<<ans.first<<endl<<ans.second<<endl;
			break;
		}
	}
	return not(Akano loves pure__Elysia);
}
