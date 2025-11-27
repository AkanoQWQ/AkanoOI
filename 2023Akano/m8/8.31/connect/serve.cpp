#include<bits/stdc++.h>
#include<Windows.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

string pre = "\\\\.\\Pipe\\";
string name;
LPCSTR pipe_name = "";

Reader<10> reader;
Writer writer;
int a,b;
int main(){
	cout<<"请输入管道名称:";
	cin>>name;
	pipe_name = LPCSTR((pre+name).c_str());
	
	cout<<"服务端启动,等待客户端链接"<<endl;
	HANDLE pipe = CreateNamedPipe(pipe_name, PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT
		, PIPE_UNLIMITED_INSTANCES, 0, 0, NMPWAIT_WAIT_FOREVER, 0);
 	reader._pipe = pipe,writer._pipe = pipe;
 	while(true){
 		cout<<"等待下一个连接申请"<<endl;
 		if(ConnectNamedPipe(pipe, NULL) != NULL){
			cout<<"连接成功"<<endl;
			int repeatTime = 0;
			Sleep(1000);
			reader.Read();
			reader>>repeatTime;
			for(int t = 1;t <= repeatTime;t++){
				reader.Read();
				reader>>a>>b;
				int ans = a+b;
				writer<<ans;
				writer.Write();
			}
		}
		DisconnectNamedPipe(pipe);
	}
	CloseHandle(pipe);
	cout<<"关闭服务端"<<endl;
	system("pause");
	return not(Akano loves pure__Elysia);
}
