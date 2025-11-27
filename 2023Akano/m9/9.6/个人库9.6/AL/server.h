#pragma once
#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;

template<int BUFSIZE>
class Reader{
	private:
		char buffer[BUFSIZE];
	public:
		istringstream iss;
		HANDLE _pipe;
		inline bool Read(){
			bool mainSuccess = false;
			string str;
			do{
				DWORD len = 0;
				bool fSuccess = ReadFile(_pipe,buffer,BUFSIZE * sizeof(char),&len,NULL);
				mainSuccess |= fSuccess;
				char buffer2[BUFSIZE + 1] = {0};//加上0?不会char数组所以不知道这是什么 
				memcpy(buffer2, buffer, len);
				str.append(buffer2);
				if(!fSuccess || len < BUFSIZE)break;
			}while(true);
			iss.str(str);
			iss.clear();
			return mainSuccess;
		}
		Reader& operator>>(auto& content){//要加引用...不然会出事 
			iss>>content;
			return *this;
		}
};
class Writer{
	private:
		
	public:
		ostringstream oss;
		HANDLE _pipe;
		inline void Clear(){
			oss.str("");
			return ;
		}
		Writer& operator<<(const auto& content){
			oss<<content;
			return *this;
		}
		inline bool WriteWithoutClear(){
			string now = oss.str();
			DWORD dwWrite;
			bool success = WriteFile(_pipe, now.c_str(), strlen(now.c_str()), &dwWrite, NULL);
			return success;
		}
		inline bool Write(){
			bool success = WriteWithoutClear();
			Clear();
			return success;
		}
		inline string Content(){
			return oss.str();
		}
};
inline bool TryConnect(const LPCSTR& name,int maxTime,int waitingTime){
	for(int t = 1;t <= maxTime;t++){
		if(WaitNamedPipe(name, NMPWAIT_WAIT_FOREVER) == FALSE){
			cout<<"没有找到链接,请稍等"<<endl; 
		}else{
			return true;
		}
		Sleep(waitingTime);
	}
	return false;
}
inline HANDLE DefaultPipe(LPCSTR name){
	return CreateNamedPipe(
		name,
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_MESSAGE |
		PIPE_READMODE_MESSAGE |
		PIPE_WAIT,
		PIPE_UNLIMITED_INSTANCES,
		0,
		0,
		NMPWAIT_WAIT_FOREVER,
		0
	);
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
