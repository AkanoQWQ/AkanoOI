#include<bits/stdc++.h>
using namespace std;
unordered_map<string,vector<string> > mp;
unordered_map<string,bool> vis;
void se(string s,int dep){
	if(dep > 6)return ;
	if(vis[s])return ;
	vis[s] = 1;
	for(int i = 0;i < s.length();i++){
		string rt = "";
		for(int j = 0;j < i;j++){
			rt += s[j];
		}
		if(s[i] == 'A'){
			rt += "BC";
		}
		if(s[i] == 'B'){
			rt += "AC";
		}
		if(s[i] == 'C'){
			rt += "AB";
		}
		for(int j = i+1;j < s.length();j++){
			rt += s[j];
		}
		mp[s].push_back(rt);
		se(rt,dep+1);
		for(int j = 0;j < mp[rt].size();j++){
			mp[s].push_back(mp[rt][j]);
		}
	}
	for(int i = 0;i+2 < s.length();i++){
		if(s[i] == 'A' && s[i+1] == 'A' && s[i+2] == 'A'){
			string rt = "";
			for(int j = 0;j < i;j++){
				rt += s[j];
			}
			for(int j = i+3;j < s.length();j++){
				rt += s[j];
			}
			mp[s].push_back(rt);
			cout<<s<<" -> "<<rt<<endl;
		}
	}
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	freopen("aw.out","w",stdout);
	se("A",1);
	for(int i = 0;i < mp["A"].size();i++){
		cout<<mp["A"][i]<<endl;
	}
	return 0;
}
