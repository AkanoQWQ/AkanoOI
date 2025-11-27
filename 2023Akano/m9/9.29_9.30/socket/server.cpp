#include<bits/stdc++.h>
#include<unistd.h>
#include<winsock2.h>
#include<ws2tcpip.h>
using namespace std;

struct Package{
	
};

struct SocketConnector{
	const static int bufferSize = 2048;
	WORD sockVersion;
	WSADATA wsaData;  
	SOCKET slisten;
	string lastError;
	sockaddr_in sin;
	char buffer[bufferSize];
	inline bool Init(){//返回是否成功
		//初始化WSA
		sockVersion = MAKEWORD(2,2);
		if(WSAStartup(sockVersion, &wsaData) != 0){  
			return false;  
		}
		//创建套接字  
		slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  
		if(slisten == INVALID_SOCKET){  
			lastError = "socket error!";
			return false;  
		}
		//绑定IP和端口  
		sin.sin_family = AF_INET;  
		sin.sin_port = htons(8888);  
		sin.sin_addr.S_un.S_addr = INADDR_ANY;   
		if(bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR){  
			lastError = "bind error!";  
			return false;
		}  
		//开始监听  
		if(listen(slisten, 5) == SOCKET_ERROR){  
			lastError = "listen error!";  
			return false;  
		}
		return true;
	}
	inline bool ReadData(SOCKET source){
		int retLen = recv(source,buffer,bufferSize,0);         
		if(retLen > 0)buffer[retLen] = 0x00;  
		return retLen > 0;
	}
	inline void Read(){
		//循环接收数据  
		SOCKET sClient;
		sockaddr_in remoteAddr;  
		int nAddrlen = sizeof(remoteAddr);  
		
		while(true){  
			cout<<"等待连接..."<<endl;  
			sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);  
			if(sClient == INVALID_SOCKET)  {  
				lastError = "accept error !";  
				continue;  
			}  
			printf("接受到一个连接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));  
			
			//接收数据  
			bool suc = ReadData(sClient);
			if(suc){
				cout<<buffer<<endl;
			}
			
			//发送数据  
			const char * sendData = "你好，TCP客户端！\n";  
			send(sClient, sendData, strlen(sendData), 0);  
			closesocket(sClient);  
		}
		return ;
	}
	inline void Close(){
		closesocket(slisten);  
		WSACleanup();  
		return ;
	}
}server;
int main(){
	server.Init();
	server.Read();
	
	return 0;  
}
