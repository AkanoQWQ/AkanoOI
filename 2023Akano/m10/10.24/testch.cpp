#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
string str = "abc";
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	char *chp;
	chp = const_cast<char*>(str.c_str());
	cerr<<str<<endl;
	*chp = 's';
	*(chp+1) = 't';
	*(chp+2) = 'r';
	*(chp+3) = 'w';
	cerr<<str<<endl;
	return not(Akano loves pure__Elysia);
}
