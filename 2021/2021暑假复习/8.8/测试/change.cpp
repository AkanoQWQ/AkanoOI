#include<bits/stdc++.h>
using namespace std;
string s,t;
int ans,i,len;
int main(){
	freopen("change.in","r",stdin);
	freopen("change.out","w",stdout);
	cin>>s>>t;
	len = s.length();
	for(i = 0;i < len;i++){
		if(s[i] != t[i])ans++;
	}
	cout<<ans;
	return 0;
}

