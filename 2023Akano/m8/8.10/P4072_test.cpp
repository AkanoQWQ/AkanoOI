#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 114;
const int MAXM = MAXN;
const int SIZE = 20;
const int LIVE = 6;
ll n,m,len[MAXN],sum[MAXN],ans = 2e9;
mt19937 rng(time(0));
struct POP{
	ll arr[MAXM],nowval;
	inline void Shuffle(){
		arr[m+1] = n,arr[0] = 0;
		int pos = (rng()%m) + 1;
		int lower = arr[pos-1],upper = arr[pos+1];
		arr[pos] = (rng() % (upper - lower + 1)) + lower;
		return ;
	}
	inline void Calc(){
		nowval = sum[n] * sum[n];
		for(int i = 1;i <= m;i++){
			const int nowx = sum[arr[i]] - sum[arr[i-1]];
			nowval += nowx * nowx * m - 2 * sum[n] * nowx;
		}
		return ;
	}
}pop[SIZE+2];
bool Cmp(POP p1,POP p2){
	return p1.nowval < p2.nowval;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>len[i];
		sum[i] = sum[i-1] + len[i];
	}
	for(int i = 1;i <= m;i++){
		pop[1].arr[i] = (rng()%n) + 1;
	}
	sort(pop[1].arr+1,pop[1].arr+m+1);
	for(int i = 2;i <= SIZE;i++)pop[i] = pop[1];
	while(clock() * 1000 / CLOCKS_PER_SEC < 980){
		for(int i = 1;i <= SIZE;i++){
			pop[i].Shuffle();
			pop[i].Calc();
		}
		sort(pop+1,pop+SIZE+1,Cmp);
		ans = min(ans,pop[1].nowval);
		for(int i = LIVE+1;i <= SIZE;i++){
			pop[i] = pop[(i % LIVE) + 1];
		}
	}
	cout<<ans<<endl;
	return 0;
}
