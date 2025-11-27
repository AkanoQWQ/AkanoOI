#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool> vis;
bool fd;
string obj;
void se(string s,int dep){
	if(fd)return ;
	if(s == obj){
		fd = 1;
		return ;
	}
	if(dep > 12)return ;
	if(vis[s])return ;
	vis[s] = 1;
	for(int i = 0;i < s.length();i++){
		string rt = "";
		for(int j = 0;j < i;j++)rt += s[j];
		if(s[i] == 'A')rt += "BC";
		if(s[i] == 'B')rt += "AC";
		if(s[i] == 'C')rt += "AB";
		for(int j = i+1;j < s.length();j++)rt += s[j];
		se(rt,dep+1);
	}
	for(int i = 0;i+2 < s.length();i++){
		if(s[i] == 'A' && s[i+1] == 'A' && s[i+2] == 'A'){
			string rt = "";
			for(int j = 0;j < i;j++)rt += s[j];
			for(int j = i+3;j < s.length();j++)rt += s[j];
			se(rt,dep+1);
		}
	}
	return ;
}
string sa,sb;
int q;
int main(){
//	freopen("always.in","r",stdin);
	cin>>sa>>sb>>q;
	while(q--){
		vis.clear();
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--;
		b--;
		c--;
		d--;
		string now = "";
		obj = "";
		fd = 0;
		for(int i = a;i <= b;i++){
			now += sa[i];
		}
		for(int i = c;i <= d;i++){
			obj += sb[i];
		}
		se(now,1);
		if(fd){
			putchar('1');
		}else{
			putchar('0');
		}
	}
	return 0;
}
