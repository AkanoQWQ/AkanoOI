#include<bits/stdc++.h>
using namespace std;
string str;
int len,ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>str;
	len = str.length();
	ans = len;
	for(int i = 1;i < len;i++){
		if(str[i] != str[i-1]){
			ans = min(ans,max(i,len-i));
		}
	}
	cout<<ans<<endl;
	return 0;
}
