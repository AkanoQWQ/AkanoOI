#include<bits/stdc++.h>
using namespace std;
string str;
int pi[2006118],n;
int KMP(){
	cin>>n>>str;
	for(int i = 1;i < n;i++){
		int j = pi[i-1];
		while(str[i] != str[j] && j)j = pi[j-1];
		if(str[i] == str[j])++j;
		pi[i] = j;
	}
	cout<<n-pi[n-1];
	return 0;
}
int main(){
	return KMP();
}

