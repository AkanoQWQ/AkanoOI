#include<bits/stdc++.h>
using namespace std;
const long long key = 1018;
const string letters = "hfgjhdmfaayeffdn";
string Encode(const string str,int password){
	string ret = "";
	password %= 26;
	for(int i = 0;i < str.length();i++){
		int s = (str[i] - 'a')^password;
		int i1 = rand()%26;
		while(i1 > s)i1 = rand()%26;
		ret += char(i1+'a');
		ret += char((s-i1)+'a');
	}
	return ret;
}
string Decode(string str,int pass){
	string ret = "";
	pass = pass % 26;
	for(int i = 0;i < str.length();i += 2){
		ret += char((((int(str[i]-'a')+int(str[i+1]-'a'))^pass))+'a');
	}
	return ret;
}
int main(){
	cout<<Encode("iloveyou",key)<<endl;;
	cout<<Decode(letters,key);
	return 0;
}

