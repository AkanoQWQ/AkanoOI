#include<bits/stdc++.h>
#include<Windows.h>
#include<fcntl.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
LPCSTR pipe_name = "\\\\.\\Pipe\\mypipe";
string pstr = "\\\\.\\Pipe\\mypipe";
string str;
Writer wr;
int main(){
	HANDLE pipe = DefaultPipe(pipe_name);
	wr._pipe = pipe;
	cerr<<"等待连接"<<endl;
	if(ConnectNamedPipe(pipe, NULL) != NULL){
		cerr<<"连接成功"<<endl;
		while(cin>>str){
			wr<<str;
			wr.Write();
			FlushFileBuffers(pipe);
		}
	}else{
		cerr<<"出现错误 "<<GetLastError()<<endl;
	}
	cerr<<"连接完毕"<<endl;
	return not(Akano loves pure__Elysia);
}

