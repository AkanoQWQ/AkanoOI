//AnarMessage Ver 2023.9.7
//based on AL 2023.9.7
//客户端版本 
#include<bits/stdc++.h>
#include<conio.h>
#include<AL/main.h>
using namespace std;
//程序常量 
const int queryTime = 1000;//对服务器的询问间隔,如果不匹配可能会被忽视 
const int showRefreshTime = 10;//刷新时间,太大会很不流畅,显得卡顿 
const int readSize = 4096;//阅读器大小,太小可能会出问题 

string serverName,userName;//服务器名称,用户名称 

vector<string> localMessages;//当前本地存的消息列表 
string nowMessage,lastMessage;//现在正在编辑的消息,缓存的自己的最后一条消息(用于使自己发的消息连贯) 

inline void Query(HANDLE pipe){
	Interactor<readSize> queryInter;
	queryInter.SetPipe(pipe,pipe);
	while(true){
		lastMessage = "";//因为刷新了信息,清空lastMessage 
		queryInter<<"query "<<localMessages.size()<<" ";//异步会导致问题吗 
		int stp = -2;
		queryInter>>stp;
		for(int i = localMessages.size();i < stp;i++){
			string str;
			queryInter>>str;
			localMessages.push_back(Decode(str));
		}
		Sleep(queryTime);
	}
	return ;
}
inline void Show(){
	while(true){
		Refresh();
		for(auto mess : localMessages){
			cout<<mess<<endl;
		}
		if(!localMessages.empty() && localMessages.back() != lastMessage && lastMessage != ""){
			cout<<lastMessage<<endl;
		}
		cout<<"-------------------------------------"<<endl;
		cout<<nowMessage<<endl;
		Sleep(showRefreshTime);
	}
	return ;
}
inline void ReadIn(){
	cout<<"请输入会话名称:"<<flush;
	cin>>serverName;
	cout<<"请输入用户名称:"<<flush;
	cin>>userName;
	return ;
}
inline HANDLE ConnectServer(){
	cout<<"客户端正在链接"<<endl; 
	Interactor<readSize> connector;
	connector.ConnectTwoWay(serverName);
	connector<<userName<<Flush;
	string result;
	connector>>result;
	while(result == "FAIL"){
		cout<<"名字重复,请重新输入:"<<flush;
		cin>>userName;
		connector<<userName<<Flush;
		connector>>result;
	}
	cout<<"链接成功"<<endl;
	return connector.GetReaderPipe();
}
inline void MainEditor(HANDLE pipe){
	Interactor<readSize> sendInter;
	sendInter.SetPipe(pipe,pipe);
	while(true){
		char ch = getch();
		if(int(ch) == 8){
			if(!nowMessage.empty())nowMessage.pop_back();
		}else if(int(ch) == 13){//回车 
			if(nowMessage == "")continue;//不发送空信息: 
			lastMessage = userName + " : " + nowMessage;//要模仿系统格式 
			sendInter<<"send "<<Encode(nowMessage)<<" "<<Flush;//必须要手动刷新,没有>>来自动刷新 
			nowMessage = "";
		}else if(int(ch) == 32){//空格 
			nowMessage += " ";
		}else{
			nowMessage += ch;
		}
	}
	return ;
}
inline void CloseServer(HANDLE& pipe){
	FlushFileBuffers(pipe);
	DisconnectNamedPipe(pipe);
	CloseHandle(pipe);
	return ;
}
inline void UpdateTitle(){
	string title = "AnarMessage client ~ "+userName+" on "+serverName+" ~";
	if(userName == "" && serverName == "")title = "AnarMessage client ~ waiting to connect ~";
	SetConsoleTitle(title.c_str());
	return ;
}
int main(){
	UpdateTitle();
	ReadIn();
	HANDLE pipe = ConnectServer();
	UpdateTitle();
	RefreshInit();//采用了双缓冲模式,此处开始启动
	 
	thread queryThread(Query,pipe);//启动对服务器的询问线程 
	queryThread.detach();
	thread showThread(Show);//启动本地的显示线程
	showThread.detach();
	
	MainEditor(pipe);//文本编辑器内容,对程序同时起阻塞作用 
	
	CloseServer(pipe);
	system("pause");
	return 0;
}
