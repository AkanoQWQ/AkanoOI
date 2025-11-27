#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int MAXN = (2006 + 1018 + 1108) * 2;
mt19937 rng(time(0));
vi sons[MAXN],dir[MAXN],temp;
int cnt = 0,n,k,c,heavy[MAXN],dep[MAXN],father[MAXN];
bool known[MAXN];
inline void GetDep(){
	for(int i = 2;i <= n;i++){
		cout<<"? 1 1 "<<i<<endl;cout.flush();
		cin>>dep[i];
	}
	known[1] = true;
	return ;
}
void Solve(int u,int fa){
	father[u] = fa;
	int rd = 0;
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
	for(auto v : dir[u]){
		Solve(v,u);
	}
	return ;	
}
inline void Output(){
	cout<<"! ";cout.flush();
	for(int i = 2;i <= n;i++){
		cout<<father[i]<<" ";cout.flush();
	}
	cout<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	GetDep();
	Solve(1,1);
	Output();
	return 0;
}
