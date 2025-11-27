#include<bits/stdc++.h>
#include<string>
using namespace std;
int len,ans,i,j;
string s,t;
int main(){
	//freopen("change.in","r",stdin);
	//freopen("change.out","w",stdout);
	cin>>s;
	cin>>t;
	len = s.length();
	for(i = 0;i < len;i++){
		if(s[i] != t[i]){
			ans++;
		} 
	} 
	cout<<ans;
	return 0;
}
