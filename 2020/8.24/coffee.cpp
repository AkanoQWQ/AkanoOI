#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	cin>>s;
	if(s[2] == s[3] && s[4] == s[5]){
		cout<<"Yes";
		return 0;
	}else{
		cout<<"No";
		return 0;
	}
}
