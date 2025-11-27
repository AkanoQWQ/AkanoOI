#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXA = 1e5+6;
const int INF = 0x7fffffff;
const ll LINF = 1ll * INF / 4 * INF;
ll read(){
    ll x = 0,f = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
		if(c == '-')f = -1;
		c = getchar();
	}
    while(c >= '0' && c <= '9'){
    	x = x * 10 + c - '0';
		c = getchar();
	}
    return x*f;
}
ll n;
ll tong[MAXA];
queue<ll> q1,q2;
ll ans;
ll realtop(){
	ll m1 = LINF,m2 = LINF;
	if(!q1.empty()){
		m1 = q1.front();
	}
	if(!q2.empty()){
		m2 = q2.front();
	}
	if(m1 < m2){
		q1.pop();
		return m1;
	}else{
		q2.pop();
		return m2;
	}
}
int main(){
	n = read();
	while(n--){
		ll c = read();
		tong[c]++;
	}
	for(int i = 1;i < MAXA;i++){
		while(tong[i]--){
			q1.push(i);
		}
	}
	while(q1.size() + q2.size() >= 2){
		ll c1 = realtop();
		ll c2 = realtop();
		ans += c1 + c2;
		q2.push(c1+c2);
	}
	cout<<ans;
	return 0;
}
