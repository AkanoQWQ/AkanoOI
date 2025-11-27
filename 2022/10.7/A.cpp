#include<bits/stdc++.h>
using namespace std;
int t,n,k,cnt[28];
string s,ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k;
		cin>>s;
		memset(cnt,0,sizeof(cnt));
		for(int i = 0;i < n;i++){
			cnt[s[i] - 'a']++;
		}
		ans = "";
		for(int i = 1;i <= k;i++){
			int maxj = -1;
			for(int j = 0;j < n/k;j++){
				if(cnt[j] != 0){
					cnt[j]--;
					maxj = j;
				}else{
					break;
				}
			}
			ans += maxj + 'a' + 1 ;
		}
		cout<<ans<<endl;
	}
	return 0;
}

