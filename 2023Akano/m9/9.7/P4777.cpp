#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
template<typename T>//装载类型,整数类型 
class ExCRT{
	private:
		T ans1,mod1;
		inline T GCD(T a,T b){
			if(b == 0)return a;
			return GCD(b,a % b);
		}
		inline T LCM(T a,T b){
			return a / GCD(a,b) * b;
		}
		inline T ExGCD(T a,T b,T& x,T& y){
			if(b == 0){
				x = 1,y = 0;
				return a;
			}
			T gcd = ExGCD(b,a % b,x,y);
			T oldX = x;
			x = y;
			y = oldX - (a/b) * y;
			return gcd;
		} 
		inline bool Calc(T a,T b,T ans,T& x,T& y){//ax + by = ans
			T gcd = ExGCD(a,b,x,y);
			if(ans % gcd != 0)return false;
			T delta = ans / gcd;
			x *= delta,y *= delta;
			return true;
		}
	public:
		inline bool Insert(T ans2,T mod2){
			T p,q;
			if(ans2 < ans1){
				swap(ans1,ans2),swap(mod1,mod2);
			}
			bool suc = Calc(mod1,mod2,ans2 - ans1,p,q);
			if(suc == false)return false;
			ans1 = ans1 + mod1 * p;
			mod1 = LCM(mod1,mod2);
			ans1 = ((ans1 % mod1) + mod1) % mod1;
			return true;
		}
		inline T GetAns(){
			return ans1;
		}
		ExCRT(){
			ans1 = 0,mod1 = 1;
			return ;
		}
};
ExCRT<__int128> excrt;
ll n,a,mod;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>mod>>a;
		bool suc = excrt.Insert(a,mod);
		if(!suc){
			cout<<"No solution!"<<endl;
			return not(Akano loves pure__Elysia); 
		}
	}
	cout<<ll(excrt.GetAns())<<endl;
	return not(Akano loves pure__Elysia);
}
