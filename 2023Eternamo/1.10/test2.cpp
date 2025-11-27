#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2006;
struct damage{
	double v,poss; 
}d[MAXN];
double enemy = 22;
int n = 4;
bool hit[MAXN];
int poss;
bool calc(){
	int dam = 0;
	double pos = 1;
	for(int i = 0;i <= n;i++){
		if(hit[i]){
			dam += d[i].v;
			pos *= d[i].poss;
		}
	}
	if(dam >= enemy){
		return 1;
	}
	return 0;
} 
void dfs(int dep){
	if(dep > n){
		poss += calc();
		return ;
	}
	hit[dep] = 0;
	dfs(dep + 1);
	hit[dep] = 1;
	dfs(dep + 1);
	return ;
}
int main(){
	d[0].v = 3,d[0].poss = 0.25;
	d[1].v = 5,d[1].poss = 0.125;
	d[2].v = 4,d[2].poss = 0.333;
	d[3].v = 9,d[3].poss = 0.1;
	d[4].v = 6,d[4].poss = 0.2;
	dfs(0);
	cout<<(double(poss) / (1<<(n+1)));
	return 0;
}

