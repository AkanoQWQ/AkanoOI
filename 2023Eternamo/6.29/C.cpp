#include<bits/stdc++.h>
using namespace std;
const int MAXS = 3e5 + 6;
int T,m,nxt[MAXS][12],lst[12],ans[12];
string s,l,r;
bool fd;
void dfs(int tail,int pos){
	if(fd)return ;
	if(pos == m){
		if(tail == -1){
			cout<<"YES"<<endl;
			fd = 1;
		}
		return ;
	}
	for(char s = l[pos];s <= r[pos];s++){
		const int i = s - '0';
		ans[pos] = i;
		if(tail == -2){
			dfs(lst[i],pos+1);
		}else if(tail == -1){
			dfs(-1,pos+1);
		}else{
			dfs(nxt[tail][i],pos+1);
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		fd = false;
		cin>>s>>m>>l>>r;
		for(int i = 0;i <= 10;i++)lst[i] = -1;
		for(int i = s.length()-1;i >= 0;i--){
			for(int j = 0;j <= 9;j++){
				nxt[i][j] = lst[j];
			}
			lst[s[i] - '0'] = i;
		}
		dfs(-2,0);
		if(!fd){
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

