//PE Offline Judge Version 2023.11.12
//BASE ON AL ver 2023.11.12
//至少需要AL ver2023.9.25及以上
//推荐AL ver2023.10.3 补泉了颜色,使用旧版本会有颜色缺失
#include<bits/stdc++.h>
#include<windows.h>
#include<io.h>
#include "AL/main.h"//优先使用本目录下的AL
using namespace std;
const int MAX_TIME = 1000;//时限默认1000,单位ms 
const int MAX_SCORE = 100;//最大分数,默认100pts 
const int TOT_BLK = 20;//方块总数 
inline void ShowBlock(int now,int up){
	int blk = TOT_BLK * now / up;
	for(int i = 1;i <= blk;i++){
		kout<<"[green]▇[/green]"; 
	}
	for(int i = blk+1;i <= TOT_BLK;i++){
		kout<<"[red]▇[/red]";
	}
	kout<<kend;
	return ;
}
struct WaitingList{
	string name;
	int maxTurn,maxScore,maxTime;
	WaitingList(){}
	WaitingList(string _name,int _t,int _mx,int _mt){
		name = _name,maxTurn = _t,maxScore = _mx,maxTime = _mt;
	}
};
vector<WaitingList> waiting;
int totAC,totWA,totTLE,totCE,totRE,totSUM,totScore,totMaxScore;
int main(){
#ifdef __ALver
	string _console_title = "PE Offline Judge ~Akano的本地评测系统~  based on AL ver." + to_string(__ALver);
	SetConsoleTitle(_console_title.c_str());
#else
	SetConsoleTitle("PE Offline Judge ~Akano的本地评测系统~");
#endif
	Error::outputName = "PEOJ";//设置ERR流的默认名字
	SetErrorMode(SEM_NOGPFAULTERRORBOX);//不显示错误对话框,否则RE识别为TLE且有弹窗 
	SetFontConsolas(20);
	SetDefaultGCC();
	if(_access("setting.txt",00) == 0){
		string command;
		while(cin>>command){
			if(command == "SetGCC"){
				string gccname;
				cin>>gccname;
				SetGCC("\"" + gccname + "\"");
			}else{
				Error::PE("PEOJ.cpp","未识别的 PEOJ 命令 : "+command);
			}
		}
	} 
	if(CheckGCC() == false){
		cout<<"GCC没有找到默认路径!请手动输入GCC路径(./.../g++.exe):"<<endl;
		string path = "DEF";
		do{
			if(path != "DEF")cout<<"GCC路径错误!请重新输入:"<<endl;
			getline(cin,path);
			SetGCC("\"" + path + "\"");
		}while(CheckGCC() == false);
	}
	if(_access("config.txt",00) == 0){
		cout<<"现在是文件读入,由文件输入以下题目:"<<endl;
		IO::Open("config.txt");
		WaitingList nowList;
		while(cin>>nowList.name>>nowList.maxTurn>>nowList.maxTime>>nowList.maxScore){
			cout<<"题目 : "<<nowList.name<<" ; 数据点数 : "<<nowList.maxTurn<<" ; ";
			cout<<"时限 : "<<nowList.maxTime<<" ; 最大分数 : "<<nowList.maxScore<<endl;
			waiting.push_back(nowList);
		}
	}else{
		cout<<"现在是快捷模式,输入名字和评测次数,默认时限 : "<<MAX_TIME<<" ; 默认最大分数 : "<<MAX_SCORE<<endl;
		WaitingList nowList;
		cin>>nowList.name>>nowList.maxTurn;
		nowList.maxTime = MAX_TIME,nowList.maxScore = MAX_SCORE;
		waiting.push_back(nowList);
	}
	
	for(auto now : waiting){
		kout<<"[white]当前评测 : "<<now.name<<"[/white]"<<kend;
		JudgeResult result = Judge(now.name,1,now.maxTurn,now.maxTime);
		int score = result.ac * now.maxScore / result.Sum();
		if(score == now.maxScore){
			kout<<"[green]SCORE : "<<score<<"pts / "<<now.maxScore<<"pts[/green]"<<kend;
		}else{
			kout<<"[red]SCORE : "<<score<<"pts / "<<now.maxScore<<"pts[/red]"<<kend;
		}
		
		ShowBlock(score,now.maxScore);
		
		string nowStat = "AC";
		if(result.ac){
			kout<<"[green]AC : "<<result.ac<<" / "<<result.Sum()<<"[/green]"<<kend;
		}
		if(result.wa){
			kout<<"[red]WA : "<<result.wa<<" / "<<result.Sum()<<"[/red]"<<kend;
			nowStat = "WA";
		}
		if(result.tle){
			kout<<"[purple]TLE : "<<result.tle<<" / "<<result.Sum()<<"[/purple]"<<kend;
			if(nowStat != "WA")nowStat = "TLE";//WA > TLE
		}
		if(result.ce){
			kout<<"[yellow]CE : "<<result.ce<<" / "<<result.Sum()<<"[/yellow]"<<kend;
			nowStat = "CE";//CE > ALL
		}
		if(result.re){
			kout<<"[/gray]RE : "<<result.re<<" / "<<result.Sum()<<"[/gray]"<<kend;
			nowStat = "RE";//RE > WA
		}
		if(nowStat == "AC"){
			totAC++;
		}else if(nowStat == "WA"){
			totWA++;
		}else if(nowStat == "TLE"){
			totTLE++;
		}else if(nowStat == "CE"){
			totCE++;
		}else if(nowStat == "RE"){
			totRE++;
		}
		totMaxScore += now.maxScore,totScore += score;
		for(auto i : result.returnList){
			kout<<"[lightwhite]"<<i<<"[/lightwhite]"<<kend;
		}
		BR();
	}
	
	totSUM = totAC + totWA + totTLE + totCE + totRE;
	kout<<"[white]在总共 "<<totSUM<<" 道题目中[/white]"<<kend;
	if(totAC)kout<<"[green]"<<totAC<<" 道题目AC[/green]"<<kend; 
	if(totWA)kout<<"[red]"<<totWA<<" 道题目WA[/red]"<<kend; 
	if(totTLE)kout<<"[purple]"<<totTLE<<" 道题目TLE[/purple]"<<kend; 
	if(totCE)kout<<"[yellow]"<<totCE<<" 道题目CE[/yellow]"<<kend; 
	if(totRE)kout<<"[gray]"<<totRE<<" 道题目RE[/gray]"<<kend;
	
	if(totScore == totMaxScore){
		kout<<"[green]总得分 : "<<totScore<<" / "<<totMaxScore<<"[/green]"<<kend;
	}else{
		kout<<"[red]总得分 : "<<totScore<<" / "<<totMaxScore<<"[/red]"<<kend;
	}
	//Error::OutputFile("PEOJ_err");//旧版本需要手动输出
	IO::Open("CON");
	kout<<"[white]按下任意键退出评测[/white]"<<kend;
	getchar();
	return 0;
}
