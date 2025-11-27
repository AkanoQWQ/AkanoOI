#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 4; 
int pre[MAXN],lst[MAXN],a[MAXN],n,ans,cnt = 0;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		ans += a[i];
		pre[i] = pre[i-1] + a[i];
	}
	for(int i = n;i >= 1;i--){
		lst[i] = lst[i+1] + a[i];
	}
	for(int l = 0;l <= n;l++){
		for(int r = l+1;r <= n+1;r++){
			cnt = max(cnt,-pre[l]-lst[r]);
		}
	}
	cout<<cnt+ans;
	return 0;
}
