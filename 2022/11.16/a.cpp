#include<bits/stdc++.h>
using namespace std;
string s;
int t;
char tablo[277];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	tablo['Y'] = 'e';
	tablo['e'] = 's';
	tablo['s'] = 'Y';
	cin>>t;
	while(t--){
		cin>>s;
		bool able = 1;
		char ch = tablo[s[0]];
		if(ch == 0){
			puts("NO");
			continue;
		}
		for(int i = 1;i < s.length();i++){
			if(s[i] != ch){
				able = 0;
				break;
			}
			ch = tablo[ch];
			if(ch == 0){
				able = 0;
				break;
			}
		}
		if(able){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}
