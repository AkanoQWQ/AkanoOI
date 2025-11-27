#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e6 + 6;
string s1,s2,s3;
int n,pi[MAXN];
void kmp(const string& str){
	const int len = str.length();
	for(int i = 1;i < len;i++){
		int j = pi[i-1];
		while(j > 0 && str[i] != str[j])j = pi[j-1];
		if(str[i] == str[j])j++;
		pi[i] = j;
	}
	return ;
}
int main(){
	cin>>s1>>s2;
	n = s2.length();
	s3 = s2 + "." + s1;
	kmp(s3);
	for(int i = 0;i < s3.length();i++){
		if(pi[i] == n){
			cout<<i-n-(n-1)<<endl;
		}
	}
	for(int i = 0;i < n;i++){
		cout<<pi[i]<<" ";
	}
	return 0;
}
