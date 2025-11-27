#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 3e5 + 1018 + 1108;
const int MAXK = 1e6 + 1018 + 1108;
ll n,k,arr[MAXN],ans;
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
	return ((x % k) + k) % k;
} 
void Solve(int l,int r){
	if(l == r)return ;
	const int mid = (l + r) >> 1;
	Solve(l,mid),Solve(mid+1,r);
	ll sum = 0,tail = mid,mx = 0,tot = 0;
	vis.Clear();
	for(int i = mid;i >= l;i--){
		mx = max(mx,arr[i]);
		tot += arr[i];
		while(tail+1 <= r && arr[tail+1] <= mx){
			tail++;
			sum += arr[tail];
			vis[Mod(sum)]++;
		}
		ans += vis[Mod(- tot + mx)];
	}
	sum = 0,tail = mid+1,mx = 0,tot = 0;
	vis.Clear();
	for(int i = mid+1;i <= r;i++){
		mx = max(mx,arr[i]);
		tot += arr[i];
		while(tail-1 >= l && arr[tail-1] < mx){
			tail--;
			sum += arr[tail];
			vis[Mod(sum)]++;
		}
		ans += vis[Mod(- tot + mx)];
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	Solve(1,n);
	cout<<ans;
	return not(Akano loves pure__Elysia);
}
