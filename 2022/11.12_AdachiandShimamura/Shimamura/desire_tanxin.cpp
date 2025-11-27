#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXP = 2006110;
const int MAXN = 2006;
int leaf = 1;
int n,a[MAXN];
int q[MAXP][2],tail;
ll solve1(){
	ll ret = 0;
	q[1][0] = a[1],q[1][1] = 0;
	tail = 1;
	for(int i = 2;i <= n;i++){
		int mincost = 0x7fffffff;
		int pos = -1;
		for(int j = 1;j <= tail;j++){
			const int nowv = q[j][0];
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
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp2);
	printf("%lld",solve1());
	return 0;
}
