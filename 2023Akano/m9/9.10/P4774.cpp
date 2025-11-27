#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
struct Dragon{
	int health,power,reward;
}d[MAXN];
multiset<ll,greater<ll> > sword;//降序 
ll t,n,m,damage[MAXN];
ll ll_EXGCD(ll a,ll b,ll& x,ll& y){
	if(b == 0){
		x = 1,y = 0;
		return a;
	}
	ll gcd = ll_EXGCD(b,a % b,x,y);
	ll oldX = x;
	x = y;
	y = oldX - (a / b) * y;
	return gcd;
}
ostream& operator<<(ostream& os,__int128 integer){
	stack<char,vector<char> > stk;
	if(integer < 0){
		putchar('-');
		integer = -integer;
	}
	if(integer == 0)stk.push('0');
	while(integer){
		stk.push((integer % 10) + '0');
		integer /= 10;
	}
	while(!stk.empty()){
		putchar(stk.top());
		stk.pop();
	}
	return os;
}
template<typename T> 
class EXCRT{
	private:
		T ans1,mod1;
	public:
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
		//x*mod1 + a1 = y*mod2 + a2
		//a2 - a1 = x*mod1 - y*mod2
		inline bool Insert(T ans2,T mod2){
			T x,y;
			if(ans2 < ans1){
				swap(ans1,ans2),swap(mod1,mod2);
			}
			T gcd = EXGCD(mod1,mod2,x,y);
			if((ans2 - ans1) % gcd != 0){
				cerr<<"ins fail in "<<mod1<<endl;
				return false;
			}
			T delta = (ans2 - ans1) / gcd;
			x *= delta,y *= delta;
//			cerr<<x*mod1+ans1<<" === "<<y*mod2+ans2<<" mod "<<(mod1 / gcd * mod2)<<endl;
			ans1 += x * mod1;
			if(ans1 < 0)cerr<<"ERROR ans1 < 0"<<endl;
			mod1 = mod1 / gcd * mod2;
			ans1 = ((ans1 % mod1) + mod1) % mod1;
			return true; 
		}
		inline T GetAns(){
			return ans1;
		}
		inline T GetMod(){
			return mod1;
		}
		inline void Clear(){
			ans1 = 0,mod1 = 1;
			return ;
		}
		EXCRT(){Clear();}
};
EXCRT<__int128> excrt;
inline ll Solve(){
	sword.clear();
	excrt.Clear();
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>d[i].health;
	}
	for(int i = 1;i <= n;i++){
		cin>>d[i].power;
	}
	for(int i = 1;i <= n;i++){
		cin>>d[i].reward;
	}
	for(int i = 1;i <= m;i++){
		int c;
		cin>>c;
		sword.insert(c);
	}
	bool suc = true;
	for(int i = 1;i <= n;i++){
		auto it = sword.lower_bound(d[i].health);
		if(it == sword.end())it--;//选择最小的
		damage[i] = *it;
		sword.erase(it); 
		ll divv = Div(d[i].health,damage[i],d[i].power);
		if(divv == -10181108){
//			cerr<<d[i].health<<" / "<<damage[i]<<" in "<<d[i].power<<" fail"<<endl;
			suc = false;
			break;
		}
		suc &= excrt.Insert(divv,d[i].power);
		if(suc == false)return -1;
		sword.insert(d[i].reward);
	}
	if(suc == false)return -1;
//	cerr<<"getans "<<excrt.GetAns()<<endl;
	cerr<<ll(excrt.GetAns())<<" % "<<ll(excrt.GetMod())<<endl;
	return excrt.GetAns();
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("dragon/dragon2.in","r",stdin);
	cin>>t;
	while(t--){
		cout<<Solve()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
/*
x * ATK = h + y * p   h-health,p-power
x * atk_i === h_i   (mod p_i)

x1 * atk1 + y1 * p1 - h1 = x2 * atk2 + y2 * p2 - h2
h2 - h1 = 
*/
