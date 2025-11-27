#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+7;
const int MAXE = 1e8+7;
struct Edge{
	int from,to,dist;
};
bool myCmp(Edge x,Edge y){
	return x.dist<y.dist;
} 
Edge edge[MAXE];
int n,e,u,v,d,fa[MAXN],tot,cnt;
int find_baba(int x){
	while(x!=fa[x]){
		x = fa[x];
	}
	return x;
}
int find_baba_fast(int x){
	int tx = x;
	while(x!=fa[x]){
		x = fa[x];
	}
	int tmp;
	while(tx!=x){
		tmp = tx;
		tx = fa[tx];
		fa[tmp] = x;
	}
	return x;
}
int UnionSet(int x,int y){
	int tx = find_baba_fast(x);
	int ty = find_baba_fast(y);
	if(tx!=ty){
		fa[tx] = ty;
		return 1;
	}else{
		return 0;
	}
}
void Kruskal(){
	sort(edge,edge+e,myCmp);
	for(int i=0;i<=n;++i){
		fa[i] = i;
	}
	for(int i=0;cnt<n&&i<e;i++){
		if(UnionSet(edge[i].from,edge[i].to)==1){
			cout<<edge[i].from<<" "<<edge[i].to<<" "<<edge[i].dist<<endl;
			tot+=edge[i].dist;
			cnt++;
		}	
	}
}
int main(){
	cin>>n>>e;
	for(int i=0;i<e;++i){
		cin>>edge[i].from>>edge[i].to>>edge[i].dist;
	}
	Kruskal();
//	for(int i=0;i<=n;++i){
//		cout<<i<<" "<<fa[i]<<endl;
//	}
	cout<<tot;
	return 0;
}
/*
8 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 5 14
3 4 9
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
