#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+6;
int t,n,a[MAXN*2],opp[MAXN];
int pr[MAXN][2];
bool opt[MAXN*2];
void dfs(int dep,int pos){
	if(pos == -1){
		
	}
	return ;
}
int main(){
	freopen("palin.in","r",stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 1;i <= 2*n;i++){
			scanf("%d",&a[i]);
			pr[a[i]][1] = pr[a[i]][0];
			pr[a[i]][0] = i;
		}
		for(int i = 1;i <= 2*n;i++){
			if(pr[a[i]][0] != i){
				opp[i] = pr[a[i]][0];
			}else{
				opp[i] = pr[a[i]][1];
			}
			cout<<opp[i]<<" ";
		}
		cout<<endl;
		dfs(1,-1);
	}
	return 0;
}

