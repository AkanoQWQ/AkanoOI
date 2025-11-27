#include<bits/stdc++.h>
using namespace std;
string s;
int i,len,a = 0,b;
int main(){
	freopen("pstring.in","r",stdin);
	freopen("pstring.out","w",stdout);
	cin>>s;
	len = s.length();
	for(i = 0;i < (len-1)/2/2;i++){
		if(s[i] != s[(len-1)/2-i-1]){
			a = true;
		}
	}
	for(i = 2;i < (len+3)/2/2;i++){
		if(s[i] != s[(len+3)/2-i-1]){
			b = true;
		}
	}
	if(a || b){
		cout<<"No";
	}else{
		cout<<"Yes";
	}
	return 0;
}
