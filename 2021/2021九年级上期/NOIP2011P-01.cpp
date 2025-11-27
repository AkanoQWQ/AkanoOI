#include<bits/stdc++.h>
using namespace std;
string s;
int i,j,len;
bool high,out;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	while(cin>>s){
		high = 1,out = 0;
		len = s.length();
		if(s == "-0"){
			cout<<0;
			out = 1;
		}
		if(s[0] == '-')cout<<'-';
		for(i = len-1;i >= 0;i--){
			if(s[i] == '-')continue;
			if(s[i] != '0')high = 0;
			if(s[i] == '0' && high == 1)continue;
			cout<<s[i];
			out = 1;
		}
		if(out == 0)cout<<0;
		cout<<endl;
	}
	return 0;
}

