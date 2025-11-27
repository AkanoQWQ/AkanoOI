#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,nodecnt = 1,dep = 1,addnode = 2,leaf_node,x,ans,leaf_start;
ll du[114];
bool dekstra;
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
inline ll read(){
	ll ret = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return ret * f;
}
void write(ll inx){
	if(inx < 0){
		inx = -inx;
		putchar('-');
	}
	if(inx > 9){
		write(inx / 10);
	}
	putchar((inx%10) + '0');
}
int main(){
	freopen("erchatree.in","r",stdin);
	freopen("erchatree2.out","w",stdout);
	du[0] = 1;
	for(int i = 1;i <= 62;i++)du[i] = du[i-1] * 2;
	n = read(),m = read();
	while(nodecnt + addnode <= n){
		nodecnt += addnode;
		addnode *= 2;
		dep++;
	}
	leaf_node = n - nodecnt;
	leaf_start = n - leaf_node + 1;
	while(m--){
		dekstra = false;
		ans = 0;
		x = read();
		while(x / 2 > 0){
			if(x % 2 == 1){
				dekstra = true;
				ans += AkiriMaldekstraChidoj(x/2);
			}
			ans++;
			x /= 2;
		}
		write(ans+1),putchar('\n');
	}
	return 0;
}
