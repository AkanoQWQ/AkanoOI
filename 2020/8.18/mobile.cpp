#include<bits/stdc++.h>
using namespace std;
int ans,i;
char inin[206],c;
int main(){
	freopen("mobile.in","r",stdin);
	freopen("mobile.out","w",stdout);
	gets(inin);
	for(i = 0;i < strlen(inin);i++){
		c = inin[i];
		if(c == '1'||c == '2'||c == '3'||c == '4'||c == '5'||c == '6'||c == '7'||c == '8'||c == '9'||c == '0'||c == '*'||c == '#'){
			ans += 1;
		}else if(c == 'a'||c == 'd'||c == 'g'||c == 'j'||c == 'm'||c == 'p'||c == 't'||c == 'w'){
			ans += 1;
		}else if(c == 'b'||c == 'e'||c == 'h'||c == 'k'||c == 'n'||c == 'q'||c == 'u'||c == 'x'){
			ans += 2;
		}else if(c == 'c'||c == 'f'||c == 'i'||c == 'l'||c == 'o'||c == 'r'||c == 'v'||c == 'y'){
			ans += 3;
		}else if(c == 's'||c == 'z'){
			ans += 4;
		}else if(c == ' '){
			ans += 1;
		}
	}
			cout<<ans;
		return 0;
}
