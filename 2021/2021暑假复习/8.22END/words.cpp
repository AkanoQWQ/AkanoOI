#include<bits/stdc++.h>
using namespace std;
string s;
int t,i,len,n,l;
int main(){
	freopen("words.in","r",stdin);
	freopen("words.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>s>>n;
		len = s.length();
		n %= len;
		n = len - n;
		for(i = n;i < len;i++){
			cout<<s[i];
		}
		for(i = 0;i < n;i++){
			cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}

