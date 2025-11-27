#include<bits/stdc++.h>
#include "comp.h"
using namespace std;
using pivs = pair<int,vector<string> >;
const int MAXN = 6e6 + 6;
int T = 1000;
string ouf[MAXN],ans[MAXN];
string main_name; 
int main(){
	cin>>main_name>>T;
	PreCompile(main_name);
	for(int turn = 1;turn <= T;turn++){
		cout<<turn<<" CHECK"<<endl;
		long long result = Execute();
		if(result != 0){//Error
			break;
		}
		int n1 = Open(main_name + ".out",ouf);
		int n2 = Open(main_name + ".ans",ans);
		if(n1 < n2){
			cout<<"Answer too short"<<endl;continue;
		}
		if(n1 > n2){
			cout<<"Answer too long"<<endl;continue;
		}
		pivs ret = Compare(ouf,ans,min(n1,n2));
		if(ret.first != 0 || !ret.second.empty()){
			cout<<ret.first<<" WA in "<<min(n1,n2)<<endl;
			for(auto j : ret.second){
				cout<<j<<endl;
			}
			break;
		}
	}
	EXIT();
	return 0;
}
//If you are not allowed to open some files(.exe)
//check if it was'nt closed correctly
