#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
ll n,a[MAXN],sum;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){//a_0 = 0 a_n+1 = 0
		cin>>a[i];
		sum += abs(a[i] - a[i-1]);
	}
	sum += abs(0 - a[n]);
	for(int i = 1;i <= n;i++){
		cout<<sum-abs(a[i] - a[i-1])-abs(a[i] - a[i+1])+abs(a[i+1]-a[i-1])<<endl;
	}
	return 0;
}

