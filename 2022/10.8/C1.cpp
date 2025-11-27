#include<bits/stdc++.h>
using namespace std;
int t,n,c,a[200006];
long long ans;
int main(){
	scanf("%d",&t);
	while(t--){
		ans = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
		}
		int tail = 1;
		for(int i = 1;i <= n;i++){
			tail = max(tail,i);
			while(a[tail+1] >= tail+1-i+1 && tail+1 <= n)tail++;
			ans += (tail-i+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
