#include<bits/stdc++.h>
using namespace std;
int father[10001];
int k,i,j,n,m,q,cache,cache2;
int getfather(int v){
	if(father[v] == v) return v;
	father[v] = getfather(father[v]);
	return father[v];
} 
int merge(int i,int j){
	i = getfather(i);
	j = getfather(j);
	if(i != j){
		father[i] = j;
	}
}
int main(){
	freopen("relation.in","r",stdin);
	//freopen("realtion.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i = 1;i <= n;i++){
		father[i] = i;
		for(k = 1;k <= m;k++){
			scanf("%d%d",&cache,&cache2);
			merge(cache,cache2);
		}
	}
	
	q = 3;
	for(i = 1;i <= q;i++){
		
		scanf("%d%d",&cache,&cache2);
		
		if(getfather(cache) == getfather(cache2)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
		
	}
	return 0;
}
