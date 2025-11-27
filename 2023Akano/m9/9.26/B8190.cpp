#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n,a,cntf,cnt0,cnt1,cntn;
long long ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a;
		if(a < 0){
			ans += cntn;
		}
		if(a == 0){
			ans += cntn;
		}
		if(a == 1){
			ans += cntn + cntf + cnt0;
		}
		if(a >= 2){
			ans += cnt1 + cntf + cnt0;
		}
		if(a > 0){
			cntn++;
		}else if(a == 0){
			cnt0++;
		}else if(a < 0){
			cntf++;
		}
		if(a == 1)cnt1++;
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
