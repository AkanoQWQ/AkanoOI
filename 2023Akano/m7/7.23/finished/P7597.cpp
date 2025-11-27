#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int MAXN = (2006 + 1018 + 1108) * 2;
mt19937 rng(time(0));
vi sons[MAXN],dir[MAXN],temp;
int cnt = 0,n,k,c,heavy[MAXN],dep[MAXN],father[MAXN];
bool known[MAXN];
inline int GetDis(int u,int v){
	int ret = 0;
	if(u == v)return ret;
	cout<<"? 1 "<<u<<" "<<v<<endl;cout.flush();
	cin>>ret;
	return ret;
}
inline void GetDep(){
	for(int i = 2;i <= n;i++){
		dep[i] = GetDis(1,i);
	}
	known[1] = true;
	return ;
}
void Solve(int u,int fa,bool BF,int top){
	father[u] = fa;
	int rd = 0;
	if(BF){
		cout<<"? 2 "<<u<<endl;cout.flush();
		cin>>k;
		for(int i = 1;i <= k;i++){
			cin>>c;
			if(c != u)sons[u].push_back(c);
		}
		k--;
		for(auto i : sons[u]){
			if(dep[i] == dep[u] + 1){
				dir[u].push_back(i);
				known[i] = true;
			}
		}
		if(k != 0)rd = sons[u][rng() % k];
	}else{
		temp.clear();
		for(auto v : sons[top]){
			if(!known[v]){
				if(dep[v] == dep[u] + 1){
					dir[u].push_back(v);
					known[v] = true;
				}
				temp.push_back(v);
			}
		}
		if(temp.size() != 0)rd = temp[rng() % temp.size()];
	}
	int FD = 0;
	for(auto v : dir[u]){
		if(v == rd)FD = v;
	}
	if(FD == 0){
		int heavydis = 1e8,dis = 0;
		for(auto v : dir[u]){
			dis = GetDis(rd,v);
			if(heavydis > dis){
				heavy[u] = v,heavydis = dis;
			}
		}
	}else{
		heavy[u] = FD;
	}
	for(auto v : dir[u]){
		if(heavy[u] == v)continue;
		Solve(v,u,true,v);
	}
	if(heavy[u] != 0){
		Solve(heavy[u],u,false,top);
	}
	return ;	
}
inline void Output(){
	cout<<"! ";
	for(int i = 2;i <= n;i++){
		cout<<father[i]<<" ";
	}
	cout<<endl;cout.flush();
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	GetDep();
	Solve(1,1,true,1);
	Output();
	return 0;
}
