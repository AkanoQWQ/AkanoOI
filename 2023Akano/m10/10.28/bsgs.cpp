#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;

fast

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
	int head[SIZE],tot;
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
		memset(head,0,sizeof(head));
		tot = 0;
		return ;
	}
	HashMap(){//初始一个空元素,下标为0,非常重要 
		Clear();
		content.emplace_back();
		return ;
	}
	HashMap(int initVal){
		Clear();
		content.reserve(initVal);
		content.emplace_back();
		return ;
	}
};
const int SIZE = 1e6;
ll p,b,n;
inline ll KSM(ll a,ll b,ll mod){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1; 
	}
	return ret;
}
inline ll BSGS(ll a,ll b,ll mod){//a^x === b (MOD mod)
	HashMap<ll,ll,hash<ll>,SIZE> mp;
	const ll up = sqrt(mod) + 1;
	ll now = b;
	for(ll power = 0;power <= up;power++){
		mp[now] = power;
		now = (now * a) % mod;
	}
	ll base = KSM(a,up,mod);
	now = base;
	for(ll power = 1;power <= up;power++){
		if(mp.Find(now)){
			return power * up - mp[now];
		}
		now = (now * base) % mod;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>p>>b>>n;
	int res = BSGS(b,n,p);
	if(res != -1){
		cout<<res<<endl;
	}else{
		cout<<"no solution"<<endl;
	}
	return not(Akano loves pure__Elysia);
}
