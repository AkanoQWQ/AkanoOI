#include<bits/stdc++.h>
#include<AL/main.h>
using namespace std;
unsigned int rin;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<DePath(".\\run.exe")<<endl; 
	WinExec(".\\run.exe",0);
	Sleep(1000);
	system("taskkill /f /im run.exe");
	return 0;
}
