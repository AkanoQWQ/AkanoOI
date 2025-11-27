#include<bits/stdc++.h>
#include<Windows.h>
#include<fcntl.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
LPCSTR pipe_name = "\\\\.\\Pipe\\testIO";
string pstr = "\\\\.\\Pipe\\testIO";
string str;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	HANDLE pipe = CreateNamedPipe(pipe_name, PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT
		, PIPE_UNLIMITED_INSTANCES, 0, 0, NMPWAIT_WAIT_FOREVER, 0);
	cerr<<"先让客户端连接上"<<endl;
	getchar();
	int in = open(pstr.c_str(),O_RDONLY);
	dup2(in,0);
	cerr<<"现在输入str"<<endl;
	cin>>str;
	cerr<<"收到str"<<endl;
	cout<<str<<endl;
	return not(Akano loves pure__Elysia);
}

