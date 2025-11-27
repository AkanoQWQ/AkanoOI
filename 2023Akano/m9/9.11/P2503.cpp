#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 26;
int n,m,arr[MAXN],sum[MAXN];
vector<int> vec; 
double nowans;
inline double P(double x){
	return x * x;
}
inline double Calc(const vector<int>& vec){
	vector<int> sets;
	int pre = 0;
	for(auto i : vec){
		sets.push_back(sum[i] - sum[pre]);
		pre = i;
	}
	double avg = 0,ret = 0;
	for(auto i : sets){
		avg += i;
	}
	avg /= m;
	for(auto i : sets){
		ret += P(avg - i);
	}
	ret /= m;
	ret = 
	return ;
}
inline void SA(){
	nowans = Calc();
	
	return 0;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){ 
		cin>arr[i]; 
		sum[i] = sum[i-1] + arr[i];
	}
	
	return not(Akano loves pure__Elysia);
}
