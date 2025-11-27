#include<bits/stdc++.h>
using namespace std;
const int MAXN = 22;
int scores[MAXN],t,ans_stat;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(int i = 0;i < 19;i++){
		cin>>scores[i];
	}
	for(int stat = 0;stat < (1<<19);stat++){
		for(int i = 0;i < 19;i++){
			if(!(stat & (1<<i))){
				dp[stat | (1<<i)] = max(dp[stat],dp[stat]);
			}
		}
	}
	cin>>t;
	while(t--){
		ans_stat = 0;
		for(int i = 0;i < 19;i++){
			char ch;
			cin>>ch;
			if(ch == '#')ans_stat |= (1<<i);
		}
		cout<<dp[ans_stat]<<endl;
	}
	return 0;
}
