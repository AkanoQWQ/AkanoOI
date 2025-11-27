#include<bits/stdc++.h>
#include "DP_FILE/comp.h"
using namespace std;
using psi = pair<string,int>;
queue<psi> q;
unordered_map<string,bool> vis;
string str;
inline bool Judge(const string& str){
	const int len = str.length();
	for(int i = 0;len - i -1 > i;i++){
		if(str[i] != str[len-i-1])return false;
	}
	return true;
}
inline string rds(int mxlen){
	string ret;
	mt19937 rng(GetTime());
	while(int(ret.length()) <= mxlen-1){
		char ch = 'a' + (rand()%26);
		ret += ch,ret += ch;
	}
	if(int(ret.length()) != mxlen)ret += 'a' + (rand()%26);
	shuffle(ret.begin(),ret.end(),rng);
	return ret;
}
int minstep = -1;
int main(){
	srand(GetTime());
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	//cin>>str;
	str = rds(8);
	cout<<str<<endl;
	q.push(make_pair(str,0));
	vis[str] = true;
	bool FD = false;
	while(!q.empty()){
		if(FD)break;
		const string u = q.front().first;
		const int step = q.front().second;
		q.pop();
		for(int i = 0;i < int(u.length())-1;i++){
			string v = u;
			swap(v[i],v[i+1]);
			if(!vis[v]){
				vis[v] = true;
				if(Judge(v)){
					minstep = step + 1;
					FD = true;
					cout<<v<<endl;
					break;
				}
				q.push(make_pair(v,step+1));
			}
		}
	}
	cout<<"ACT "<<minstep<<endl;
	return 0;
}
