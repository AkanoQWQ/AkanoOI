#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int MAX_CON = 2;
HANDLE hPipe,hEvent,hTread;
void OnStart() {
  LPCSTR lpPipeName = "\\\\.\\Pipe\\NamedPipe" ;
    // 创建管道实例
    hPipe =  CreateNamedPipe ( lpPipeName, PIPE_ACCESS_DUPLEX|FILE_FLAG_OVERLAPPED, \
          PIPE_TYPE_BYTE|PIPE_READMODE_BYTE|PIPE_WAIT, MAX_CON, 0, 0, 1000, NULL ) ;//
    if ( hPipe == INVALID_HANDLE_VALUE )
    {
      DWORD dwErrorCode = GetLastError () ;
      cerr<<"创建管道错误！"<<endl;
      return ;
    }
    // 为每个管道实例创建一个事件对象，用于实现重叠IO
    hEvent  =  CreateEvent ( NULL, false, false, false ) ;
    // 为每个管道实例分配一个线程，用于响应客户端的请求
    hTread = AfxBeginThread ( ServerThread, &PipeInst[i], THREAD_PRIORITY_NORMAL ) ;  
  cout<<"服务启动成功"<<endl;
  return ;
}
// 停止服务
void CMyDlg::OnStop() 
{
  DWORD dwNewMode = PIPE_TYPE_BYTE|PIPE_READMODE_BYTE|PIPE_NOWAIT ;
  for ( UINT i = 0; i < nMaxConn; i++ )
  {
    SetEvent ( PipeInst[i].hEvent ) ;
    CloseHandle ( PipeInst[i].hTread ) ;
    CloseHandle ( PipeInst[i].hPipe ) ;
  }
    
  this->SetWindowText ( "命名管道实例之服务器" ) ;
  this->MessageBox ( "停止启动成功" ) ;
}
// 线程服务函数
UINT ServerThread ( LPVOID lpParameter )
{
  DWORD  nReadByte = 0, nWriteByte = 0, dwByte = 0 ;  
  char  szBuf[MAX_BUFFER_SIZE] = {0} ;
  PIPE_INSTRUCT  CurPipeInst = *(PIPE_INSTRUCT*)lpParameter ;
  OVERLAPPED OverLapStruct = { 0, 0, 0, 0, CurPipeInst.hEvent } ;
  while ( true )
  {
    memset ( szBuf, 0, sizeof(szBuf) ) ;  
    // 命名管道的连接函数，等待客户端的连接（只针对NT）
    ConnectNamedPipe ( CurPipeInst.hPipe, &OverLapStruct ) ;
    // 实现重叠I/0，等待OVERLAPPED结构的事件对象
    WaitForSingleObject ( CurPipeInst.hEvent, INFINITE ) ;
    // 检测I/0是否已经完成，如果未完成，意味着该事件对象是人工设置，即服务需要停止
    if ( !GetOverlappedResult ( CurPipeInst.hPipe, &OverLapStruct, &dwByte, true ) )
      break ;
    // 从管道中读取客户端的请求信息
    if ( !ReadFile ( CurPipeInst.hPipe, szBuf, MAX_BUFFER_SIZE, &nReadByte, NULL ) )
    {
      MessageBox ( 0, "读取管道错误！", 0, 0 ) ;
      break ;
    }
    
    int a, b ;
    sscanf ( szBuf, "%d %d", &a, &b ) ;
    pMyDlg->nFirst    = a ;
    pMyDlg->nSecond    = b ;
    pMyDlg->nResValue  = a + b ;
    memset ( szBuf, 0, sizeof(szBuf) ) ;
    sprintf ( szBuf, "%d", pMyDlg->nResValue ) ;
    // 把反馈信息写入管道
    WriteFile ( CurPipeInst.hPipe, szBuf, strlen(szBuf), &nWriteByte, NULL ) ;
    pMyDlg->SetDlgItemInt ( IDC_FIRST, a, true ) ;
    pMyDlg->SetDlgItemInt ( IDC_SECOND, b, true ) ;
    pMyDlg->SetDlgItemInt ( IDC_RESULT, pMyDlg->nResValue, true ) ;
    // 断开客户端的连接，以便等待下一客户的到来
    DisconnectNamedPipe ( CurPipeInst.hPipe ) ;
  }
  return 0 ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	return 0;
}

