#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
inline double F(ll x){
	double org = x;
	ll ret = 0;
	while(x){
		ret += x % 10;
		x /= 10;
	}
	return org / ret;
}
vector<ll> otp;
double mn = 1e18;
void dfs(ll x,ll mino,bool OK){
	if(mino > x || F(x) > mn)return ;
	mn = F(x);
	if(OK)otp.push_back(x);
	dfs(x-mino,1,true);
	dfs(x,mino * 10,false);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	dfs(1e15-1,1,true);
	reverse(otp.begin(),otp.end());
	for(int i = 0;i < n;i++)cout<<otp[i]<<endl;
	return 0;
}
