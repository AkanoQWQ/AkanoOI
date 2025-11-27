#include<bits/stdc++.h>
#include "AL/main.h"
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Interactor<4096> inter;
int n,m,ans;
string str;
inline void Ask(){//执行 Ask 操作 
	inter<<"Ask"<<Flush;
	inter>>n>>m;
	return ;
}
inline void Add(int u,int v){//执行 Add 操作 
	inter<<"Add "<<u<<" "<<v<<Flush;
	return ;
}
inline void Query(){//执行 Query 操作 
	inter<<"Query"<<Flush;
	inter>>str;
	
	ans = 10181108;//在这里通过str计算你的答案 
	
	inter<<ans<<Flush;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	inter.ConnectTwoWay("BrokenBit");
	//请在一开始执行Ask语句 
	//Ask();
	
	//你的Add操作在这里执行
	//操作仅供参考，不符合逻辑 
	for(int i = 1;i <= m;i++)Add(1,1);
	
	//请在最后执行 Query 语句 
	//Query();
	return not(Akano loves pure__Elysia);
}
