#include<bits/stdc++.h>
using namespace std;
int n,k,l,r,i,j;
long long f[200006],s[200006];
struct node{
	int l,r;
}a[15];
const long long MOD = 998244353;
long long ze = 0;
int main(){
	//freopen("move.in","r",stdin);
	//freopen("move.out","w",stdout);
	cin>>n>>k;
	for(i = 0;i < k;i++){
		cin>>a[i].l>>a[i].r;
	}
	f[1] = 1;
	s[1] = 1;
	for(i = 2;i <= n;i++){
		for(j = 1;j <= k;j++){
			f[i] = (f[i] + max(i - a[j].l,0) - max(i - a[j].r,0) + MOD) % MOD;
			s[i] = (s[i-1] + f[i]) % MOD;
		}
	}
	cout<<s[n];
	return 0;
}

