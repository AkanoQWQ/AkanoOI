#include<bits/stdc++.h>
using namespace std;
const int maxm = 10006;
int Next[maxm],first[maxm],en[maxm],sign,n,m,dfn[maxm],low[maxm],tot,sta[maxm];
int top,sum,id[maxm],i,j,a,b;
bool insta[maxm];
void Add(int x,int y){
	tot++;
	Next[tot] = first[x];
	first[x] = tot;
	en[tot] = y;
	return ;
}
void dfs(int x){
	int k,i;
	sign++;
	dfn[x] = sign,low[x] = sign;
	top++;
	sta[top] = x,insta[x] = 1;
	k = first[x];
	while(k != 0){
		i = en[k];
		if(dfn[i] == 0){
			dfs(i);
			if(low[i] < low[x]){
				low[x] = low[i];
			}
		}else{
			if((insta[i]) && (dfn[i] < low[x])){
				low[x] = dfn[i];
			}
		}
		k = Next[k];
	}
	if(low[x] == dfn[x]){
		sum++;
		i = sta[top];
		while(i != x){
			id[i] = sum;
			insta[i] = 0;
			top--;
			i = sta[top];
		}
		id[x] = sum;
		insta[x] = 0;
		top--;
	}
	return ;
}

int main(){
	freopen("tarjin.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(i = 1;i <= m;i++){
		cin>>a>>b;
		Add(a,b);
	}
	memset(dfn,0,sizeof(dfn));
	sum = 0,sign = 0;
	for(i = 1;i <= n;i++){
		if(dfn[i] == 0)dfs(i);
	}
	cout<<sum<<endl;
	for(i = 1;i <= n;i++){
		cout<<i<<"属于第"<<id[i]<<"个强连通分量"<<endl;
		//cout<<i<<":"<<dfn[i]<<" "<<low[i]<<endl; 
	}
	return 0;
}//12345679
