#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t,n;
inline ll Solve(const int& x){
	ll ret = 0;
	int l = 1,r = 0;
	while(l <= x){
		const int r = (x / (x / l));
		ret += (r - l + 1) * (x / l);
		l = r + 1;
	}
	return ret;
}
inline ll BF(const int& x){
	ll ret = 0;
	for(int i = 1;i <= x;i++){
		ret += x / i;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 1;i <= 30000;i++){
		if(Solve(i) != BF(i)){
			cout<<i<<"Read "<<Solve(i)<<" Expected "<<BF(i)<<endl;
		}
	}
	return 0;
}

