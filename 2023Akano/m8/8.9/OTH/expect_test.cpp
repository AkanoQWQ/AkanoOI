#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20;
const double EPS = 1e-13;
int n;
struct Node{
	int fa[MAXN];
	double val;
	int GetFa(int x){
		if(fa[x] == x)return x;
		return fa[x] = GetFa(fa[x]);
	}
	inline void Merge(int x,int y){
		x = GetFa(x),y = GetFa(y);
		if(x > y)swap(x,y);//x < y
		fa[y] = x;
		return ;
	}
	inline void Build(){
		for(int i = 1;i <= n;i++)fa[i] = GetFa(i);
		return ;
	}
};
bool operator==(Node n1,Node n2){
	for(int i = 1;i <= n;i++){
		if(n1.fa[i] != n2.fa[i])return false;
	}
	return true;
}
vector<Node> f[MAXN];
double poss[MAXN][MAXN];
inline void Move(const Node& pre,int u){
	int maxstat = 1<<(u-1);
	for(int i = 0;i < maxstat;i++){
		Node now = pre;
		for(int v = 1;v < u;v++){
			if(i & (1<<(v-1))){
				now.val *= poss[u][v];
				now.Merge(u,v);
			}else{
				now.val *= (1-poss[u][v]);
			}
		}
		if(now.val <= EPS)continue;//OK?
		now.Build();
		bool ins = false;
		for(auto& org : f[u]){
			if(now == org){
				org.val += now.val;
				ins = true;
				break;
			}
		}
		if(ins == false){
			f[u].push_back(now);
		}
	}
	return ;
}
inline void Init(){
	Node fir;
	for(int i = 1;i <= n;i++){
		fir.fa[i] = i,fir.val = 1;
	}
	f[1].push_back(fir);
	return ;
}
double ans;
inline double Calc(const Node& node){
	int cnt = 0;
	for(int i = 1;i <= n;i++)cnt += (node.fa[i] == i);
	return node.val * cnt; 
} 
int main(){
	freopen("expect.in","r",stdin);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			scanf("%lf",&poss[i][j]);
		}
	}
	Init();
	for(int i = 2;i <= n;i++){
		cout<<"CALC "<<i<<" and size "<<f[i-1].size()<<endl;
		for(auto stat : f[i-1]){
			Move(stat,i);
		}
	}
	for(auto i : f[n]){
		ans += Calc(i);
	}
	printf("%.6lf",ans);
	return 0;
}

