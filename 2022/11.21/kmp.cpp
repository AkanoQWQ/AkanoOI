#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e6;
string a,b;
int pi[MAXN];
void kmp(string s){
	for(int i = 1;i < s.length();i++){
		int j = pi[i-1];
		while(j > 0 && s[i] != s[j])j = pi[j-1];
		if(s[i] == s[j])j++;
		pi[i] = j;
	}
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>a>>b;
	kmp(b+"!"+a);
	string str = b + "," + a;
	for(int i = 0;i <= 14;i++){
		cout<<str[i]<<" "<<i<<",";
	}
	cout<<endl;
	for(int i = b.length()+1;i < a.length()+b.length();i++){
		if(pi[i] == a.length()){
			cout<<i - a.length()<<endl;
		}
	}
	cout<<endl;
	for(int i = b.length()+1;i < a.length()+b.length();i++){
		cout<<pi[i]<<" ";
	}
	return 0;
}

