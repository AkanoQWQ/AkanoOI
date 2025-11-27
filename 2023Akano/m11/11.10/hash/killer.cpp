#include <bits/stdc++.h>

using namespace std;

ofstream os("hack.in");

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	string s; s.resize(1<<12);
	
	s[0]='a'; int n=1;
	for(int i=0;i<12;++i) {
		for(int j=0;j<n;++j) s[j+n]=((s[j]-'a')^1)+'a';
		n<<=1;
	}
	
	os<<s<<endl;
	os<<(1<<11)<<endl;
	
	return 0;
}
