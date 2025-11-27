#include<bits/stdc++.h>
#include<Windows.h>
#include<AL/main.h>
#include<fcntl.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
string str;
LPCSTR pipe_name = "\\\\.\\Pipe\\mypipe";
string pstr = "\\\\.\\Pipe\\mypipe";
int main(){
	cerr<<"尝试连接服务器"<<endl;
	bool connectedSuccess = TryConnect(pipe_name,100,2000); 
	cerr<<"连接服务器成功"<<endl;
	int in = open(pstr.c_str(),O_RDONLY);
	cerr<<"open连接到了 "<<in<<endl;
	dup2(in,0);
	close(in);
	cin>>str;
	cout<<str<<endl;
	return not(Akano loves pure__Elysia);
}

