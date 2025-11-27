#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
int n,arr[MAXN],f[MAXN];
class BIT{
	private:
		int val[MAXN*2];
		inline int Lowbit(int x){
			return x & (-x);
		}
	public:
		inline void Change(int pos,int x){
			pos += n + 2;
			while(pos <= 2*n+5){
				val[pos] += x;
				pos += Lowbit(pos);
			}
			return ;
		}
		inline int Query(int pos){
			pos += n + 2;
			int ret = 0;
			while(pos){
				ret += val[pos];
				pos -= Lowbit(pos);
			}
			return ret;
		}
		inline void Clear(){
			memset(val,0,sizeof(val));
			return ;
		}
}bit;
ll OBJ;
inline bool Judge(int x){
	ll ret = 0;
	bit.Clear();
	for(int i = 1;i <= n;i++){
		f[i] = f[i-1] + ((arr[i] >= x) ? 1 : -1);
		bit.Change(f[i-1],1);
		ret += bit.Query(f[i]); 
//		cerr<<i<<" get "<<bit.Query(f[i])<<" f "<<f[i]<<endl;
	}
	//ret有多少个子串的mid大于等于x 
//	cerr<<x<<" : "<<ret<<" compare "<<(OBJ+1)/2<<" in tot "<<OBJ<<endl;
	return (ret >= (OBJ+1)/2);
}
inline int Solve(){
	int l = 1,r = 1e9 + 1;
	while(l < r){
		const int mid = (l + r) >> 1;
		if(Judge(mid)){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	return l-1;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	OBJ = 1ll * (n) * (n+1) / 2;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	cout<<Solve()<<endl;
	return not(Akano loves pure__Elysia);
}
