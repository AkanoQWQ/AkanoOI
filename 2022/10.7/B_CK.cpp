#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,pls = 1,mx = 1,t;
bool vis[100000000];
int main(){
	freopen("B.in","r",stdin);
	//freopen("BC.out","w",stdout);
	//x = 1 + (x*(4+2x));
	while(ans < 2000000){
		int pre = ans;
		ans += 1;
		vis[ans] = 1;
		//cout<<ans<<endl;
		ans += pls;
		vis[ans] = 1;
		//cout<<ans<<endl;
		ans += pls;
		vis[ans] = 1;
		//cout<<ans<<endl;
		pls++;
	}
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		int cnt = 0;
		for(int i = l;i <= r;i++){
			cnt += vis[i];
		}
		cout<<cnt<<endl;
	}
	return 0;
}
