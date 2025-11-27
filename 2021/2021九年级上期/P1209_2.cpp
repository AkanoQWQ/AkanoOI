#include<bits/stdc++.h>
using namespace std;
int t,n,m,v[106][106],i,j,timee,couldget,hmoney;
bool choices[106];
void choose(int money,int getmoney){
	if(money < 0)return ;
	for(int i = 1;i <= n;i++){
		if(choices[i] == 0 && v[timee+1][i] > v[timee][i]){
			//choices[i] = 1;
			choose(money - v[timee][i],getmoney + v[timee+1][i] - v[timee][i]);
			//choices[i] = 0;
		}
	}
	couldget = max(couldget,getmoney);
}
int main(){
	freopen("P1209.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t>>n>>m;
	for(i = 1;i <= t;i++){
		for(j = 1;j <= n;j++){
			cin>>v[i][j];
		} 
	}
	hmoney = m;
	for(timee = 1;timee <= t;timee++){
		couldget = 0;
		memset(choices,0,sizeof(choices));
		choose(hmoney,0);
		if(couldget > 0)hmoney += couldget;
	}
	cout<<hmoney;
	return 0;
}
