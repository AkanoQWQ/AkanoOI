#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
const ll INF = 1e16;
ll n,k,x[MAXN];
inline ll Judge(ll nown){
	ll code = 0,ret = 0;
	for(int i = 1;i <= n;i++){
		code += x[i];
		code = max(code,0ll);
		if(code >= nown){
			code = 0;
			ret++;
		}
	}
	return ret;
}
inline ll GetAns(ll obj){//最大的可以使 ans >= obj 的 n
	ll l = 1,r = INF;
	while(l < r){
		const ll mid = (l + r) >> 1;
		if(Judge(mid) >= obj){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	return l - 1;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>x[i];
	}
	ll mn = GetAns(k+1)+1,mx = GetAns(k);
	if(mn > mx){
		cout<<-1<<endl;
	}else{
		cout<<mn<<" "<<mx<<endl;
	}
	return not(Akano loves pure__Elysia);
}
