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

vector<string> server_messages;
const int waitingTime = 1100;
inline string Decode(const string& str){
	string ret;
	for(auto i : str){
		if(i == '_'){
			ret += " ";
		}else{
			ret += i;
		}
	}
	return ret;
}
inline void Solve(HANDLE pipe){
	cout<<"建立了新链接"<<endl;
	Reader<10> reader;
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
			writer<<int(server_messages.size())-1<<" ";
			for(int i = tail;i < int(server_messages.size());i++){
				writer<<server_messages[i]<<" ";
			}
			writer.Write();
		}else if(str == "send"){
			string str;
			reader>>str;
			cerr<<"读取到了"<<Decode(str)<<endl;
			server_messages.push_back(Decode(str));
		}else{
			cerr<<"读取错误"<<endl;
		}
	}
	DisconnectNamedPipe(pipe);
	CloseHandle(pipe);
	cerr<<"关闭了pipe!"<<endl; 
	return ;
} 
int a,b;
char name_save[1018];//必须要用char数组存下来... 
int main(){
//	cout<<"请输入管道名称:"<<endl;
//	cin>>name;
	name = "test";
	strcpy(name_save,(pre + name).c_str());
	pipe_name = TEXT(name_save);
	
	cout<<"服务端启动,等待客户端链接"<<endl;
 	while(true){
 		HANDLE pipe = CreateNamedPipe(
			pipe_name,
			PIPE_ACCESS_DUPLEX,
			PIPE_TYPE_MESSAGE |
			PIPE_READMODE_MESSAGE |
			PIPE_WAIT,
			PIPE_UNLIMITED_INSTANCES,
			0,
			0,
			0,//NMPWAIT_WAIT_FOREVER
			0
			);
		if(pipe == INVALID_HANDLE_VALUE){
			cerr<<"管道创建失败!"<<endl;
			return 0;
		} 
		
		cout<<"等待连接申请中"<<endl;
		if(ConnectNamedPipe(pipe,NULL)){
			thread newThread(Solve,pipe);
			newThread.detach();
		}else{
			cout<<"链接错误"<<endl;
		}
	}
	cout<<"关闭服务端"<<endl;
	system("pause");
	return not(Akano loves pure__Elysia);
}
