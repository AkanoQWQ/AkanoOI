#include<bits/stdc++.h>
#include<windows.h>
#include<tlhelp32.h>
#include<tchar.h>
#pragma comment(lib,"psapi.lib")
#include<psapi.h>
using namespace std;
// dos 文件路径转 windows 文件路径
BOOL DosPathToNtPath(LPTSTR pszDosPath, LPTSTR pszNtPath)
{
	TCHAR			szDriveStr[500];
	TCHAR			szDrive[3];
	TCHAR			szDevName[100];
	INT				cchDevName;
	INT				i;
	
	//检查参数
	if(!pszDosPath || !pszNtPath )
		return FALSE;
 
	//获取本地磁盘字符串
	if(GetLogicalDriveStrings(sizeof(szDriveStr), szDriveStr))
	{
		for(i = 0; szDriveStr[i]; i += 4)
		{
			if(!lstrcmpi(&(szDriveStr[i]), _T("A:\\")) || !lstrcmpi(&(szDriveStr[i]), _T("B:\\"))){continue;}

			szDrive[0] = szDriveStr[i];
			szDrive[1] = szDriveStr[i + 1];
			szDrive[2] = '\0';
			// 查询 Dos 设备名
			if(!QueryDosDevice(szDrive, szDevName, 100)){return FALSE;}
				
			// 命中
			cchDevName = lstrlen(szDevName);
			if(_tcsnicmp(pszDosPath, szDevName, cchDevName) == 0){
				// 复制驱动器
				lstrcpy(pszNtPath, szDrive);

				// 复制路径
				lstrcat(pszNtPath, pszDosPath + cchDevName);
 
				return TRUE;
			}			
		}
	}
 
	lstrcpy(pszNtPath, pszDosPath);
	
	return FALSE;
}

// 获取进程全路径
BOOL GetProcessFullPath(DWORD dwPID,string &fullPath){
	TCHAR		szImagePath[MAX_PATH];
	TCHAR		pszFullPath[MAX_PATH];
	HANDLE		hProcess;
	
	// 初始化失败
	if(!pszFullPath){return FALSE;}
	pszFullPath[0] = '\0';

	// 获取进程句柄失败
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, 0, dwPID);
	if(!hProcess){return FALSE;}
		
	// 获取进程完整路径失败
	if(!GetProcessImageFileName(
		hProcess,					// 进程句柄
		szImagePath,				// 接收进程所属文件全路径的指针
		MAX_PATH					// 缓冲区大小
	)){
		CloseHandle(hProcess);
		return FALSE;
	}
 
	// 路径转换失败
	if(!DosPathToNtPath(szImagePath, pszFullPath)){
		CloseHandle(hProcess);
		return FALSE;
	}
 
	CloseHandle(hProcess);
 
	// 导出文件全路径
	fullPath = pszFullPath;

	return TRUE;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);

	return 0;
}

