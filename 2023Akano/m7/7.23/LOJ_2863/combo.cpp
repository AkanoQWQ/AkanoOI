#include "combo.h"
#include <bits/stdc++.h>
using namespace std;

string guess_sequence(int n) {
	string str;
	vector<string> ch = {"A","B","X","Y"};
	if(press("AB") != 0){
		if(press("A") != 0){
			ch.erase(find(ch.begin(),ch.end(),"A"));
			str = "A";
		}else{
			ch.erase(find(ch.begin(),ch.end(),"B"));
			str = "B";
		}
	}else{
		if(press("X") != 0){
			ch.erase(find(ch.begin(),ch.end(),"X"));
			str = "X";
		}else{
			ch.erase(find(ch.begin(),ch.end(),"Y"));
			str = "Y";
		}
	}
	if(n == 1)return str;
	for(int i = 2;i < n;i++){
		int len = str.length();
		int res = press(str + ch[1] + str + ch[2] + ch[0] + str + ch[2] + ch[1] + str + ch[2] + ch[2]);
		if(res == len){
			str += ch[0];
		}else if(res == len + 1){
			str += ch[1];
		}else if(res == len + 2){
			str += ch[2];
		}
	}
	if(press(str + ch[0] + str + ch[1]) == n){
		if(press(str + ch[0]) == n){
			str += ch[0];
		}else{
			str += ch[1];
		}
	}else{
		str += ch[2];
	}
	return str;
}
