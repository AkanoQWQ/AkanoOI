#include<bits/stdc++.h>
#include "AL/main.h"
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = (1<<30) + 1018;
const int MAXM = 32;
Interactor<4096> inter;
Rander rd;
int n,m,ans,userAns;
vector<int> to[MAXM];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	inter.CreateTwoWay("BrokenBit");
	
	//请在这里调整你的数据范围 
	n = rd(5e4,1e5),m = 20;
	
	ans = rd(1,n);
	while(true){
		string cmd;
		inter>>cmd;
		if(cmd == "Ask"){
			inter<<n<<" "<<m<<Flush;
		}else if(cmd == "Add"){
			int machine,bit;
			inter>>machine>>bit;
			to[machine].push_back(bit);
		}else if(cmd == "Query"){
			string ret;
			for(int i = 1;i <= m;i++){
				bool alive = true;
				for(auto j : to[i]){
					if(j == ans){
						alive = false;
					}
				}
				ret += char('0' + alive);
			}
			inter<<ret<<Flush;
			inter>>userAns;
			if(userAns == ans){
				cerr<<"答案正确!"<<endl;
			}else{
				cerr<<"答案错误!"<<endl;
				cerr<<"读到了 "<<userAns<<" 期望 "<<ans<<endl;
			}
			system("pause");
			return 0;
		}else{
			cerr<<"通讯错误! 读取到了\""<<cmd<<"\""<<endl;
			system("pause");
			return 0;
		}
	}
	return not(Akano loves pure__Elysia);
}
