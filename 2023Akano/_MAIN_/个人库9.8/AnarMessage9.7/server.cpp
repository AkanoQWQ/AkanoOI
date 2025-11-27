//AnarMessage Ver 2023.9.7
//based on AL 2023.9.7
//服务端版本 
#include<bits/stdc++.h>
#include<AL/main.h>
using namespace std;
//程序常量 
const int readSize = 4096;//太小可能会出问题 
const int waitingTime = 1100;//与服务器的通讯等待时间,应该和客户端的询问时间匹配 

string serverName;//服务器名称 
LPCSTR pipe_name = "";
char name_save[1018];//必须要用char数组存下来... 

vector<string> serverMessages;//存储的消息列表 
vector<string> userList;//用户列表 

inline void UpdateTitle(int x){
	string str = "AnarMessage server ~" + to_string(x) + " people on server "+serverName+" ~";
	SetConsoleTitle(str.c_str());
	return ; 
}
inline void Contact(HANDLE pipe){//只能传递pipe......
 	Interactor<readSize> inter;
 	inter.SetPipe(pipe,pipe);
	cout<<"建立了新链接"<<endl;
	string userName;
	inter>>userName;//先输入userName
	while(find(userList.begin(),userList.end(),userName) != userList.end()){
		inter<<"FAIL"<<Flush;
		inter>>userName;
	}
	inter<<"OK"<<Flush;
	userList.push_back(userName);
	UpdateTitle(userList.size());
 	while(true){
		string str;
		inter>>str;
		if(inter.Fail())break;
		cout<<"获得了指令 "<<str<<endl;
		if(str == "query"){
			int tail = 0;
			inter>>tail;
			inter<<serverMessages.size()<<" ";
			for(int i = tail;i < int(serverMessages.size());i++){
				inter<<serverMessages[i]<<" ";
			}
		}else if(str == "send"){
			inter>>str;
			cout<<"读取到了"<<Decode(str)<<endl;
			str = Decode(str);//解包 
			str = userName + " : " + str;//加上用户名 
			str = Encode(str);//再装包回去 
			serverMessages.push_back(str);
		}else{
			cerr<<"读取错误"<<endl;
		}
	}
	inter.DisConnect();
	cout<<"关闭了一个pipe!"<<endl;
	userList.erase(find(userList.begin(),userList.end(),userName));
	UpdateTitle(userList.size());
	return ;
} 
inline void ReadIn(){
	cout<<"请输入会话名称:"<<flush;
	cin>>serverName;
	cout<<"服务端启动,等待客户端链接"<<endl;
	return ;
}
Interactor<readSize> mainInter;//可以复用,只负责连接 
inline void ConnectNewClient(){
	while(true){
		cout<<"等待连接申请中"<<endl;
		mainInter.CreateTwoWay(serverName); 
		thread newThread(Contact,mainInter.GetReaderPipe());//因为是双向管道所以只用传一个pipe 
		newThread.detach();
	}
	return ;
}
int main(){
	UpdateTitle(0);
	ReadIn();
	ConnectNewClient();//尝试和新客户端建立连接,同时起阻塞作用 
 	
	cerr<<"关闭服务端"<<endl;
	system("pause");
	return 0;
}
