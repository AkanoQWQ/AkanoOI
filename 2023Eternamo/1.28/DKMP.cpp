#include<bits/stdc++.h>
using namespace std;
string str,s;
int pi[2006118],m,orglen,vis[2006118];
int KMP(){
	cin>>s>>m;
	while(m--){
		char ch;
		cin>>ch;
		str += ch;
	}
	const int strlen = str.length();
	const int slen = s.length();
	for(int i = 1;i < strlen;i++){
		int j = pi[i-1];
		while(str[i] != str[j] && j)j = pi[j-1];
		if(str[i] == str[j])++j;
		pi[i] = j;
	}
	int stat = 0;
	for(int i = 0;i < slen;i++){
		while(s[i] != str[stat] && stat)stat = pi[stat-1];
		if(s[i] == str[stat+1])stat++;
		vis[stat]++;
		cout<<i<<" step vis "<<stat<<endl;
	}
	for(int i = str.length()-1;i >= 0;i--){
		vis[pi[i]] += vis[i]; 
	}
	for(int i = 1;i <= str.length();i++){
		cout<<vis[i]<<endl;
	}
	return 0;
}
int main(){
	return KMP();
}

