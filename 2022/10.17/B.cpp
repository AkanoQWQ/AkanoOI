#include<bits/stdc++.h>
using namespace std;
int t;
struct gs{
	int a,b;
}g[200006];
bool cmp(gs a,gs b){
	return a.b < b.b;
}
int main(){
	cin>>t;
	while(t--){
		int n,maxv = 0;
		cin>>n;
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			cin>>g[i].a;
			ans += g[i].a;
		}
		for(int i = 1;i <= n;i++){
			cin>>g[i].b;
			ans += g[i].b;
			maxv = max(maxv,g[i].b);
		}
		ans -= maxv;
		cout<<ans<<endl;
	}
	return 0;
}
