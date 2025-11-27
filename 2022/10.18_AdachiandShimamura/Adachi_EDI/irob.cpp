#include<bits/stdc++.h>
using namespace std;
int n,a[2006],s[2006],ans;
int main(){
	freopen("irob.in","r",stdin);
	freopen("irob.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		a[i]--;
		s[i] = s[i-1] + a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if((j - i + 1) % 2 == 1){
				ans++;
				continue;
			}
			if((s[j] - s[i-1]) != ((j - i + 1)/2)){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
