#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1018 + 1108; 
int n,a,b,d[MAXN];
vector<pair<int,int> > e;
int fa[MAXN];
int Find(int x){
	if(fa[x] == x)return x;
	return fa[x] = Find(fa[x]);
}
inline bool CheckTree(){
	for(int u = 1;u <= n;u++){
		fa[u] = u;
	}
	for(auto i : e){
		int x = Find(i.first),y = Find(i.second);
		if(x == y)return false;
		fa[x] = y;
	}
	return true;
}
int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	a = inf.readInt(),b = inf.readInt();
	n = ouf.readInt(0,1999);
	int stdans = ans.readInt();
	if(stdans == 0){
		if(n == 0){
			quitf(_ok,"正确的空树!");
		}else{
			quitf(_wa,"无解,但是你认为有解!");
		}
	}
	for(int i = 1;i < n;i++){
		int u = ouf.readInt(1,n),v = ouf.readInt(1,n);
		if(u == v){
			quitf(_wa,"你有一条边 u = v : %d = %d",u,v);
		}
		e.emplace_back(u,v);
		d[u]++,d[v]++;
	}
	if(CheckTree() == false){
		quitf(_wa,"你输入的不是树!");
	}
	for(int i = 1;i <= n;i++){
		if(d[i] == 1)a--;
		if(d[i] == 3)b--;
	}
	if(a < 0){
		quitf(_wa,"你的1度点多了 %d",-a);
	}
	if(a > 0){
		quitf(_wa,"你的1度点少了 %d",a);
	}
	if(b < 0){
		quitf(_wa,"你的1度点多了 %d",-b);
	}
	if(b > 0){
		quitf(_wa,"你的1度点少了 %d",b);
	}
	quitf(_ok,"答案正确!");
}
