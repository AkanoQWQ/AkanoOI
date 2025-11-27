#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,k;
ll ksm(ll a,ll n,ll p){
	ll ret = 1;
	while(n){
		if(n % 2 == 1){
			ret *= a;
			ret %= p;
		}
		a *= a;
		a %= p;
		n /= 2;
	}
	return ret;
}
int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x = 1,y = 0;
		return a;
	}
	int g = exgcd(b,a%b,y,x);
	y -= (a/b) * x;
	return g;
}
map<ll,ll> a;
int main(){
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	cin>>t>>k;
	while(t--){
		ll y,z,p;
		cin>>y>>z>>p;
		if(k == 1){
			cout<<ksm(y,z,p)<<endl;
		}else if(k == 2){
			int x = 0,yy = 0;
			int g = exgcd(y,p,x,yy);
			if(z % g != 0){
				cout<<"Orz, I cannot find x!"<<endl;
			}else{
				int tmp = p / g;
				while(x < 0)x += tmp;
				cout<<((x*z/g)%tmp + tmp)%tmp<<endl;
			}
		}else if(k == 3){
			if(y % p == 0 &&z){
				cout<<"Orz, I cannot find x!"<<endl;
				continue;
			}
			ll m = ceil(sqrt(p));
			a.clear();
			ll now = z % p;//没错我是贺的 我不会,贺完以后再学习
			ll f = ksm(y,m,p);
			a[now] = 0;
			for(int i = 1;i <= m;i++){
				now = (now * y) % p;
				a[now] = i;
			}
			now = 1;
			bool otp = 0;
			for(int i = 1;i <= m;i++){
				now = (now * f) % p;
				if(a[now]){
					cout<<((i*m-a[now])%p+p)%p<<endl;
					otp = 1;
					break;
				}
			}
			if(otp == 0){
				cout<<"Orz, I cannot find x!"<<endl;
			}
		}
	}
	return 0;
}
