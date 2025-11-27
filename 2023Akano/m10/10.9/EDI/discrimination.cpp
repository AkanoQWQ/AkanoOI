#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using Bigint = __int128;
using ll = long long;
ostream& operator<<(ostream& os,Bigint bi){
	string str;
	while(bi){
		str += '0' + (bi % 10);
		bi /= 10;
	}
	reverse(str.begin(),str.end());
	os<<str;
	return os;
}
istream& operator>>(istream& is,Bigint& bi){
	ll cache;
	is>>cache;
	bi = cache;
	return is;
}
const int MAXD = 1e7 + 1018 + 1108;
const ll lim = 1e13 + 1018 + 1108;
inline ll Near(ll x,ll y){
	ll bs = x / y;
	if(bs * y < x)bs++;
	return bs*y;
}
ll lpos[MAXD],rpos[MAXD],nowlen = 1,nowl = 1;
ll t,n,m,R;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("discrimination.in","r",stdin);
	freopen("discrimination.out","w",stdout);
	for(ll i = 1;nowl <= lim;i++){
		lpos[i] = nowl,rpos[i] = nowl + nowlen - 1;
		if((i & 1ll) == 0)rpos[i]++,nowlen++;
		nowl = rpos[i] + 1;
	}
	cin>>t;
	while(t--){
		cin>>n>>m>>R;
		Bigint ans = 0;
		for(ll i = 1;lpos[i] <= n;i++){
			const ll l = lpos[i],r = min(n,rpos[i]);
			ll realL = Near(l,m) + R;
			while(realL - m >= l)realL -= m;
			ll appear = ((r - realL + 1 - 1) / m) + 1;
			if(realL > r)appear = 0;
			ans = max(ans,ans + appear * i);
		}
		cout<<ans<<endl;
	}
	return not(Akano loves pure__Elysia);
}
