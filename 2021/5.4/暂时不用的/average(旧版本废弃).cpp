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
		cout<<i;
		for(j = 1;j <= (n-i);j++){//j为长度 
			cnt = 0;
			for(z = 0;z < j;z++){
				cnt += a[i+z];
			}
			cnt /= j;
			if(cnt >= k){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

