#include<bits/stdc++.h>
#include "testlib.h"
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;

constexpr int MAXN = 1e4 + 1018 + 1108;
constexpr int MAXP = 5e4;

int n,m,a[MAXN];
bool value[MAXN];
string s;
ll answer;

inline void ReadInfAns(){
	n = inf.readInt();
	inf.readSpace();
	m = inf.readInt();
	inf.readEoln();
	s = inf.readString();
	for(int i = 0;i < n;i++){
		value[i+1] = s[i] - '0';
	}
	for(int i = 1;i <= n;i++){
		a[i] = inf.readInt();
		inf.readSpace();
	}
	answer = ans.readLong();
	return ;
}

int p;
ll oufans;
inline void ReadOuf(){
	oufans = ouf.readLong();
	ouf.readSpace();
	p = ouf.readInt(1,INT_MAX);
	ouf.readEoln();
	if(p > MAXP){
		quitf(_wa,"Your p %d is bigger than MAXP %d",p,MAXP);
	}
	if(oufans < answer){
		quitf(_wa,"Your answer %lld is smaller than std answer %lld",answer,oufans);
	}
	if(oufans > answer){
		quitf(_wa,"Your answer %lld is bigger than std answer %lld.Check if stdans is wrong?",answer,oufans);
	}
	for(int i = 1;i <= p;i++){
		string op = ouf.readString();//这个readString会读一个换行
		if(int(op.length()) != n){
			quitf(_wa,"Your operation string length is : %d",int(op.length()));
		}
		int cnt1 = 0;
		for(int j = 0;j < n;j++){
			if(op[j] == '1'){
				value[j+1] = !value[j+1];
				cnt1++;
			}
		}
		if(cnt1 != m){
			quitf(_wa,"Your operation use \"1\" for %d times,expected %d",cnt1,m);
		}
	}
	ll realans = 0;
	for(int i = 1;i <= n;i++){
		if(value[i]){
			realans += a[i];
		}
	}
	if(realans != oufans){
		quitf(_wa,"Your real answer is %lld,but output answer %lld",realans,oufans);
	}
	return ;
}

int main(int argc, char* argv[]){
	registerTestlibCmd(argc,argv);
	ReadInfAns();
	ReadOuf();
	quitf(_ok,"Congrat!Your answer %lld is OK!",oufans);
	return not(Akano loves pure__Elysia);
}
