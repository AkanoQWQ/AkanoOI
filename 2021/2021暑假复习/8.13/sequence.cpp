#include<bits/stdc++.h>
using namespace std;
long long a[102006],n,l,r,i,j,c,k;
double ans,dd1 = 1.00;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>l>>r;
	for(i = 1;i <= n;i++){
		cin>>c;
		a[i] = a[i-1] + c;
	}
	for(k = l;k <= r;k++){
		for(i = 1;i <= (n-k+1);i++){
			ans = max(ans,(double(a[i+k-1] - a[i-1])/double(k)));
		}
	}
	printf("%.4f",ans);
	return 0;
}

