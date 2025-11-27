//PE Offline Judge Version 2023.8.12
//BASIC ON AL ver2023.8.12
#include<bits/stdc++.h>
#include<AL/comp.h>//需要使用install.cmd安装AL 
using namespace std;
const int MAX_TIME = 1000;//时限默认1000,单位ms 
const int MAX_SCORE = 100;//最大分数,默认100pts 
string main_name;
int t;
int main(){
	cin>>main_name>>t;
	JudgeResult result = Judge(main_name,1,t,MAX_TIME);
	int score = result.ac * MAX_SCORE / result.Sum();
	cout<<"SCORE : "<<score<<"pts / "<<MAX_SCORE<<"pts"<<endl;
	if(result.ac)cout<<"AC : "<<result.ac<<" / "<<result.Sum()<<endl;
	if(result.wa)cout<<"WA : "<<result.wa<<" / "<<result.Sum()<<endl;
	if(result.tle)cout<<"TLE : "<<result.tle<<" / "<<result.Sum()<<endl;
	for(auto i : result.returnList){
		cout<<i<<endl;
	}
	return 0;
}
