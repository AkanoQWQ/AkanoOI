#include<bits/stdc++.h>
#include<windows.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const string name = "test";
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<"find "<<name<<endl; 
	HWND hwnd = FindWindow(NULL,name.c_str());
	DWORD pid;
	GetWindowThreadProcessId(hwnd,&pid);
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	cout<<hwnd<<","<<pid<<","<<hProcess<<endl;
	SetStdHandle(STD_OUTPUT_HANDLE,hProcess);
	return not(Akano loves pure__Elysia);
}
