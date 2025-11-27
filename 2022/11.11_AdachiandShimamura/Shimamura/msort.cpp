#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
long long ans;
int n,a[MAXN],b[MAXN];
void msort(int l,int r){
	if(l == r)return ;
	const int mid = (l + r) >> 1;
	msort(l,mid);
	msort(mid+1,r);
	int i = l;
	int j = mid + 1;
	int t = l;
	while(i <= mid && j <= r){
		if(a[i] > a[j]){
			ans += mid - i + 1;
			b[t++] = a[j];
			++j;
		}else{
			b[t++] = a[i];
			++i;
		}
	}
	while(i <= mid){
		b[t++] = a[i];
		++i;
	}
	while(j <= r){
		b[t++] = a[j];
		++j;
	}
	for(int i = l;i <= r;i++){
		a[i] = b[i];
	}
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	msort(1,n);
	printf("%lld",ans);
	return 0;
}
