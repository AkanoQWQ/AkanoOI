#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MAXM = 1e5 + 1018 + 1108;
ll n,m,x,r;
pll seg[MAXM],now[MAXM];
inline bool Judge(ll d){
	for(int i = 1;i <= d;i++)now[i] = seg[i];
	sort(now+1,now+d+1);
	r = 0;
	ll cnt = 0;
	for(int i = 1;i <= d;i++){
		const ll left = now[i].first - r - 1;
		if(left > 0){
			if(x == 0)return false;
			const ll temp = (left - 1) / x + 1;
			cnt += temp;
			r = max(r,r + temp * x);
		}
		r = max(r,now[i].second);
	}
	const ll left = n - r;
	if(left > 0){
		if(x == 0)return false;
		cnt += (left - 1) / x + 1;
	}
	return (cnt <= d);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("liqi.in","r",stdin);
	freopen("liqi.out","w",stdout);
	cin>>n>>m>>x;
	for(int i = 1;i <= m;i++){
		cin>>seg[i].first>>seg[i].second;
	}			 
	ll l = 1,r = m+1;
	while(l < r){
		const ll mid = (l + r) >> 1;
		if(Judge(mid)){
			r = mid;
		}else{	 
			l = mid + 1;
		}
	}
	if(r == m+1){
		cout<<"Poor Douer!"<<endl;
	}else{
		cout<<r<<endl;
	}
	return 0;
}
//Point 5 poss
