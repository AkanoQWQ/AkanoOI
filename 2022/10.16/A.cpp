#include<bits/stdc++.h>
using namespace std;
int t,n,a[55],mp[257];
string s;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool able = 1;
		memset(mp,0,sizeof(mp));
		for(int i = 0;i < n;i++){
			cin>>a[i];
		}
		cin>>s;
		for(int i = 0;i < n;i++){
			if(mp[a[i]] == 0){
				mp[a[i]] = s[i];
			}else{
				if(mp[a[i]] != s[i]){
					able = 0;
					break;
				}
			}
		}
		if(able){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}	
	return 0;
}
