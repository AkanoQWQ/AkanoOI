#include<bits/stdc++.h>
#include<windows.h>
#include<tlhelp32.h>
using namespace std;
string GetProcessInfo(HANDLE hProcess,char* processName)
{
	PROCESSENTRY32* pinfo = new PROCESSENTRY32; //进程信息 （pinfo->dwSize = sizeof(PROCESSENTRY32);）
	MODULEENTRY32* minfo = new MODULEENTRY32; //模块信息 （minfo->dwSize = sizeof(MODULEENTRY32);）
    char shortpath[MAX_PATH];				//保存路径变量

	int flag = Process32First(hProcess,pinfo);	// 从第一个进程开始
    while(flag){
		// 如果是 QQMusic.exe 这个进程
		if(strcmp(pinfo->szExeFile, processName) == 0){

			// 创建进程快照
			HANDLE hModule = CreateToolhelp32Snapshot(
				TH32CS_SNAPMODULE,		//（DWORD） 快照返回的对象，TH32CS_SNAPMODULE 是指 "特定进程的使用模块的列表"
				pinfo->th32ProcessID	//（DWORD） 要获取快照进程的PID，当前进程/系统列表 快照时设为0
				); 

			// 把第一个模块信息给 minfo
			Module32First(
				hModule,  //（HANDLE） CreateToolhelp32Snapshot 的返回句柄
				minfo	 // （LPMODULEENTRY32）  接收模块信息
				);    

			// 把文件路径给 shortpath
			GetShortPathName(
				minfo->szExePath,	//  文件路径（但最好不要用这个，因为这个碰到中文会出现乱码）
				shortpath,		// 用来接收 minfo->szExePath 兼容中文的值
				256			// 缓冲区大小
				); 

			return shortpath;
		}
		// 下一个进程
		flag = Process32Next(hProcess, pinfo);
    }

	return NULL;
}

int main()
{
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0); // 创建进程快照
	PROCESSENTRY32 process = {sizeof(PROCESSENTRY32)};	// 用来接收 hProcessSnap 的信息
	
	// 遍历进程快照
	while (Process32Next(hProcessSnap,&process)){
		// 找到 QQMusic.exe 进程
		string processName = process.szExeFile; // char* 转 string
		if(processName == "csrss.exe")continue;
		if(processName == "svchost.exe")continue;
		if(processName == "ShowBuffer.exe")continue;
		if(processName == "armsvc.exe")continue;
		if(processName == "mDNSResponder.exe")continue;
		if(processName == "Nmdeputy.exe")continue;
		if(processName == "srvany.exe")continue;
		if(processName == "PsiService_2.exe")continue;
		if(processName == "QQProtect.exe")continue;
		if(processName == "vmnetdhcp.exe")continue;
		if(processName == "Yistart.exe")continue;
		if(processName == "vmnat.exe")continue;
		if(processName == "vmware-authd.exe")continue;
		if(processName == "vmware-usbarbitrator64.exe")continue;
		if(processName == "SearchIndexer.exe")continue;
		if(processName == "PresentationFontCache.exe")continue;
		if(processName == "igfxHK.exe")continue;
		if(processName == "igfxEM.exe")continue;
		if(processName == "DesktopService64.exe")continue;
		if(processName == "SogouCloud.exe")continue;
		if(processName == "explorer.exe")continue;
		if(processName == "DesktopMgr64.exe")continue;
		if(processName == "cenaclnt.exe")continue;
		if(processName == "360bdoctor.exe")continue;
		if(processName == "msedge.exe")continue;
		if(processName == "taskhost.exe")continue;
		if(processName == "devcpp.exe")continue;
		cout<<processName<<endl;
		//string s_exePath = GetProcessInfo(hProcessSnap,"processName.exe"); // 进程的全路径 
		
		string s_exePath = GetProcessInfo(hProcessSnap,const_cast<char *>(processName.c_str()));
		cout << s_exePath << endl;
		continue;
	}
	
	return 0;
}
