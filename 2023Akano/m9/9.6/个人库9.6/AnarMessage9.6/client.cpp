//AnarMessage Ver 2023.9.6
//based on AL 2023.9.6
//客户端版本 
#include<bits/stdc++.h>
#include<conio.h>
#include<Windows.h>
#include<AL/main.h>
using namespace std;

const int queryTime = 1000;
const int showRefreshTime = 10;//刷新时间 
const int readSize = 1024;

string pre = "\\\\.\\Pipe\\";
string serverName;
LPCSTR pipe_name = "";

Writer sendWriter;

vector<string> localMessages;
string nowMessage,lastMessage,userName;
inline void Query(HANDLE pipe){
	Reader<readSize> queryReader;
	Writer queryWriter;
	queryReader._pipe = pipe,queryWriter._pipe = pipe;
	while(true){
		lastMessage = "";//因为刷新了信息,清空lastMessage 
		queryWriter<<"query "<<localMessages.size()<<" ";//异步会导致问题吗 
		queryWriter.Write();
		queryReader.Read();
		int stp = -2;
		queryReader>>stp;
		for(int i = localMessages.size();i < stp;i++){
			string str;
			queryReader>>str;
			localMessages.push_back(Decode(str));
		}
		Sleep(queryTime);
	}
	return ;
}
inline void Show(){
	while(true){
		Refresh();
		for(auto i : localMessages){
			cout<<i<<endl;
		}
		if(!localMessages.empty() && localMessages.back() != lastMessage && lastMessage != ""){
			cout<<lastMessage<<endl;
		}
		cout<<"------------------------------"<<endl;
		cout<<nowMessage<<endl;
		Sleep(showRefreshTime);
	}
	return ;
}
char name_save[1018]; 
int main(){
	SetConsoleTitle("AnarMessage client");
	cout<<"请输入会话名称:"<<flush;
	cin>>serverName;
	cout<<"请输入用户名称:"<<flush;
	cin>>userName;
	RefreshInit();//采用了双缓冲模式 
	
	
	strcpy(name_save,(pre + serverName).c_str());
	pipe_name = TEXT(name_save);
	
	cout<<"客户端正在链接"<<endl; 
	bool connectedSuccess = TryConnect(pipe_name,100,2000); 
	if(connectedSuccess == false){
		cout<<"客户端链接失败,未能找到链接"<<endl;
		return 0;
	}
	cout<<"链接成功"<<endl;
	HANDLE pipe = CreateFile(pipe_name, GENERIC_READ | GENERIC_WRITE, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	
	thread queryThread(Query,pipe);
	queryThread.detach();
	
	thread showThread(Show);
	showThread.detach();
	
	sendWriter._pipe = pipe;
	while(true){
		char ch = getch();
		if(int(ch) == 8){
			if(!nowMessage.empty())nowMessage.pop_back();
		}else if(int(ch) == 13){//回车 
			if(nowMessage == "")continue;//不发送空信息: 
			lastMessage = userName+" : "+nowMessage;
			sendWriter<<"send "<<Encode(lastMessage)<<" ";
			sendWriter.Write();
			nowMessage = "";
		}else if(int(ch) == 32){//空格 
			nowMessage += " ";
		}else{
			nowMessage += ch;
		}
	}
	
	FlushFileBuffers(pipe);
	DisconnectNamedPipe(pipe);
	CloseHandle(pipe);
	system("pause");
	return 0;
}
