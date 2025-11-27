#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
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
const int SIZE = 1e6;
inline ll KSM(ll a,ll b,ll mod){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1; 
	}
	return ret;
}
int t,type;
ll a,b,c;
namespace Subtask1{
	inline void Solve(){
		while(t--){
			cin>>a>>b>>c;
			cout<<KSM(a,b,c)<<endl;
		}
		return ;
	}
}
namespace Subtask2{
	ll ExGCD(ll a,ll b,ll& x,ll& y){
		if(b == 0){
			x = 1,y = 0;
			return a;
		}
		ll gcd = ExGCD(b,a % b,x,y);
		ll oldX = x;
		x = y;
		y = oldX - (a/b) * y;
		return gcd;
	}
	inline ll Calc(ll a,ll b,ll mod){
		ll x,y;
		ll gcd = ExGCD(a,mod,x,y);
		if(b % gcd != 0)return -1;
		x *= (b / gcd),y *= (b / gcd);
		ll delta = ceil(double(1 - x) / double(mod));
		return (x + delta * mod) % mod;
	}
	inline void Solve(){
		while(t--){
			cin>>a>>b>>c;
			ll res = Calc(a,b,c);
			if(res == -1){
				cout<<"Orz, I cannot find x!"<<endl;
			}else{
				cout<<res<<endl;
			}
		}
		return ;
	}
}
namespace Subtask3{
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
		return -1;
	}
	inline void Solve(){
		while(t--){
			cin>>a>>b>>c;
			a %= c,b %= c;
			if(a == 0){
				if(b == 0){//.......
					cout<<1<<endl;
					continue;
				}
				cout<<"Orz, I cannot find x!"<<endl;
				continue;
			}
			ll res = BSGS(a,b,c);
			if(res == -1){
				cout<<"Orz, I cannot find x!"<<endl;
			}else{
				cout<<res<<endl;
			}
		}
		return ;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t>>type;
	if(type == 1){
		Subtask1::Solve();
	}else if(type == 2){
		Subtask2::Solve();
	}else if(type == 3){
		Subtask3::Solve();
	}
	return not(Akano loves pure__Elysia);
}
