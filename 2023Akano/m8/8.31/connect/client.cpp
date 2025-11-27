#include<bits/stdc++.h>
#include<conio.h>
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
int t,a,b,ans;
int main(){
	cout<<"请输入管道名称:";
	cin>>name;
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
	reader._pipe = pipe,writer._pipe = pipe;
	cin>>t;
	writer<<t;
	writer.Write();
	for(int i = 1;i <= t;i++){
		cin>>a>>b;
		writer<<a<<" "<<b;
		writer.Write();
		reader.Read();
		reader>>ans;
		cout<<"计算结果为 : "<<a<<" + "<<b<<" = "<<ans<<endl;
	}
	FlushFileBuffers(pipe);
	DisconnectNamedPipe(pipe);
	CloseHandle(pipe);
	system("pause");
	return not(Akano loves pure__Elysia);
}

