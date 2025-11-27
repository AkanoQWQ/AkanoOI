#include<bits/stdc++.h>
using namespace std;
int t,n,a[2006],s[2006];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		memset(s,0,sizeof(s));
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			s[i] = s[i-1] + a[i];
		}
		int ans = n;
		for(int stlen = 1;stlen < ans;stlen++){
			int obj = s[stlen],rpos = stlen+1,maxlen = stlen;
			if(s[n] % obj != 0)continue;
			bool FD = 1;
			int sum = 0,cntlen = 0;
			while(sum < obj && rpos <= n){
				cntlen++;
				maxlen = max(maxlen,cntlen);
				sum += a[rpos];
				if(sum == obj){
					cntlen = 0;
					sum = 0;
				}else if(sum > obj){
					FD = 0;
					break;
				}
				rpos++;
			}
			if(FD){
				ans = min(ans,maxlen);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
