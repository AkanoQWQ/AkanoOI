#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int MAXN = 1018;
bool ban[MAXN];
int n,m,str[MAXN];
int fa[MAXN];
int Find(int x){
	if(fa[x] == x)return x;
	return fa[x] = Find(fa[x]);
}
inline void Merge(int x,int y){
	x = Find(x),y = Find(y);
	if(x < y)swap(x,y);
	fa[x] = y;
}
bool fail;
vector<pii> edge;
vector<int> e[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n+1;i++)fa[i] = i;
	for(int i = 1;i <= m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(x > y)swap(x,y);
		for(int j = 1;j <= z;j++){
			Merge(y+j-1,x+j-1);//后面的连到前面上去
		}
		edge.emplace_back(y+z,x+z);
	}
	for(auto i : edge){
		i.first = Find(i.first),i.second = Find(i.second);
		if(i.first == i.second)fail = true;
		e[i.first].push_back(i.second),e[i.second].push_back(i.first);
	}
	for(int i = 1;i <= n && fail == false;i++){
		if(Find(i) != i){
			str[i] = str[Find(i)];
			continue;
		}
		str[i] = 0;
		memset(ban,0,sizeof(ban));
		for(auto v : e[i]){
			if(v > i)continue;
			ban[str[v]] = true;
		}
		for(int j = 0;j <= n+1;j++){
			if(ban[j])continue;
			str[i] = j;
			break;
		}
	}
	if(fail){
		cout<<-1<<endl;
	}else{
		for(int i = 1;i <= n;i++){
			cout<<str[i]<<" ";
		}
		cout<<endl;
	}
	return not(Akano loves pure__Elysia);
}
