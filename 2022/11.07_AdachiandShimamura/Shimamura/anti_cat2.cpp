#include<bits/stdc++.h>
#include<windows.h>
#include<tlhelp32.h>
#include<psapi.h>
using namespace std;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0); // 创建进程快照
	PROCESSENTRY32 process = {sizeof(PROCESSENTRY32)};	// 用来接收 hProcessSnap 的信息
	
	// 遍历进程快照
	while (Process32Next(hProcessSnap,&process)){
		// 获取进程名
		string processName = process.szExeFile;
		cout << processName << endl;
		
		// 获取全路径
		char chpath[MAX_PATH];
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process.th32ProcessID);
		GetModuleFileNameEx(hProcess,NULL,chpath,sizeof(chpath));
		cout << chpath << endl;
		
		cout << "-------------------" << endl;
	}

	return 0;
}

