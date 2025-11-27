#include<bits/stdc++.h>
#define ll int
using namespace std;
ll t,n,x,c,two,milt[200006],ms[200006],cm[200006];
bool cmp4(ll a,ll b){
	return a > b;
}
int main(){
	cin>>t;
	for(int i = 1;i <= 200000;i++){
		if(i % 2 == 0)milt[i] = milt[i/2] + 1;
		ms[i] = ms[i-1] + milt[i];
	}
	while(t--){
		cin>>n;
		two = 0;
		x = 1;
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			cin>>c;
			while(c % 2 == 0 && c > 0){
				c /= 2;
				two++;
			}
		}
		if(two + ms[n] < n){
			cout<<-1<<endl;
		}else{
			if(two >= n){
				cout<<0<<endl;
				continue;
			}
			for(int i = 1;i <= n;i++)cm[i] = milt[i];
			sort(cm+1,cm+n+1,cmp4);
			for(int i = 1;i <= n;i++){
				two += cm[i];
				ans++;
				if(two >= n)break;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
