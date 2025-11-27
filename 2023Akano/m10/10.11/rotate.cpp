#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int MAXN = 5e5 + 1018 + 1108;
int n,arr[MAXN];
pii start[MAXN],final[MAXN];
class piiHash{
public:
	using ull = unsigned long long;
	ull operator()(pii _pii)const {
		return (ull(_pii.first) << 32) + _pii.second;
	}
};
unordered_map<pii,int,piiHash> idxs;
bool OK = true;
class BIT{
private:
	int val[MAXN];
	inline int Lowbit(int x){
		return x & (-x);
	}
public:
	inline void Change(int pos,int x){
		while(pos <= n){
			val[pos] += x;
			pos += Lowbit(pos);
		}
		return ;
	}
	inline int Query(int pos){
		int ret = 0;
		while(pos){
			ret += val[pos];
			pos -= Lowbit(pos);
		}
		return ret;
	}
}tr;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>start[i].first;
	for(int i = 1;i <= n;i++)cin>>start[i].second;
	for(int i = 1;i <= n;i++)cin>>final[i].first;
	for(int i = 1;i <= n;i++)cin>>final[i].second;
	for(int i = 1;i <= n;i++)idxs[start[i]] = i;
	for(int i = 1;i <= n;i++){
		pii invFinal = final[i];
		swap(invFinal.first,invFinal.second);
		if(idxs.find(final[i]) != idxs.end()){
			const int idx = idxs[final[i]];
			if(abs(idx - i) % 2 == 0){
				arr[idx] = i;
			}else{
				OK = false;
			}
		}else if(idxs.find(invFinal) != idxs.end()){
			const int idx = idxs[invFinal];
			if(abs(idx - i) % 2 == 1){
				arr[idx] = i;
			}else{
				OK = false;
			}
		}else{
			OK = false;
		}
	}
	if(OK == false){
		cout<<-1<<endl;
	}else{
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			ans += i - 1 - tr.Query(arr[i]);
			tr.Change(arr[i],1);
		}
		cout<<ans<<endl;
	}
	return not(Akano loves pure__Elysia);
}
