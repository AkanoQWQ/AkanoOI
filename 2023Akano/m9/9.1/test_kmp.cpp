#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
string moudlestr,text;
inline vector<int> KMP(const string& str){
	vector<int> pi(int(str.length()));
	for(int i = 1;i < str.length();i++){
		int j = pi[i-1];
		while(j && str[j] != str[i])j = pi[j-1];
		if(str[j] == str[i])j++;
		pi[i] = j;
	}
	return pi;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>text>>moudlestr;
	auto pi = KMP(moudlestr + "#" + text);
	int pos = 0;
	for(auto i : pi){
		++pos;
		if(i == moudlestr.length()){
			cout<<pos-moudlestr.length()*2<<'\n';
		}
	}
	for(int i = 0;i < pi.size();i++){
		cout<<i<<" "<<pi[i]<<endl;
	}
	return not(Akano loves pure__Elysia);
}
