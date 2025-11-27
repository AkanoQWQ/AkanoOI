#include<bits/stdc++.h>
#include "testlib.h"
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXM = 32;
int n,m,answer,userAns;
vector<int> to[MAXM];
int main(int argc, char* argv[]){
	registerInteraction(argc, argv);
	n = inf.readInt(),m = inf.readInt();
	answer = rnd.next(1,n);
	while(true){
		string cmd = "unread";
		cmd = ouf.readString();
		if(cmd == "Ask"){
			cout<<n<<" "<<m<<endl;
		}else if(cmd == "Add"){
			int machine = ouf.readInt(1,m);
			ouf.readSpace();
			int bit = ouf.readInt(1,n);
			ouf.readEoln();
			to[machine].push_back(bit);
		}else if(cmd == "Query"){
			string ret;
			for(int i = 1;i <= m;i++){
				bool alive = true;
				for(auto j : to[i]){
					if(j == answer){
						alive = false;
					}
				}
				ret += char('0' + alive);
			}
			cout<<ret<<endl;
			userAns = ouf.readInt(1,n);
			if(userAns == answer){
				quitf(_ok,"answer is %d",answer);
			}else{
				quitf(_wa,"read %d expected %d",userAns,answer);
			}
			return 0;
		}else{
			quitf(_wa,"wrong command,unexpected \"%s\"",cmd.c_str());
			return 0;
		}
	}
	return not(Akano loves pure__Elysia);
}
