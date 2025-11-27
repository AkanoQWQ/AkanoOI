#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 100006;
int n,d[MAXN],mind = 0x7fffffff;
ll ans;
int main(){
	freopen("auti.in","r",stdin);
	freopen("auti.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&d[i]);
		mind = min(mind,d[i]);
	}
	for(int i = 1;i <= n;i++){
		ans += (d[i] + mind);
	}
	ans -= 2 * mind;
	printf("%lld",ans);
	return 0;
}
