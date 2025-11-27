#include<iostream>
#include<set>
#include<cstring>
#include<queue>
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int N=1e5+10;
int n,K,m,S,dis[N];
bool ban[N];
set<int> odd,even;

void BFS(){
	memset(dis,-1,sizeof(dis));
	queue<int> q;
	dis[S]=0,q.push(S);
	while(!q.empty()){
		int o=q.front();
		q.pop();
		int L=max(1,o-K+1),R=min(n,o+K-1);
		L=L+(L+K-1)-o,R=R+(R-K+1)-o;
		set<int>&p=L&1?odd:even;
		for(auto i=p.lower_bound(L);i!=p.end()&&*i<=R;p.erase(i++)){
			dis[*i]=dis[o]+1,q.push(*i);
		}
	}
}

int main(){
	freopen("reverse.in","r",stdin);
	freopen("reverse.out","w",stdout);
	scanf("%d%d%d%d",&n,&K,&m,&S);
	For(i,1,m){
		int x;
		scanf("%d",&x);
		ban[x]=true;
	}
	For(i,1,n){
		if((!ban[i])&&i!=S){
			i&1?odd.insert(i):even.insert(i);
		}
	}
	BFS();
	For(i,1,n){
		printf("%d%c",dis[i],i==n?'\n':' ');
	}
	return 0;
}
