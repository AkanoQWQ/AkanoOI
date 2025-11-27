#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
const int MAXK = 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 6;
const int MAXP = 200611;
int pos[MAXK],np[MAXK],c[MAXN],d[MAXN];
int n,k,w[MAXK],cnt,step,vis[MAXP][2];
bool cannot = 0;
int id(){
	int ret = 0;
	for(int i = 1;i <= k;i++){
		ret = ret * 11 + pos[i];
	}
	return ret;
}
bool inc(){
	for(int i = 1;i <= k;i++){
		if(pos[i] < 1 || pos[i] > w[i])return 0;
	}
	return 1;
}
void show(){
	for(int i = 1;i <= k;i++)cout<<pos[i]<<" ";
	cout<<endl;
	return ;
}
void calc(){
	++cnt;
	const int ststep = step;
	for(int i = 1;i <= k;i++)pos[i] = np[i];
	int nowk = 1;
	vis[id()][0] = cnt;
	vis[id()][1] = 0;
	while(inc()){
		pos[c[nowk]] += d[nowk];
		const int nowid = id();
		if((vis[nowid][0] == cnt && vis[nowid][1] == nowk) || step - ststep >= 2114514){
			cannot = 1;
			return ;
		}
		vis[nowid][0] = cnt;
		vis[nowid][1] = nowk;
		++step;
		if(step >= MOD)step -= MOD;
		nowk++;
		if(nowk > n){
			nowk = 1;
		}
	}
}
void dfs(int dep){
	if(cannot)return ;
	if(dep > k){
		calc();
		return ;
	}
	for(int i = 1;i <= w[dep];i++){
		np[dep] = i;
		dfs(dep+1);
	}
	return ;
}
EXCUTE_ST
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n >= 250){
		puts("-1");
		return 0;
	}
	for(int i = 1;i <= k;i++){
		scanf("%d",&w[i]);
	}
	for(int i = 1;i <= n;i++){
		scanf("%d%d",&c[i],&d[i]);
	}
	dfs(1);
	if(cannot){
		puts("-1");
	}else{
		cout<<step;
	}
FILE_ED_And_excute

