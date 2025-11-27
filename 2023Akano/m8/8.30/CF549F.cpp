#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 3e5 + 1018 + 1108;
const int MAXK = 1e6 + 1018 + 1108;
ll n,k,arr[MAXN],ans,shift;
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
};
ClearableArray<int,MAXK> vis;
inline ll Mod(ll x){
	x %= k;
	x = (x + k) % k;
	return x;
} 
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("CF549F/CF549F.in","r",stdin);
	cin>>n>>k;
	arr[0] = -1;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	for(int i = 1;i <= n;i++){
		ll sum = 0,cnt = 0;
		vis.clear();
		if(i - l[i] < r[i] - i){//
			
		}
	}
	cout<<ans;
	return not(Akano loves pure__Elysia);
}
