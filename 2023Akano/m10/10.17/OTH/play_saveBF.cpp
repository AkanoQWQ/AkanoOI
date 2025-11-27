//#include<bits/stdc++.h>
//#define Akano 1
//#define pure__Elysia 0
//#define loves ^
//using namespace std;
//using ll = long long;
//using pii = pair<int,int>;
//const int MAXN = 1e5 + 1018 + 1108;
//const int MOD = 1e9 + 7;
//int n,q,a[MAXN];
//ll delta[MAXN],now[MAXN];
//set<pii> save;
//inline void Prepare(){
//	ll last = 0;
//	for(int i = 0;i*i <= 1e9 + 3e4;i++){
//		int l = i*i,r = (i+1) * (i+1) - 1;
//		last += 1ll * (r - l + 1) * i;
//		last %= MOD;
//		save.insert(make_pair(r,last));
//	}
//	return ;
//}
//inline ll GetG(int x){
//	auto last = --save.upper_bound(make_pair(x,MOD+1));
//	ll ret = last->second;
//	int nowval = sqrt(last->first+1);
//	ret += 1ll * nowval * (x - last->first);
//	return ret % MOD;
//}
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
////	freopen("play/play0.in","r",stdin);
//	cin>>n>>q;
//	Prepare();
//	for(int i = 1;i <= n;i++){
//		cin>>a[i];
//		delta[i] = sqrt(a[i]);
//		now[i] = GetG(a[i]);
//	}
//	while(q--){
//		int opt,l,r;
//		cin>>opt>>l>>r;
//		if(opt == 1){
//			for(int i = l;i <= r;i++){
//				a[i]++;
//				int sqt = sqrt(a[i]);
//				if(sqt * sqt == a[i]){
//					delta[i]++;
//				}
//				now[i] += delta[i];
//			}
//		}else if(opt == 2){
//			ll ans = 0;
//			for(int i = l;i <= r;i++){
//				ans += now[i];
//				ans %= MOD;
//			}
//			cout<<ans<<endl;
//		}
//	}
//	return not(Akano loves pure__Elysia);
//}
