#include<bits/stdc++.h>
using namespace std;
const int MAXU = 2e6 + 6;
const int MAXN = 2e5 + 6;
int tr[MAXU][26],fail[MAXU],from[MAXU],ans[MAXN],val[MAXN],n,tot;
vector<int> tag[MAXU];
string s,t;
inline void Insert(const string& str,int no){
	int u = 0,len = str.length();
	for(int i = 0;i < len;i++){
		if(tr[u][str[i]-'a'] == 0)tr[u][str[i]-'a'] = ++tot;
		u = tr[u][str[i]-'a'];
	}
	tag[u].push_back(no);
	return ;
}
inline void Build(){
	queue<int> q;
	for(int i = 0;i < 26;i++){
		if(tr[0][i] != 0)q.push(tr[0][i]);
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		for(int i = 0;i < 26;i++){
			if(tr[u][i]){
				fail[tr[u][i]] = tr[fail[u]][i];
				q.push(tr[u][i]);
			}else{
				tr[u][i] = tr[fail[u]][i];
			}
		}
	}
	return ;
}
inline void Find(const string& str){
	int u = 0,len = str.length();
	for(int i = 0;i < len;i++){
		u = tr[u][str[i] - 'a'];
		val[u]++;
	}
	return ;
}
inline void Count(){
	for(int i = tot;i >= 1;i--){
		val[fail[i]] += val[i];
		for(int j = 0;j < tag[i].size();j++){
			ans[tag[i][j]] = val[i];
		}
	}
	
	return ;
} 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>t;
		Insert(t,i);
	}
	Build();
	cin>>s;
	Find(s);
	Count();
	for(int i = 1;i <= n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
