#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2006 + 1018 + 1108;//Ã»ÓÐ·¶Î§°¡ 
ll n,a[MAXN],mod[MAXN];
template<typename T>
class ExCRT{
	private:
		T ans1,mod1;
		T EXGCD(T a,T b,T& x,T& y){
			if(b == 0){
				x = 1,y = 0;
				return a;
			}
			T gcd = EXGCD(b,a % b,x,y);
			T oldX = x;
			x = y;
			y = oldX - (a / b) * y;
			return gcd;
		}
	public:
		inline void Clear(){
			ans1 = 0,mod1 = 1;
			return ;
		}
		inline bool Insert(T ans2,T mod2){
			if(ans2 < ans1){
				swap(ans1,ans2),swap(mod1,mod2);
			}
			T x,y;
			T gcd = EXGCD(mod1,mod2,x,y);
			if((ans2 - ans1) % gcd != 0)return false;
			T delta = (ans2 - ans1) / gcd;
			x *= delta,y *= delta;
			ans1 += mod1 * x;
			mod1 = mod1 / gcd * mod2;
			ans1 = ((ans1 % mod1) + mod1) % mod1;
			return true;
		}
		inline T GetAns(){
			return ans1;
		}
		ExCRT(){Clear();}
};
ExCRT<__int128> excrt;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>n){
		bool fail = false;
		for(int i = 1;i <= n;i++){
			cin>>mod[i]>>a[i];
		}
		excrt.Clear();
		for(int i = 1;i <= n;i++){
			bool res = excrt.Insert(a[i],mod[i]);
			if(res == false){
				fail = true;
				break;
			}
		}
		if(fail){
			cout<<-1<<endl;
		}else{
			cout<<ll(excrt.GetAns())<<endl; 
		}
	}
	return not(Akano loves pure__Elysia);
}
