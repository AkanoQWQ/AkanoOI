#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 5e4 + 1018 + 1108;
const int MAXM = 1e5 + 1018 + 1108;
const string fail = "Akano loves pure__Elysia";
struct Edge{
	int nxt,to;
}e[MAXM * 2];
int head[MAXN*2],cnt;
inline void AddEdge(int from,int to){
	cerr<<"Add "<<from<<" to "<<to<<endl;
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m,d;
string str;
struct Rule{
	int u,v;
	char uc,vc;
}rule[MAXM];
bool chooseA[MAXN];//钦定是A 
/*
契约:
在布尔方程中,false为可能的取值中小的那一个(比如说可以选AC,false指A),true为可能取值大的那一个

*/

inline int IsSmall(int x,char ch){
	if(str[x] == 'a')return ch == 'B';
	if(str[x] == 'b')return ch == 'A';
	if(str[x] == 'c')return ch == 'A';
	return ch == 'B';//chooseA
}
inline bool IsBig(int x,char ch){
	return not(IsSmall(x,ch));
}
inline char GetSmall(int x){
	if(str[x] == 'a')return 'B';
	if(str[x] == 'b')return 'A';
	if(str[x] == 'c')return 'A';
	if(chooseA[x])return 'B';//这个怎么选? 
	return 'A';
}
inline char GetBig(int x){
	if(str[x] == 'a')return 'C';
	if(str[x] == 'b')return 'C';
	if(str[x] == 'c')return 'B';
	return 'C';//chooseA
}

int dfn[MAXN*2],low[MAXN*2],bel[MAXN*2],SCC_CNT,dnt;
bool ins[MAXN * 2];
stack<int,vector<int> > stk;
void Tarjan(int u){
	dfn[u] = low[u] = ++dnt;
	stk.push(u);
	ins[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			Tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(ins[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(low[u] == dfn[u]){
		SCC_CNT++;
		int tp = 0;
		do{
			tp = stk.top();
			stk.pop();
			ins[tp] = false;
			bel[tp] = SCC_CNT;
		}while(tp != u);
	}
	return ;
}

inline string Solve(int stat){
	const int truePoint = n*2+1;//虚拟点,限制某些点一定选真 
	int now = 0;
	cnt = 0,dnt = 0,SCC_CNT = 0;
	for(int i = 1;i <= 2*n+1;i++){//清空所有信息 
		head[i] = dfn[i] = low[i] = 0;
	}
	for(int i = 1;i <= n;i++){
		if(str[i] == 'x'){
			if((1<<now) & stat){
				chooseA[i] = true;
			}else{
				chooseA[i] = false;
			}
			now++;
		}
	}
	for(int i = 1;i <= n*2;i++){//连向虚拟点 
		AddEdge(truePoint,i);
	} 
	for(int i = 1;i <= m;i++){
		if(chooseA[rule[i].u] && chooseA[rule[i].v]){//必须uc不为A或者vc为A 
			if(rule[i].uc == 'A' && rule[i].vc != 'A')return fail;
		}if(chooseA[rule[i].u]){//uc为A,v必须选vc
			if(rule[i].uc == 'A'){
				AddEdge(truePoint,rule[i].v + (IsBig(rule[i].v,rule[i].vc) ? n : 0));
			}
		}else if(chooseA[rule[i].v]){//vc不为A,u不能选uc 
			if(rule[i].vc != 'A'){
				AddEdge(truePoint,rule[i].u + (IsSmall(rule[i].u,rule[i].uc) ? n : 0));//IsSmall反过来,uc小就选大,uc大就选小 
			}
		}else{//若u选了uc,则v选择vc 
			AddEdge(rule[i].u + (IsBig(rule[i].u,rule[i].uc) ? n : 0),rule[i].v + (IsBig(rule[i].v,rule[i].vc) ? n : 0));
		}
	}
	for(int i = 1;i <= 2*n+1;i++){
		if(!dfn[i])Tarjan(i);
	}
	string ret;
	for(int i = 1;i <= n;i++){
		if(bel[i] == bel[i+n])return fail;
		if(chooseA[i]){
			ret += 'A';
		}else if(bel[i] > bel[i+n]){
			ret += GetSmall(i);
		}else{
			ret += GetBig(i);
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("P3825_2.in","r",stdin);
	cin>>n>>d;
	cin>>str;
	str = "." + str;
	cin>>m;
	for(int i = 1;i <= m;i++){
		cin>>rule[i].u>>rule[i].uc>>rule[i].v>>rule[i].vc;
	}
	for(int stat = 0;stat < (1<<d);stat++){
		string ans = Solve(stat);
		if(ans != fail){
			cout<<ans<<endl;
			return not(Akano loves pure__Elysia);
		}
	}
	cout<<"-1"<<endl;
	return not(Akano loves pure__Elysia);
}
