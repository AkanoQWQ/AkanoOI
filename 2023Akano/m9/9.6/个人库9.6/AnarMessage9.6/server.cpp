//AnarMessage Ver 2023.9.6
//based on AL 2023.9.6
//服务端版本 
#include<bits/stdc++.h>
#include<Windows.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

const int readSize = 1024;//太小可能会出问题 
const int waitingTime = 1100;//与服务器的通讯等待时间,应该和客户端的询问时间匹配 

string pre = "\\\\.\\Pipe\\";
string serverName;
LPCSTR pipe_name = "";

vector<string> serverMessages;

inline void Solve(HANDLE pipe){
	cout<<"建立了新链接"<<endl;
	Reader<readSize> reader;
	Writer writer;
	reader._pipe = pipe,writer._pipe = pipe;
 	while(true){
 		bool readin = reader.Read();
 		if(readin == false){
 			Sleep(waitingTime);
 			readin |= reader.Read();
 			if(readin == false)break;
		}
		string str;
		reader>>str;
		cerr<<"获得了指令 "<<str<<endl;
		if(str == "query"){
			int tail = 0;
			reader>>tail;
			writer<<serverMessages.size()<<" ";
			for(int i = tail;i < int(serverMessages.size());i++){
				writer<<serverMessages[i]<<" ";
			}
			writer.Write();
		}else if(str == "send"){
			string str;
			reader>>str;
			cout<<"读取到了"<<Decode(str)<<endl;
			serverMessages.push_back(str);
		}else{
			cerr<<"读取错误"<<endl;
		}
	}
	DisconnectNamedPipe(pipe);
	CloseHandle(pipe);
	cout<<"关闭了一个pipe!"<<endl; 
	return ;
} 
char name_save[1018];//必须要用char数组存下来... 

int main(){
	SetConsoleTitle("AnarMessage server");
	cout<<"请输入会话名称:"<<flush;
	cin>>serverName;
	
	strcpy(name_save,(pre + serverName).c_str());
	pipe_name = TEXT(name_save);
	
	cout<<"服务端启动,等待客户端链接"<<endl;
 	while(true){
 		HANDLE pipe = DefaultPipe(pipe_name);
		if(pipe == INVALID_HANDLE_VALUE){
			cerr<<"管道创建失败!"<<endl;
			return 0;
		} 
		
		cout<<"等待连接申请中"<<endl;
		if(ConnectNamedPipe(pipe,NULL)){
			thread newThread(Solve,pipe);
			newThread.detach();
		}else{
			cerr<<"链接错误"<<endl;
			break;
		}
	}
	cerr<<"关闭服务端"<<endl;
	system("pause");
	return not(Akano loves pure__Elysia);
}
