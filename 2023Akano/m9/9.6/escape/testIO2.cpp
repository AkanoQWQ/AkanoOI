#include<bits/stdc++.h>
#include<conio.h>
#include<Windows.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

LPCSTR pipe_name = "\\\\.\\Pipe\\testIO";

Reader<10> reader;
Writer writer;
string str;
int main(){
	
	cout<<"客户端正在链接"<<endl; 
	bool connectedSuccess = TryConnect(pipe_name,100,2000); 
	if(connectedSuccess == false){
		cout<<"客户端链接失败,未能找到链接"<<endl;
		return 0;
	}
	cout<<"链接成功"<<endl;
	HANDLE pipe = CreateFile(pipe_name, GENERIC_READ | GENERIC_WRITE, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	reader._pipe = pipe,writer._pipe = pipe;
	while(true){
		cin>>str;
		writer<<str;
		writer.Write();
	}
	FlushFileBuffers(pipe);
	DisconnectNamedPipe(pipe);
	CloseHandle(pipe);
	system("pause");
	return not(Akano loves pure__Elysia);
}

