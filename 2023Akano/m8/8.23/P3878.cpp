#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 32;
const double startTemp = 2006 + 1018 + 1108 + 5000;
const double deltaT = 0.9999010181108;
const double endT = 1e-8;
const int MAXVAL = 1e9;
mt19937 rng(time(0));
ll arr[MAXN],n,set1[MAXN],set2[MAXN],num[MAXN];
inline double Rand1(){
	return 1.0f * (rng() % MAXVAL) / MAXVAL;
}
inline ll Solve(){
	double temp = startTemp;
	cin>>n;
	const int up = n / 2,other = n - up;
	for(int i = 1;i <= n;i++)cin>>arr[i];
	if(n == 1){
		return arr[1];
	}
	ll sum = 0,now = 0,ans = 1e9;
	for(int i = 1;i <= n;i++){
		num[i] = i;
		sum += arr[i];
	}
	shuffle(num+1,num+n+1,rng);
	for(int i = 1;i <= up;i++){
		set1[i] = num[i];
		now += arr[num[i]];
	}
	ans = abs(sum - 2 * now);
	for(int i = 1;i <= other;i++)set2[i] = num[up+i];
	while(temp > endT){
		int rd1 = (rng() % up) + 1,rd2 = (rng() % other) + 1;
		int newnow = now - arr[set1[rd1]] + arr[set2[rd2]];
		int newans = abs(sum - 2 * newnow);
		if(newans < ans){
			swap(set1[rd1],set2[rd2]);
			ans = newans,now = newnow;
		}else if(Rand1() < exp(-(newans - ans) / temp)){
			now = newnow,swap(set1[rd1],set2[rd2]);
		}
		temp *= deltaT;
	}
	return ans;
}
int t;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)cout<<Solve()<<endl;
	return 0;
}
