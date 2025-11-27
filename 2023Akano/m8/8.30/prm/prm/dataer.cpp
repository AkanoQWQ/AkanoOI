#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
Rander rd;
const int MAXVAL = 1e6;
const int MIN_ANS = 10;
inline int Cnt(ll a,ll b,ll mod,ll up){
	ll ret = 0,res = 1;
	for(int i = 0;i <= up;i++){
		if(res == b){
			ret++;
		}
		res = (res * a) % mod;
	}
	return ret;
}
inline void Make(){
	ll b = 2,n = 2,p = 2,up = 2,ans = 0;
	while(__gcd(b,p) != 1 || ans <= MIN_ANS){
		b = rd(1,MAXVAL),n = rd(1,MAXVAL),p = rd(2,MAXVAL),up = 2 * p + rd(-p,p);
		ans = Cnt(b,n,p,up);
	}
	cout<<b<<" "<<n<<" "<<p<<" "<<up<<endl;
	return ;
}
inline void BF(){
	ll a,b,mod,up;
	cin>>a>>b>>mod>>up;
	ll ret = 1;
	for(int i = 0;i <= up;i++){
		if(ret == b){
			cout<<i<<endl;
		}
		ret = (ret * a) % mod;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("prm",1,10,Make,BF);
	return not(Akano loves pure__Elysia);
}

