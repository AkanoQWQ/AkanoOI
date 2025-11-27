#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
const int MAXVAL = 45000;
const int MAXN = 5006;
vector<int> sons[MAXN],e[MAXN];
int n,fa[MAXN],ansfa[MAXN],dep[MAXN],querys;
void dfs(int u,int father){
	dep[u] = dep[father] + 1;
	ansfa[u] = father;
	sons[u].push_back(u);
	for(auto v : e[u]){
		if(v == father)continue;
		dfs(v,u);
		for(auto i : sons[v])sons[u].push_back(i);
	}
	return ;
}
inline void AddQuerys(int val){
	query += val;
	if(query > MAXVAL){
		quitf(_wa,"You have used %d querys,expected less than %d",query,MAXVAL);
	}
}
int main(int argc, char* argv[]){
	registerInteraction(argc, argv);
	n = inf.readInt();
	cout<<n<<endl;
	for(int i = 1;i < n;i++){
		int u = inf.readInt(),v = inf.readInt();
		e[u].push_back(v),e[v].push_back(u);
	}
	dfs(1,1);
	while(1){
		char opt = ouf.readChar();
		if(opt == '!'){
			for(int i = 2;i < n;i++){
				fa[i] = ouf.readInt();
			}
			for(int i = 2;i < n;i++){
				if(ansfa[i] != fa[i]){
					quitf(_wa,"Wrong answer.Read %d but expected %d",fa[i],ansfa[i]);
				}
			}
			quitf(_ok,"Congrat AC with %d querys used",query);
		}else if(opt == '?'){
			int typ = ouf.readInt();
			if(typ == 1){
				int u = ouf.readInt();
				int v = ouf.readInt();
				int ret = 0;
				while(u != v){
					if(dep[u] < dep[v]){
						swap(u,v);
					}
					u = fa[u];
					++ret;
				}
				cout<<ret<<endl;
				AddQuerys(1);
			}else{
				int u = ouf.readInt();
				cout<<sons[u].size()<<" ";
				for(auto i : sons[u]){
					cout<<i<<" ";
				}
				cout<<endl;
				AddQuerys(sons[u].size() + 1);
			}
		}else{
			quitf(_wa,"Unexpected operator char %c",opt);
		}
	}
	return 0;
}
