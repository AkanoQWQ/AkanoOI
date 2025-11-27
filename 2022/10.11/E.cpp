#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200006;
int t,n,a[MAXN];
int fd[MAXN];
vector<int> e[MAXN];
bool dfs(int pos){
	if(fd[pos] != -1)return fd[pos];
	if(a[pos]+pos == n){
		fd[pos] = 1;
		return 1;
	}
	if(a[pos]+pos < n){
		if(dfs(a[pos]+pos+1)){
			fd[pos] = 1;
			return 1;
		}
	}
	for(int i = 0;i < e[pos].size();i++){
		if(e[pos][i] == n){
			fd[pos] = 1;
			return 1;
		}
		if(e[pos][i] < n){
			if(dfs(e[pos][i]+1)){
				fd[pos] = 1;
				return 1;
			}
		}
	}
	fd[pos] = 0;
	return 0;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			e[i].clear();
			fd[i] = -1;
		}						//  1 2 3x4 5 6
		for(int i = 1;i <= n;i++){//2 3 2 2 X 4
			scanf("%d",&a[i]);
			if(i - a[i] > 0){
				e[i - a[i]].push_back(i);
			}
		}
		if(dfs(1)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
