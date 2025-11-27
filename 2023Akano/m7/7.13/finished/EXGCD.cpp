#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll t,a,b,c;
ll Exgcd(ll a,ll b,ll& x,ll& y){
	if(b == 0){
		x = 1,y = 0;
		return a;
	}
	ll ret = Exgcd(b,a % b,x,y);
	ll nowx2 = x;
	x = y;//x1 = y2
	y = nowx2 - (a/b) * y;//y1 = x2 - (a/b)y2
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("EXGCD.in","r",stdin);
	freopen("EXGCD.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		ll x = 0,y = 0;
		ll abgcd = Exgcd(a,b,x,y);
		if(c % abgcd != 0){
			cout<<-1<<endl;
			continue;
		}
		x *= (c / abgcd),y *= (c / abgcd);
		a /= abgcd,b /= abgcd;
		if(x <= 0){
			const ll delta_x = ll(ceil(double(1ll-x) / b)) * b;
			const ll delta_y = delta_x / b * a;
			x += delta_x,y -= delta_y;
			const ll MIN_X = x,MAX_Y = y;
			const ll d2_y = ll(floor(double(y-1ll) / a)) * a;
			const ll d2_x = d2_y / a * b;
			x += d2_x,y -= d2_y;
			if(x <= 0 || MAX_Y <= 0){
				cout<<MIN_X<<" "<<y<<" "<<endl;
			}else{
				cout<<((x-MIN_X)/b)+1<<" "<<MIN_X<<" "<<y<<" "<<x<<" "<<MAX_Y<<endl;
			}
		}else{
			const ll delta_x = ll(floor(double(x-1ll) / b)) * b;
			const ll delta_y = delta_x / b * a;
			x -= delta_x,y += delta_y;
			const ll MIN_X = x;
			const ll MAX_Y = y;
			const ll d2_y = ll(floor(double(y-1ll) / a)) * a;
			const ll d2_x = d2_y / a * b;
			x += d2_x,y -= d2_y;
			if(x <= 0 || MAX_Y <= 0){
				cout<<MIN_X<<" "<<y<<" "<<endl;
			}else{
				cout<<((x-MIN_X)/b)+1<<" "<<MIN_X<<" "<<y<<" "<<x<<" "<<MAX_Y<<endl;
			}
		}
		
	}
	return 0;
}
