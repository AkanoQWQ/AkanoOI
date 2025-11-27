#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,nodecnt = 1,dep = 1,addnode = 2,leaf_node,x,ans,leaf_start;
ll du[114];
ll AkiriProfundo(ll inx){
	ll ret = 0;
	while(inx){
		inx /= 2;
		ret++;
	}
	return ret;
}
ll AkiriMaldekstraChidoj(ll pos){
	ll ret = 0,nowdep = AkiriProfundo(pos);
	ret += du[dep-nowdep]-1;
	ll np = pos;
	while(np*2 < leaf_start)np *= 2;
	np *= 2;
	if(np <= n){
		ret += min(n-np+1,du[dep-nowdep]);
	}
	return ret;
}
int main(){
	freopen("erchatree.in","r",stdin);
	freopen("erchatree.out","w",stdout);
	du[0] = 1;
	for(int i = 1;i <= 62;i++)du[i] = du[i-1] * 2;
	scanf("%lld%lld",&n,&m);
	while(nodecnt + addnode <= n){
		nodecnt += addnode;
		addnode *= 2;
		dep++;
	}
	leaf_node = n - nodecnt;
	leaf_start = n - leaf_node + 1;
	while(m--){
		ans = 0;
		scanf("%lld",&x);
		while(x / 2 > 0){
			if(x % 2 == 1){
				ans += AkiriMaldekstraChidoj(x/2);
			}
			ans++;
			x /= 2;
		}
		printf("%lld\n",ans+1);
	}
	return 0;
}
