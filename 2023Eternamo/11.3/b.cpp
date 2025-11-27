#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2006 + 1018 + 1108;
int t,n,a[MAXN];
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i <= 2*n;i++){
			cin>>a[i];
		}
		sort(a+1,a+2*n+1);
		cout<<a[n]-a[1]+a[2*n]-a[n+1]<<endl;
		for(int i = 1;i <= n;i++){
			cout<<a[i]<<" "<<a[n+i]<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}
