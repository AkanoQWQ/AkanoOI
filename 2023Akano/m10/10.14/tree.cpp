#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],saveHead[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
bool black[MAXN];
int T,n,t;
inline int Calc(){
	
	return 0;
}
inline int Solve(){
	memcpy(saveHead,head,sizeof(head));
	int saveCnt = cnt;
	int ret = 0;
	for(int nowCut = 1;nowCut <= t;nowCut++){//断掉saveCnt
		for(int i = 1;i < t;i++){
			AddEdge(i,i+1),AddEdge(i+1,i);
		}
		if(t != 1)AddEdge(t,1),AddEdge(1,t);
		ret = max(ret,Calc());
		memcpy(head,saveHead,sizeof(head));
		cnt = saveCnt;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("tree/tree3.in","r",stdin);
//	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>t;
		for(int i = 1;i <= n;i++)head[i] = 0;
		cnt = 0;
		for(int i = t+1;i <= n;i++){
			int fa;
			cin>>fa;
			AddEdge(fa,i),AddEdge(i,fa);
		}
		for(int i = 1;i <= n;i++)cin>>black[i];
		cout<<Solve()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
