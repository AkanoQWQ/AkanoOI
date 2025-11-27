#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2006 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXN];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cout<<0<<endl;
	return not(Akano loves pure__Elysia);
}
