#include<bits/stdc++.h>

#include<Windows.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
filebuf buf;
istream ss(&buf);
inline void WriteOut(){
	string str;
	while(ss>>str){
		cout<<str<<" in WO"<<endl;
	}
	cerr<<"Out"<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	ss.tie(&cout);
	string s;
	cerr<<"getin s"<<endl;
	thread mth(WriteOut);
	mth.detach();
	while(cin>>s){
		ss>>s;
		cout<<s<<" in main"<<endl;
	}
	return not(Akano loves pure__Elysia);
}

