#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
Rander rd;
const int MAXH = 1e9,n = 3e5,MAXLR = 3e5;
inline void Make(){
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rd(MAXH/2,MAXH)<<" ";
	}
	cout<<endl;
	mt19937_64 rng(GetTime());
	const ll mx = 1ll * n * (n+1) / 2;
	ll l = ((rng() % mx) + 1);
	ll r = ((rng() % mx) + 1);
	if(l > r)swap(l,r);
	r = min(r,l + MAXLR);
	cout<<l<<" "<<r<<endl;
	return ;
}
int h[n+2];
inline void Solve(){
	return ;
	int nn,l,r;
	cin>>nn;
	for(int i = 1;i <= nn;i++){
		cin>>h[i];
	}
	cin>>l>>r;
	vector<ll> vec;
	for(int i = 1;i <= nn;i++){
		int mn = h[i];
		for(int j = i;j <= nn;j++){
			mn = min(mn,h[j]);
			vec.push_back(1ll * mn * (j-i+1));
		}
	}
	sort(vec.begin(),vec.end());
	for(int i = l;i <= r;i++){
		cout<<vec[i-1]<<" ";
	}
	cout<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("rectangle",1,10,Make,Solve);
	return not(Akano loves pure__Elysia);
}
