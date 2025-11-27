#include<bits/stdc++.h>
#include<string>
using namespace std;
string s,t;
int main(){
	freopen("reg.in","r",stdin);
	freopen("reg.out","w",stdout);
	cin>>s>>t;
	t[t.length()-1] = ' ';
	s += ' ';
	if(s == t){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}
