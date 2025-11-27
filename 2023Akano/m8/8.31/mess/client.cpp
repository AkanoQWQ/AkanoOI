#include<bits/stdc++.h>
#include<conio.h>
#include<Windows.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int queryTime = 1000;
string pre = "\\\\.\\Pipe\\";
string name;
LPCSTR pipe_name = "";

Writer sendWriter;
string mess;
int tail = 0;
inline void Query(HANDLE pipe){
	Reader<512> queryReader;
	Writer queryWriter;
	queryReader._pipe = pipe,queryWriter._pipe = pipe;
	while(true){
		queryWriter<<"query "<<tail;//异步会导致问题吗 
		queryWriter.Write();
		queryReader.Read();
		int stp = -2;
		queryReader>>stp;
		for(int i = tail;i <= stp;i++){
			string str;
			queryReader>>str;
			cout<<str<<endl;
		}
		tail = stp+1;
		Sleep(queryTime);
	}
	return ;
}
inline string Encode(const string& str){
	string ret;
	for(auto i : str){
		if(i == ' '){
			ret += "_";
		}else{
			ret += i;
		}
	}
	return ret;
}
int main(){
//	cout<<"请输入管道名称:"<<endl;
//	cin>>name;
	name = "test";
	pipe_name = LPCSTR((pre+name).c_str());
	
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
	sendWriter._pipe = pipe;
	while(getline(cin,mess)){
		cerr<<"发送了"<<Encode(mess)<<endl;
		sendWriter<<"send "<<Encode(mess)<<" ";//必须有空格 
		sendWriter.Write();
	}
	FlushFileBuffers(pipe);
	DisconnectNamedPipe(pipe);
	CloseHandle(pipe);
	system("pause");
	return not(Akano loves pure__Elysia);
}

