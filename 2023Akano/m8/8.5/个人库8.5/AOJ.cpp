//Akano Offline Judge Version 2023.8.6
//BASIC ON AL ver2023.8.5
//ADAPT TO AL ver2023.8.6
#include<bits/stdc++.h>
#include "AL/comp.h"
using namespace std;
using pivs = pair<int,vector<string> >;
const int ArraySize = 6e6 + 6;//注意比较数组的大小,应该和答案输出的元素个数一致 
int T = 1000;
string ouf[ArraySize],ans[ArraySize];//默认使用string 
string main_name;
bool KEEP_FILE = false;
int main(){
	cin>>main_name>>T;
	PreCompile(main_name);
	for(int turn = 1;turn <= T;turn++){
		cout<<turn<<" CHECK"<<'\n';
		long long result = Run();
		if(result != 0){//Error
			KEEP_FILE = true;
			break;
		}
		int n1 = FileIntoArray(pre_file + out_name,ouf);
		int n2 = FileIntoArray(pre_file + ans_name,ans);
		if(n1 < n2){
			KEEP_FILE = true;
			cout<<"Answer too short"<<'\n';break;
		}
		if(n1 > n2){
			KEEP_FILE = true;
			cout<<"Answer too long"<<'\n';break;
		}
		pivs ret = Compare(ouf,ans,min(n1,n2));
		if(ret.first != 0 || !ret.second.empty()){
			KEEP_FILE = true;
			cout<<ret.first<<" WA in "<<min(n1,n2)<<endl;
			for(auto warn : ret.second){
				cout<<warn<<'\n';
			}
			break;
		}
	}
	if(KEEP_FILE == false)Delete();
	return 0;
}
//可能的BUG
//1.cmd提示你无法正确打开某个exe
//在任务管理器中检查该exe是否正常关闭,是否有一个不明所以的cmd.exe
//发现以上异常,结束对应进程 
//2.__MAIN__文件没有正常删除
//在任务管理器中检查code.exe , std.exe , data.exe 是否正常关闭,是否有一个不明所以的cmd.exe
//发现以上异常,结束对应进程 
