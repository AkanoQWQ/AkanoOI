#include<bits/stdc++.h>
using namespace std;
const int MAXN = 14;
const int SIZE = 10;
const int LIVE = 5;
mt19937 rng(time(0));
int n,m;
struct POP{
	int nowval;
	char c[MAXN][MAXN];
	inline void Shuffle(){
		bool UD = rng() % 2;
		int up = UD ? n : m;
		int l = (rng() % up) + 1,r = (rng() % up) + 1;
		if(UD){
			for(int i = 1;i <= m;i++){
				swap(c[l][i],c[r][i]);
			}
		}else{
			for(int i = 1;i <= n;i++){
				swap(c[i][l],c[i][r]);
			}
		}
		return ;
	}
	inline void Calc(){
		nowval = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				const int OPi = (n + 1) - i,OPj = (m + 1) - j;
				nowval += c[i][j] != c[OPi][OPj];
			}
		}
		return ;
	}
}pop[SIZE + 2];
bool Cmp(POP p1,POP p2){
	return p1.nowval < p2.nowval;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>pop[1].c[i][j];
		}
	}
	for(int i = 2;i <= SIZE;i++){
		pop[i] = pop[1];
	}
	int t = 10000;
	while(t--){
		for(int i = 1;i <= SIZE;i++){
			pop[i].Shuffle();
		}
		for(int i = 1;i <= SIZE;i++){
			pop[i].Calc();
		}
		sort(pop+1,pop+SIZE+1,Cmp);
		if(pop[1].nowval == 0){
			cout<<"YES"<<endl;
			return 0;
		}
		for(int i = LIVE+1;i <= SIZE;i++){
			pop[i] = pop[(i % LIVE)+1];
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
