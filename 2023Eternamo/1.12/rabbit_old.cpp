#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 100006;
ll n,m,k,a[MAXN];
double pos[MAXN];
int main(){
//	freopen("rabbit.in","r",stdin);
//	freopen("rabbit_old.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lf",&pos[i]);
	}
	scanf("%lld%lld",&m,&k);
	for(int i = 1;i <= m;i++){
		scanf("%lld",&a[i]);
	}
	while(k--){
		for(int i = 1;i <= m;i++){
			pos[a[i]] = pos[a[i]-1] + pos[a[i]+1] - pos[a[i]];
		}
//		printf("\n !!! %.1lf !!! \n",pos[2]);
	}
	for(int i = 1;i <= n;i++){
		printf("%.1lf\n",pos[i]);
	}
	return 0;
}
//pos[a[i]] = 0.5 * (2 * pos[a[i]-1] - pos[a[i]]) + 0.5*(2 * pos[a[i]+1] - pos[a[i]]);

