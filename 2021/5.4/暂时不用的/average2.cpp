#include<bits/stdc++.h>
using namespace std;
long long n,k,i,j,z,a[200006],cnt,ans,bj;
int main(){
	freopen("average.in","r",stdin);
	//freopen("average.out","w",stdout);
	cin>>n>>k;
	for(i = 0;i < n;i++){
		cin>>a[i];
	}
	for(i = 0;i < n;i++){//i为L 
		for(j = 1;j <= (n-i);j++){//j为长度
			if(bj == 1&&a[i+j] > k){
				ans++;
				bj = 0;
				continue;
			}
			bj = 0;
			cnt = 0;
			for(z = 0;z < j;z++){
				cnt += a[i+z];
			}
			cnt /= j;
			if(cnt >= k){
				ans++;
				bj = 1;
			}
		}
	}
	cout<<ans;
	return 0;
}

