//PE Offline Judge Version 2023.10.16
//BASE ON AL ver2023.10.3
//使用了最新的ALege库,目前放在目录下编译(方便调试)
#include<bits/stdc++.h>
#include<windows.h>
#include<io.h>
#include<AL/comp.h>//需要使用install.cmd安装AL
#include<AL/colorout.h>
#include<graphics.h>
#include "ALege/UI.h"
using namespace std;
using Pos = Position;
const int screenX = 800;
const int screenY = 640;
const int MAX_TIME = 1000;//时限默认1000,单位ms 
const int MAX_SCORE = 100;//最大分数,默认100pts 
const int TOT_BLK = 20;//方块总数 
inline void ShowBlock(int now,int up){
	aerr<<"未完成的部分,目前仍然在控制台输出"<<enderr;
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
inline void CLS(){
	setcolor(RGB(255,255,255));
	setfillcolor(RGB(255,255,255));
	bar(0,0,screenX,screenY);
	return ;
}
inline void ShowEvent(){//画图线程的事件,所有画图工作应当在里面完成!
	for(;is_run();delay_fps(30)){//PEOJ不需要60fps吧......
		CLS();
		UIExecute();
	}
	return ;
}
int main(){
	initgraph(screenX,screenY);
	SetConsoleTitle("PEOJ 后台");
	setcaption("PE Offline Judge ~Akano的本地评测系统~");
	thread showThread(ShowEvent);
	showThread.detach();
	Error::outputName = "PEOJ";//设置ERR流的默认名字
	SetErrorMode(SEM_NOGPFAULTERRORBOX);//不显示错误对话框,否则RE识别为TLE且有弹窗 
	SetDefaultGCC();
	if(_access("setting.txt",00) == 0){
		ifstream fin("setting.txt");
		string command;
		while(fin>>command){
			if(command == "SetGCC"){
				string gccname;
				fin>>gccname;
				SetGCC("\"" + gccname + "\"");
			}else{
				Error::PE("PEOJ.cpp","未识别的 PEOJ 命令 : "+command);
			}
		}
	} 
	if(CheckGCC() == false){
		string path = "DEF";
		const int BUFFSIZE = 1024;
		char buff[BUFFSIZE];
		do{
			if(path != "DEF")cout<<"GCC路径错误!:"<<endl;
			inputbox_getline("GCC路径错误!","请输入GCC路径:",buff,BUFFSIZE);
			path = buff;
			SetGCC("\"" + path + "\"");
		}while(CheckGCC() == false);
	}
	if(_access("config.txt",00) == 0){
		cout<<"读取到文件config.txt,文件输入以下题目:"<<endl;
		ifstream fin("config.txt");
		WaitingList nowList;
		while(fin>>nowList.name>>nowList.maxTurn>>nowList.maxTime>>nowList.maxScore){
			cout<<"题目 : "<<nowList.name<<" ; 数据点数 : "<<nowList.maxTurn<<" ; ";
			cout<<"时限 : "<<nowList.maxTime<<" ; 最大分数 : "<<nowList.maxScore<<endl;
			waiting.push_back(nowList);
		}
	}else{
		UIptr showinfo(new Text(Pos(5,5)));
		showinfo.Textr()<<"现在是快捷模式,输入名字和评测次数,默认时限 : "<<MAX_TIME<<" ; 默认最大分数 : "<<MAX_SCORE;
		WaitingList nowList;
		cin>>nowList.name>>nowList.maxTurn;
		nowList.maxTime = MAX_TIME,nowList.maxScore = MAX_SCORE;
		waiting.push_back(nowList);
	}
	for(auto now : waiting){
		const int spaceY = 15;
		int nowY = 5;
		vector<UIptr> infos;
		infos.emplace_back(new Text(Pos(5,nowY += spaceY)));
		infos.emplace_back(new Text(Pos(5,nowY += spaceY)));
		infos[0].Textr()<<"当前评测 : "<<now.name<<'\n';
		JudgeResult result = Judge(now.name,1,now.maxTurn,now.maxTime);
		int score = result.ac * now.maxScore / result.Sum();
		if(score == now.maxScore){
//			infos[1].Textr()<<"SCORE : "<<score<<"pts / "<<now.maxScore<<"pts";
		}else{
//			infos[1].Textr()<<"SCORE : "<<score<<"pts / "<<now.maxScore<<"pts";
		}
		ShowBlock(score,now.maxScore);
		string nowStat = "AC";
		if(result.ac){
			infos.emplace_back(new Text(Pos(5,nowY += spaceY)));
//			infos.back().Textr()<<"AC : "<<result.ac<<" / "<<result.Sum();
		}
		if(result.wa){
			infos.emplace_back(new Text(Pos(5,nowY += spaceY)));
//			infos.back().Textr()<<"WA : "<<result.wa<<" / "<<result.Sum();
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
