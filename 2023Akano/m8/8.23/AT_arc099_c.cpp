#include<bits/stdc++.h>
using namespace std;
const double startT = 1018 + 1108;
const double deltaT = 0.991;
const double endT = 0.0000010181108;
const int MAXVAL = 1e9;
const int MAXN = 706;
bool con[MAXN][MAXN];
int n,m,num[MAXN],set1[MAXN],set2[MAXN],ans = 1e9;
mt19937 rng(time(0));
inline double Rand1(){
	return 1.0f * (rng() % MAXVAL) / MAXVAL;
}
inline bool Judge(int x,int OBJ){
	double temp = startT;
	int now = 0,y = n - x;
	for(int i = 1;i <= n;i++)num[i] = i;
	shuffle(num+1,num+n+1,rng);
	for(int i = 1;i <= x;i++)set1[i] = num[i];
	for(int i = 1;i <= y;i++)set2[i] = num[x+i];
	for(int i = 1;i <= x;i++){
		for(int j = 1;j <= y;j++){
			now += con[set1[i]][set2[j]];
		}
	}
	int nowans = OBJ - now;
	while(temp > endT){
		int rd1 = (rand() % x) + 1,rd2 = (rand() % y) + 1;
		int delta = 0;
		for(int i = 1;i <= x;i++){
			delta += con[set1[rd1]][set1[i]];
			delta -= con[set2[rd2]][set1[i]];
		}
		for(int i = 1;i <= y;i++){
			delta += con[set2[rd2]][set2[i]];
			delta -= con[set1[rd1]][set2[i]];
		}
		if(con[set1[rd1]][set2[rd2]])delta += 2;
		int newans = abs(OBJ-(now+delta));
		if(nowans == 0 || newans == 0){
			return true;
		}
		if(newans < nowans){
			swap(set1[rd1],set2[rd2]);
			now += delta;
			nowans = newans;
		}else if(Rand1() < exp(-(newans - nowans)/temp)){
			swap(set1[rd1],set2[rd2]);
			now += delta;
			nowans = newans;
		}
		temp *= deltaT;
	}
	return false;
}
int main(){
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		con[u][v] = con[v][u] = true;
	}
	for(int i = 1;i < n;i++){
		int b = i * (i-1) / 2 + (n-i) * (n-i-1) / 2;
		if(Judge(i,m-b)){
	 		ans = min(ans,b);
		}
	}
	if(ans == 1e9)ans = -1;
	cout<<ans;
	return 0;
}
