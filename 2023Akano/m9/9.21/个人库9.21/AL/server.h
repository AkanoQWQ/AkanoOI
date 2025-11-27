#pragma once
#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;
//默认常量
const int DEFAULT_CONNECT_MAXTIME = 1e9;//默认无限进行下去 
const int DEFAULT_CONNECT_WAITINGTIME = 1000;//默认每秒一次
const string PIPE_PRE = "\\\\.\\Pipe\\";
inline bool AllSpaceOrEndl(const string& str){//返回是否没有非空非换行字符 
	for(auto i : str)if(i != ' ' && i != '\n')return false;
	return true; 
}
struct FlushFlag{
	
}; 
inline void Flush(FlushFlag flag){
	return ;
}
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
			
			//加一个空格很重要!和下面判断EOF相关 
			//str += " ";
			//然而这一段被撤销了,具体原因看下面 
			
			iss.str(str);
			iss.clear();
			return mainSuccess;
		}
		template<typename T>
		Reader& operator>>(T& content){//要加引用...不然会出事
			iss>>content;
			return *this;
		}
};
class Writer{
	public:
		ostringstream oss;
		HANDLE _pipe;
		inline void Clear(){
			oss.str("");
			return ;
		}
		template<typename T>
		Writer& operator<<(const T& content){
			oss<<content;
			return *this;
		}
		inline bool WriteWithoutClear(){
			string now = oss.str();
			DWORD dwWrite;
			
			/*   实现不了ww 
			//想要重叠IO...(是这么说吗)
			//不知道放一个局部变量有没有问题......感觉问题很大啊 
			OVERLAPPED query;
			//在函数调用中使用结构之前，应始终将此结构的任何未使用成员初始化为零
			//上文来自learn.microsoft.com 
			query.hEvent = NULL;
			query.Internal = NULL;
			query.InternalHigh = NULL;
			//添加到末尾,所以加上这些
			//> "若要写入文件末尾，请将 OVERLAPPED 结构的 Offset 和 OffsetHigh 成员指定为0xFFFFFFFF"
			//> "这在功能上等效于之前调用 CreateFile 函数以使用FILE_APPEND_DATA访问打开 hFile"----教程 
			query.Offset = 0xFFFFFFFF;
			query.OffsetHigh = 0xFFFFFFFF;
			*/ 
			
			bool success = WriteFile(
				_pipe,
				now.c_str(),
				strlen(now.c_str()),
				&dwWrite,
				NULL//如果不需要重叠IO的话设置为NULL 
			);
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

//一些默认用的管道设置 
inline bool TryConnect(const LPCSTR& name,int maxTime,int waitingTime){
	for(int t = 1;t <= maxTime;t++){
		if(WaitNamedPipe(name, NMPWAIT_WAIT_FOREVER) == FALSE){
			//没有找到链接,请稍等
		}else{
			return true;
		}
		Sleep(waitingTime);
	}
	return false;
}
inline bool TryConnect(const LPCSTR& name){
	return TryConnect(name,DEFAULT_CONNECT_MAXTIME,DEFAULT_CONNECT_WAITINGTIME);
}
inline HANDLE DefaultPipe(const LPCSTR& name){
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
inline HANDLE ConnectPipe(const LPCSTR& name){
	return CreateFile(
		name,
		GENERIC_READ |
		GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,//这个 FILE_FLAG_OVERLAPPED 可以吗 
		NULL
	);
}

//加强版Reader/Writer
//因为要用到一些默认设置所以放在了默认管道函数的下面 
template<int BUFSIZE>
class ExReader{
	public:
		Reader<BUFSIZE> reader;
		HANDLE& _pipe = reader._pipe;
		template<typename T>
		ExReader& operator>>(T& content){
			do{//可能iss剩无用的空内容,读取不到还是EOF 指正:应该是fail()状态 
				while(reader.iss.eof()){//一直读取直到不是EOF   删除:AllSpaceOrEndl(reader.iss.str()),表示且不为空
					reader.Read();
				}
				//记录一下这里的问题
				//首先这个逻辑和上面Reader的 str +=" "有很大关系  PS:这段已经被注释了,有更好的写法 
				//考虑一种情况,想要读入一个int但是此时iss里面剩下空格
				//不会触发EOF,其实也不会出触发 AllSpaceOrEndl(事实上这句好像没有用了,于是注释掉)
				//解决方法:如果尝试输入content失败,貌似会触发fail(),用这个判断要不要继续读 
				if(GetLastError() == 109){
					return *this;//管道关闭了 
				}
				reader>>content;
				//如果读到的内容没有输进去content,那么触发fail继续读 
			}while(reader.iss.fail()); 
			return *this;
		}
		//特别注意,原本这里大括号前面加了一个const,不知道去掉了有没有问题 
		operator void*(){//用于把对象本身当做一个值返回,比如while(cin) 
			return (reader.iss.fail() && (!reader.Read())) ? 0 : const_cast<ExReader*>(this);
		}
		inline void Connect(const string& name){//默认Writer指向Reader,Writer发起Reader打开 
			string newstr = PIPE_PRE + name;//很重要!不然长了会出bug 
			LPCSTR pipeName = TEXT(newstr.c_str());
			TryConnect(pipeName);
			_pipe = ConnectPipe(pipeName);
			return ;
		}
		ExReader(){}
		ExReader(const string& str){
			Connect(str);
			return ;
		}
};
class ExWriter{
	public:
		Writer writer;
		HANDLE& _pipe = writer._pipe;
		template<typename T>
		ExWriter& operator<<(const T& content){
			writer<<content;
			return *this;
		}
		ExWriter& operator<<(void (*func)(FlushFlag)){
			writer.Write();
			return *this;
		}
		inline void Connect(const string& name){
			string newstr =  PIPE_PRE + name;
			LPCSTR pipeName = TEXT(newstr.c_str());
			_pipe = DefaultPipe(pipeName);
			ConnectNamedPipe(_pipe,NULL);
			return ;
		}
		ExWriter(){}
		ExWriter(const string& str){
			Connect(str);
			return ;
		}
};
template<int BUFSIZE>
class Interactor{
	private:
		ExReader<BUFSIZE> reader;
		ExWriter writer;
		Reader<BUFSIZE>& sonReader = reader.reader;
		Writer& sonWriter = writer.writer;
		bool failed;
	public:
		template<typename T>
		Interactor& operator<<(const T& content){
			writer<<content;
			if(GetLastError() == 109)failed = true;
			return *this;
		}
		template<typename T>
		Interactor& operator>>(T& content){
			sonWriter.Write();//绑定,相当于tie 
			reader>>content;
			if(GetLastError() == 109)failed = true;
			return *this;
		}
		operator void*(){//用于把对象本身当做一个值返回,比如while(cin) 
			return (sonReader.iss.fail() && (!sonReader.Read())) ? 0 : const_cast<Interactor*>(this);
		}
		//两种连接方式,无论是哪种的创建都有顺序
		//方式1必须先Create再Connect
		//方式2必须有一个First有一个Second 
		//连接方式1:两个 Interactor 的RW共用一个管道 
		inline void CreateTwoWay(const string& name){
			string newstr =  PIPE_PRE + name;
			LPCSTR pipeName = TEXT(newstr.c_str());
			HANDLE pipe = DefaultPipe(pipeName);
			reader._pipe = writer._pipe = pipe;
			ConnectNamedPipe(pipe,NULL);
			return ;
		}
		inline void ConnectTwoWay(const string& name){
			string newstr =  PIPE_PRE + name;
			LPCSTR pipeName = TEXT(newstr.c_str());
			TryConnect(pipeName);
			HANDLE pipe = ConnectPipe(pipeName);
			reader._pipe = writer._pipe = pipe;
			return ;
		}
		//连接方式2:两个 Interactor 的RW使用两个单向管道(泉限还是双向) 
		//F2S first to second   S2F second to first
		inline void FirstOneWay(const string& name){
			writer.Connect(name + "F2S");
			reader.Connect(name + "S2F");
		}
		inline void SecondOneWay(const string& name){
			reader.Connect(name + "F2S");
			writer.Connect(name + "S2F");
		}
		inline void DisConnect(){
			HANDLE pipe = reader._pipe;//随便一个应该都行 
			DisconnectNamedPipe(pipe);
			CloseHandle(pipe);
			return ;
		}
		Interactor& operator=(const Interactor& obj){//无法复制stringstream!直接不复制了 
			reader._pipe = obj.reader._pipe;//只复制pipe 
			writer._pipe = obj.writer._pipe;
			return *this;
		}
		inline void SetPipe(HANDLE pipew,HANDLE piper){
			writer._pipe = pipew,reader._pipe = piper; 
			return ;
		}
		inline HANDLE GetWriterPipe(){
			return writer._pipe; 
		} 
		inline HANDLE GetReaderPipe(){
			return reader._pipe; 
		}
		inline void ReSet(){
			failed = false;
			return ;
		}
		inline bool Fail(){
			return failed;
		}
		Interactor(){
			failed = false;
			return ;
		}
};

//一个不基于ReaderWriter(但是底层类似)的交互器Connector
//特点是定时交互,发送Read和Write请求
//需要对方也是Connector
 


//服务器使用_作为连接符的解码编码 
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
