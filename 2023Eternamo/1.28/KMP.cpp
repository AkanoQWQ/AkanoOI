#include<bits/stdc++.h>
using namespace std;
string s,t;
int pi[2006118];
int KMP(){
	cin>>s>>t;
	string str = t + "." + s;
	for(int i = 1;i < str.length();i++){
		int j = pi[i-1];
		while(str[i] != str[j] && j)j = pi[j-1];
		if(str[i] == str[j])++j;
		pi[i] = j;
		if(pi[i] == t.length()){
			cout<<i+1-int(t.length()*2)<<endl;
		}	
	}
	
	for(int i = 0;i < t.length();i++){
		cout<<pi[i]<<" ";
	}
	return 0;
}
int main(){
	return KMP();
}

