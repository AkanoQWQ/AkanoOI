#include<bits/stdc++.h>
using namespace std;
int T,n,m;
string s,t;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>s>>t;
		bool Tok = true;
		for(int i = 0;i < m-1;i++){
			if(t[i] == t[i+1])Tok = false;
		}
		bool OK = true;
		for(int i = 0;i < n-1;i++){
			if(s[i] == s[i+1]){
				if(Tok == false)OK = false;
				if(s[i] == t[0] || s[i+1] == t[m-1])OK = false;
			}
		}
		if(OK){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
