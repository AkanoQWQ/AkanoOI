#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXP = 200611;
const int MAXN = 2006;
int dep[MAXP],leaf = 1;
int n,a[MAXN];
int t[MAXP],num[MAXP],leaf_num = 1;
int q[MAXP][2],tail;
ll sr(){
	t[1] = 0;
	leaf_num = 1;
	ll ret = 0;
	while(leaf_num < n){
		const int v = t[leaf_num];
		t[leaf_num++] = v + 1;
		t[leaf_num] = v + 2;
	}
	sort(t+1,t+n+1);
	for(int i = 1;i <= n;i++){
		ret += t[i] * a[i];
	}
	return ret;
}
ll sl(){
	t[1] = 0;
	leaf_num = 1;
	ll ret = 0;
	while(leaf_num < n){
		const int v = t[leaf_num];
		t[leaf_num++] = v + 2;
		t[leaf_num] = v + 1;
	}
	sort(t+1,t+n+1);
	for(int i = 1;i <= n;i++){
		ret += t[i] * a[i];
	}
	return ret;
}
ll solve1(){
	ll ret = 0;
	t[1] = 0;
	leaf_num = 0;
	q[1][0] = a[1],q[1][1] = 0;
	tail = 1;
	for(int i = 2;i <= n;i++){
		int mincost = 0x7fffffff;
		int pos = -1;
		for(int j = 1;j <= tail;j++){
			const int nowv = q[j][0];//addcost = nowv + dep*
			const int nowd = q[j][1];
			if(nowv == -1 || nowd == -1)continue;
			if(nowv + (nowd+2)*a[i] < mincost){
				mincost = nowv + (nowd+2)*a[i];
				pos = j;
			}
		}
		ret += mincost;
		q[++tail][0] = q[pos][0];
		q[tail][1] = q[pos][1] + 1;
		q[++tail][0] = a[i];
		q[tail][1] = q[pos][1] + 2;
		q[pos][0] = q[pos][1] = -1;
	}
	return ret;
}
int cmp2(int a,int b){
	return a > b;
}
int main(){
	//freopen("desire.in","r",stdin);
	//freopen("desire.out","w",stdout);
	srand(time(0));
	for(int tt = 1;tt <= 1000;tt++){
		n = 750;
		for(int i = 1;i <= n;i++){
			a[i] = (rand()*rand())%100000;
		}
		sort(a+1,a+n+1,cmp2);
		ll rans = sr();
		ll lans = sl();
		ll ans1 = solve1();
		printf("%lld %lld %lld",min(ans1,min(lans,rans)),lans,rans);
		if(lans < ans1 || rans < ans1){
			puts("NO");
			return 0;
		}
		if(lans < rans){
			puts("Left");
		}else{
			puts("Right");
		}
	}
	return 0;
}
