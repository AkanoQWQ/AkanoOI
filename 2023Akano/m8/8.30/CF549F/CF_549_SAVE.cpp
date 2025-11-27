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
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("CF549F.in","r",stdin);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	for(int i = 1;i <= n;i++){//向左边推取等,向右边推不取等 
		vis.Clear();
		int tail = i;
		ll sum = 0;
		while(tail-1 >= 1 && arr[tail-1] <= arr[i]){
			tail--;
			sum = (sum + arr[tail]) % k;
			vis[sum]++;
		}
		tail = i,sum = 0;
		ans += vis[0];
		vis[0]++;//TOT ADD
		while(tail+1 <= n && arr[tail+1] < arr[i]){
			tail++;
			sum = (sum + arr[tail]) % k;
			ans += vis[(k-sum) % k];
//			cerr<<"try "<<(k-sum) % k<<" in "<<tail<<" which "<<vis[(k-sum) % k]<<endl;
		}
	}
	cout<<ans;
	return not(Akano loves pure__Elysia);
}

