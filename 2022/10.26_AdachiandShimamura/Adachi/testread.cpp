#include<bits/stdc++.h>
using namespace std;
string sread(){
	string ret = "";
	char c = getchar();
	while(c < '0' || c > '9')c = getchar();
	while('0' <= c && c <= '9'){
		ret += c;
		c = getchar();
	}
	return ret;
}
int main(){
	string a,b,c,d;
	a = sread();
	b = sread();
	c = sread();
	cout<<a<<endl<<b<<endl<<c;
    return 0;
}


