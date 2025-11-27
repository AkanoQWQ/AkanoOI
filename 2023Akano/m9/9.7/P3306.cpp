#include<bits/stdc++.h>
using namespace std;
using ll = long long;

namespace container{
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
}

ll KSM(ll a,ll b,ll mod){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}
inline void Execute(ll& x,const ll& mod){
	x = ((x % mod) + mod) % mod;
	return ;
}
ll Div(ll a,ll b,ll mod){
	Execute(a,mod),Execute(b,mod);
	return (a * KSM(b,mod-2,mod) + mod) % mod;
}
const int SIZE = 7e4;
container::HashMap<ll,ll,hash<ll>,SIZE> mp;
inline ll BSGS(ll a,ll b,ll mod){//a^x === b (MOD mod)
	mp.Clear();
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
	return -2;
}
ll T,p,a,b,x,t;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>p>>a>>b>>x>>t;
		if(x == t){
			cout<<1<<endl;
			continue;
		}
		if(a == 0){
			if(b == t){
				cout<<2<<endl;
			}else{
				cout<<-1<<endl;
			}
			continue;
		}
		if(a == 1){
			ll newt = t - x;
			Execute(newt,p);
			if(b == 0){
				cout<<-1<<endl;
				continue;
			}
			const ll ans = ((newt * KSM(b,p-2,p)) % p) + 1;
			cout<<ans<<endl;
			continue;
		}
		const ll OBJ = Div(t - Div(b,1-a,p),x + Div(b,a-1,p),p);
		const ll ans = BSGS(a,OBJ,p) + 1;
		cout<<ans<<endl; 
	}
	return 0;
}
