#include<bits/stdc++.h>
#include<AL/datamaker.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
bool isSP(char ch){
	return(ch == '_' || ch == '!' || ch == '+' || ch == '-');
}
inline string GenerateString(){
	string ret = "";
	for(int i = 1;i <= 25;i++){
		ret += rd.RandChar("abcdefghijklmnopqrstuvwxyzQWERTYUIOPASDFGHJKLZCXVBNM");
	}
	for(int i = 1;i <= 5;i++){
		int pos = rd(0,24);
		while(isSP(ret[pos]) || pos == 2 || pos == 9)pos = rd(0,24);
		ret[pos] = rd.RandChar("_!+-");
	}
	int pos3 = rd(0,7),pos10 = 7 - pos3;
	ret[2] = '0' + pos3,ret[9] = '0' + pos10;
	int poss = rd(1,100);
	if(poss <= 30){//长度不对
		ret += 'a';
	}else if(poss <= 45){//特殊字符少
		int pos = rd(0,24);
		while(isSP(ret[pos]) == false)pos= rd(0,24);
		ret[pos] = rd.RandChar("abcde");
	}else if(poss <= 60){//特殊字符多
		int pos = rd(0,24);
		while(isSP(ret[pos]) || pos == 2 || pos == 9)pos = rd(0,24);
		ret[pos] = rd.RandChar("_!+-");
	}else if(poss <= 80){//不是数字
		ret[2] = 'a';
	}else{
		ret[2] = ('9' - ret[9] + '0');
	}
	return "flag{" + ret + "}";
}
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 1;i <= 1018 + 1108 - 1;i++){
		cout<<GenerateString()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
/*
1.	flag内25位
2.	正好拥有5个特殊字符_!+-
3.	第三位和第十位是数字，并且和为7
flag{aK4n0-L0v3s-puR3__ELys1A!}
*/
