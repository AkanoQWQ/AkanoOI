#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
priority_queue<ll,vector<ll>,greater<ll> > q;
ll n,c,ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>c;
		q.push(c);
	}
	while(q.size() >= 2){
		const ll u1 = q.top();
		q.pop();
		const ll u2 = q.top();
		q.pop();
		ans += u1 + u2;
		q.push(u1+u2);
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
