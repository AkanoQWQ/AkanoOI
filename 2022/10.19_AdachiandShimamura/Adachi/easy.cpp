#include<bits/stdc++.h>
#define ull unsigned long long
const int b = 131;
using namespace std;
string s,t;
int k;
ull ans[5006];
bool hw(string s,int st,int ed){
	for(int i = st;i < (st+ed+1)/2;i++){
		if(s[i] != s[ed-i+st]){
			return false;
		}
	}
	return true;
}
ull hs(string s,int st,int ed){
	ull ret = 0;
	for(int i = st;i <= ed;i++){
		ret *= b;
		ret += s[i] - 'a';
	}
	return ret;
}
int main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	cin>>s>>k;
	t += s[0];
	t += s[0];
	ans[1] = hs(t,0,1);
	for(int i = 1;i < s.length();i++){
		char c = (ans[i]+s[i]-'a')%26 + 'a';
		string ct = "";
		int ss = 1;
		while(ss+1 < t.length()-1){
			swap(t[ss],t[ss+1]);
			ss += 2;
		}
		ct = t[0];
		ct +=  c;
		for(int j = 1;j < t.length()-1;j++){
			ct += t[j];
		}
		ct += c;
		ct += t[t.length()-1];
		t = ct;
		for(int j = 1;j < t.length();j += 2){
			if(hw(t,0,j)){
				ans[i+1] += hs(t,0,j);
			}
		}
	}
	for(int i = 1;i <= s.length();i += k){
		ull cnt = 0;
		for(int j = 0;j < k;j++){
			cnt ^= ans[i+j];
		}
		cout<<cnt<<endl;
	}
	return 0;
}
