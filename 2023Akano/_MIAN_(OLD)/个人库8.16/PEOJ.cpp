//PE Offline Judge Version 2023.8.16
//BASE ON AL ver2023.8.16
//需要AL ver2023.8.15及以上 
#include<bits/stdc++.h>
#include<io.h>
#include<AL/comp.h>//需要使用install.cmd安装AL 
using namespace std;
const int MAX_TIME = 1000;//时限默认1000,单位ms 
const int MAX_SCORE = 100;//最大分数,默认100pts 
string main_name;
int t;
const int TOT_BLK = 20;//方块总数 
inline void ShowBlock(int now,int up){
	int blk = TOT_BLK * now / up;
	SetColor("lightgreen");
	for(int i = 1;i <= blk;i++){
		cout<<"█";
	}
	SetColor("red");
	for(int i = blk+1;i <= TOT_BLK;i++){
		cout<<"█";
	}
	cout<<endl;
	return ;
}
vector<pair<string,int> > waiting;
int main(){
	if(_access("config.txt",00) == 0){
		
		IO::Open("config.txt");
	}
	while(cin>>main_name>>t){
		waiting.push_back(make_pair(main_name,t));
	}
	for(auto now : waiting){
		main_name = now.first,t = now.second;
		JudgeResult result = Judge(main_name,1,t,MAX_TIME);
		int score = result.ac * MAX_SCORE / result.Sum();
		if(score == MAX_SCORE){
			SetColor("lightgreen");
		}else{
			SetColor("lightred");
		}
		cout<<"SCORE : "<<score<<"pts / "<<MAX_SCORE<<"pts"<<endl;
		ShowBlock(score,MAX_SCORE);
		if(result.ac){
			SetColor("lightgreen");
			cout<<"AC : "<<result.ac<<" / "<<result.Sum()<<endl;
		}
		if(result.wa){
			SetColor("lightred");
			cout<<"WA : "<<result.wa<<" / "<<result.Sum()<<endl;
		}
		if(result.tle){
			SetColor("lightpurple");
			cout<<"TLE : "<<result.tle<<" / "<<result.Sum()<<endl;
		}
		SetColor("lightwhite");
		for(auto i : result.returnList){
			cout<<i<<endl;
		}
	}
	Error::OutputFile("PEOJ_err");
	return 0;
}
