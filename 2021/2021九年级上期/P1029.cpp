#include<bits/stdc++.h>
using namespace std;
int t,n,m,v[106][106],i,j,timee,couldget,money;
bool choices[106];
void choose(int money,int getmoney){
	if(money <= 0 || getmoney <= 0)return ;
	for(int i = 1;i <= 100;i++){
		if(choices[i] == 0 && v[timee][i+1] > v[timee][i]){
			//choices[i] = 1;
			choose(money - v[timee][i],getmoney + v[timee][i+1] - - v[timee][i]);
			//choices[i] = 0;
		}
	}
	couldget = max(couldget,getmoney);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t>>n>>m;
	for(i = 1;i <= t;i++){
		for(j = 1;j <= n;j++){
			cin>>v[i][j];
		} 
	}
	money = m;
	for(timee = 1;timee <= t;timee++){
		memset(choices,0,sizeof(choices));
		choose(money,0);
		if(couldget > 0)money += couldget;
	}
	cout<<money;
	return 0;
}

