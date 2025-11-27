#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int> m;
int main(){
	freopen("token.txt","r",stdin);
	string s;
	while(cin>>s){
		const int len = s.length();
		for(int i = 0;i < len;i++){
			++m[s[i]];
		}
	}
	for(auto i : m){
		cout<<i.first<<":"<<i.second<<endl;
	}
	return 0;
}

