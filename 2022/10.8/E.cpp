#include<bits/stdc++.h>
using namespace std;
long long t,n,q,a[200006],b[200006],c,k,d[200006];
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&q);
		memset(b,0,sizeof(b));
		for(int i = 1;i <= n;i++){
			scanf("%lld",&c);
			b[i] = b[i-1] + c;
			d[i] = max(c,d[i-1]);
		}
		while(q--){
			scanf("%lld",&k);
			long long ans = 0;
			long long l = 1,r = n+1;
			while(l < r){
				long long mid = (l+r) >> 1;
				if(k < d[mid]){
					r = mid;
				}else{
					l = mid+1;
					ans = max(ans,b[mid]);
				}
			}
			printf("%lld ",ans);
		}
		putchar('\n');
	}
	return 0;
}
