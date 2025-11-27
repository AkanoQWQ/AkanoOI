#pragma GCC target("avx")
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ull = unsigned long long;
using ll = long long;
using pii = pair<short,short>;
const int MAXN = 2006 + 1018 + 1108 + 1000;
const int SIZE = 1e5;
const int base = 13;
int n;
string str;

template<typename T,int SIZE>
class ClearableArray{
private:
	T _content[SIZE];
	bool _vis[SIZE];
	queue<int> clearQueue;
public:
	T& operator[](int _x){
		if(!_vis[_x]){
			_vis[_x] = true,clearQueue.push(_x);
		}
		return _content[_x];
	}
	inline T& at(int _x){
		assert(_x < SIZE && _x >= 0);
		return operator[](_x);
	}
	inline void Clear(){
		while(!clearQueue.empty()){
			const int _u = clearQueue.front();
			clearQueue.pop();
			_vis[_u] = false;
			_content[_u] = T();
		}
		return ;
	}
	inline int Size(){
		return clearQueue.size();
	}
	ClearableArray(){
		memset(_content,0,sizeof(_content));
		memset(_vis,0,sizeof(_vis));
		return ;
	}
};

template<typename Key,typename Val>
struct HashMapNode{
	Key key;
	Val val;
	int nxt;//索引范围int,也许需要使用更规范的类型
	HashMapNode(){key = Key(),val = Val(),nxt = 0;}
	HashMapNode(Key _key){key = _key,val = Val(),nxt = 0;}
};
template<typename Key,typename Val,typename HashClass,int SIZE>//SIZE一定是小于int的,索引需要装得下 
class HashMap{
	typedef HashMapNode<Key,Val> Node;
	typedef typename vector<Node>::iterator iterator;//为了和普通容器保持一致 
private:
	HashClass hasher = HashClass();
	ClearableArray<int,SIZE> head;
	int tot;
	vector<Node> content;
	inline int FindIndex(const Key& key){
		const int hashVal = hasher(key) % SIZE;
		for(int i = head[hashVal];i;i = content[i].nxt){
			if(content[i].key == key)return i;
		}
		return 0;
	}
	inline int Insert(const Key& key){
		const int hashVal = hasher(key) % SIZE;
		int lst = head[hashVal];
		head[hashVal] = ++tot;
		content.emplace_back(key);
		content[tot].nxt = lst;
		return tot;
	}
public:
	iterator begin(){//方便 for(auto) 遍历 
		return ++content.begin();//初始是0,要加一个元素 
	}
	iterator end(){
		return content.end();
	}
	Val& operator[](const Key& key){
		int idx = FindIndex(key);
		if(idx == 0)idx = Insert(key);
		return content[idx].val;
	}
	inline bool Find(const Key& key){
		int idx = FindIndex(key);
		return (idx != 0);
	}
	inline void Clear(){
		content.clear();
		content.emplace_back();//初始一个空元素,下标为0,非常重要 
		head.Clear();
		tot = 0;
		return ;
	}
	HashMap(){
		Clear();
		return ;
	}
	HashMap(int initVal){
		content.reserve(initVal);
		Clear();
		return ;
	}
};

/*哈希相关部分*/
ull hashVal[MAXN],basep[MAXN];
inline void GetHash(){
	basep[0] = 1;
	for(int i = 1;i <= n;i++){
		basep[i] = basep[i-1] * base;
	}
	for(int i = 1;i <= n;i++){
		hashVal[i] = hashVal[i-1] * base + (str[i] - '0' + 1);
	}
	return ;
}
inline ull Cut(int l,int r){
	return hashVal[r] - hashVal[l-1] * basep[r-l+1];
}
int matchCnt[MAXN][MAXN];
inline int GetMatch(int pos){
	int ret = 0;
	for(int len = 1;len <= n;len++){
		matchCnt[pos][len] = matchCnt[pos][len-1];
		if(pos - len >= 1 && pos + len - 1 <= n && Cut(pos-len,pos-1) == Cut(pos,pos+len-1)){
			matchCnt[pos][len]++;
		}
	}
	return ret;
}
inline void ReadIn(){
	cin>>str;
	n = str.length();
	str = "." + str;
	return ;
}
const int SIZEE = 1e6;
HashMap<ull,int,hash<ull>,SIZEE> bucket;
vector<pii> vecs[MAXN];
int cnt = 0;
inline void Push(int len){//把子串装进桶里
	bucket.Clear();
	for(int i = 1;i <= cnt;i++){
		vecs[i].clear();
	}
	cnt = 0;
	for(int l = 1;l + len - 1 <= n;l++){
		const int r = l + len - 1;
		int& head = bucket[Cut(l,r)];
		if(head == 0)head = ++cnt;
		vecs[head].emplace_back(l,r);
	}
	return ;
}
inline ll Calc(vector<pii>& vec){
	ll ret = 0;
	auto it = vec.begin();
	for(auto val : vec){
		while(it != vec.end() && it->first < val.second+2){
			it++;
		}
		int after = vec.end() - it;
		ret += 1ll * matchCnt[val.first][val.second-val.first+1-1] * after;
	}
	return ret;
}
inline ll Solve(){
	ll ans = 0;
	for(int i = 1;i <= cnt;i++){
		ans += Calc(vecs[i]);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	GetHash();
	for(int i = 1;i <= n;i++)GetMatch(i);//GetMatch
	ll ans = 0;
	for(int i = 1;i <= n;i++)vecs[i].reserve(n);
	for(int len = 1;len <= n;len++){
		Push(len);
		ans += Solve();
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
