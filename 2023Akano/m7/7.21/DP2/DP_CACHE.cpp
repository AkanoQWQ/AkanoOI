#include<bits/stdc++.h>
using namespace std;
const int MAXT = 100;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int turn = 1;turn <= MAXT;turn++){
		system("P2497_data.exe");
		system("P2497_BF.exe");
		system("P2497.exe");
		if(system("fc P2497.out P2497.ans")){
			cout<<"WA!"<<endl;
			return 0;
		}
	}
	return 0;
}

