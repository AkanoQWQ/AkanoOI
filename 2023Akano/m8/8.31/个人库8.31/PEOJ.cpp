//PE Offline Judge Version 2023.8.19
//BASE ON AL ver2023.8.19
//需要AL ver2023.8.18及以上 
#include<bits/stdc++.h>
#include<windows.h>
#include<io.h>
#include<AL/comp.h>//需要使用install.cmd安装AL 
using namespace std;
const int MAX_TIME = 1000;//时限默认1000,单位ms 
const int MAX_SCORE = 100;//最大分数,默认100pts 
const int TOT_BLK = 20;//方块总数 
inline void ShowBlock(int now,int up){
	int blk = TOT_BLK * now / up;
	SetColor("lightgreen");
	for(int i = 1;i <= blk;i++){
		cout<<"▇"; 
	}
	SetColor("red");
	for(int i = blk+1;i <= TOT_BLK;i++){
		cout<<"▇";
	}
	cout<<endl;
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
	SetConsoleTitle("PE Offline Judue ~Akano的本地评测系统~");
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
		SetColor("white");
		cout<<"当前评测 : "<<now.name<<endl;
		JudgeResult result = Judge(now.name,1,now.maxTurn,now.maxTime);
		int score = result.ac * now.maxScore / result.Sum();
		if(score == now.maxScore){
			SetColor("lightgreen");
		}else{
			SetColor("lightred");
		}
		cout<<"SCORE : "<<score<<"pts / "<<now.maxScore<<"pts"<<endl;
		ShowBlock(score,now.maxScore);
		string nowStat = "AC";
		if(result.ac){
			SetColor("lightgreen");
			cout<<"AC : "<<result.ac<<" / "<<result.Sum()<<endl;
		}
		if(result.wa){
			SetColor("lightred");
			cout<<"WA : "<<result.wa<<" / "<<result.Sum()<<endl;
			nowStat = "WA";
		}
		if(result.tle){
			SetColor("lightpurple");
			cout<<"TLE : "<<result.tle<<" / "<<result.Sum()<<endl;
			if(nowStat != "WA")nowStat = "TLE";//WA > TLE
		}
		if(result.ce){
			SetColor("lightyellow");
			cout<<"CE : "<<result.ce<<" / "<<result.Sum()<<endl;
			nowStat = "CE";//CE > ALL
		}
		if(result.re){
			SetColor("gray");
			cout<<"RE : "<<result.re<<" / "<<result.Sum()<<endl;
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
		SetColor("lightwhite");
		for(auto i : result.returnList){
			cout<<i<<endl;
		}
		BR();
	}
	totSUM = totAC + totWA + totTLE + totCE + totRE;
	SetColor("white");
	cout<<"在总共 "<<totSUM<<" 道题目中"<<endl;
	if(totAC){
		SetColor("lightgreen");
		cout<<totAC<<" 道题目AC"<<endl; 
	}
	if(totWA){
		SetColor("lightred");
		cout<<totWA<<" 道题目WA"<<endl; 
	}
	if(totTLE){
		SetColor("lightpurple");
		cout<<totTLE<<" 道题目TLE"<<endl; 
	}
	if(totCE){
		SetColor("lightyellow");
		cout<<totCE<<" 道题目CE"<<endl; 
	}
	if(totRE){
		SetColor("gray");
		cout<<totRE<<" 道题目RE"<<endl; 
	}
	if(totScore == totMaxScore){
		SetColor("lightgreen");
	}else{
		SetColor("lightred");
	}
	cout<<"总得分 : "<<totScore<<" / "<<totMaxScore<<endl;
	SetColor("white");
	Error::OutputFile("PEOJ_err");
	cout<<endl;
	IO::Open("CON");
	cout<<"按下任意键退出评测"<<endl;
	getchar();
	return 0;
}
