#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1018; 
long long n,a[MAXN],ans;
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 2;i <= n;i++){
		ans += abs(a[i] - a[i-1]);
	}
	cout<<ans<<endl;
	return 0;
}
