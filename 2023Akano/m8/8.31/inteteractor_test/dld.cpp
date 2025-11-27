#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int a = 2,b = 3,res;
void OnSubmit() {
  // 打开管道
  HANDLE hPipe = CreateFile("\\\\.\\Pipe\\NamedPipe", GENERIC_READ | GENERIC_WRITE, \
    0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL) ;
  if ( hPipe == INVALID_HANDLE_VALUE )
  {
    cout<<"打开管道失败，服务器尚未启动,或者客户端数量过多"<<endl;
    return ;
  }
  DWORD nReadByte, nWriteByte ;
  char szBuf[1024] = {0} ;
  // 把两个整数(a,b)格式化为字符串
  sprintf ( szBuf, "%d %d",a,b) ;
  // 把数据写入管道
  WriteFile ( hPipe, szBuf, strlen(szBuf), &nWriteByte, NULL ) ;
  memset ( szBuf, 0, sizeof(szBuf) ) ;
  // 读取服务器的反馈信息
  ReadFile ( hPipe, szBuf, 1024, &nReadByte, NULL ) ;
  // 把返回信息格式化为整数
  sscanf ( szBuf, "%d",&res) ;
  CloseHandle ( hPipe ) ;
  return ;
}
int main(){
	OnSubmit();
	return 0;
}
