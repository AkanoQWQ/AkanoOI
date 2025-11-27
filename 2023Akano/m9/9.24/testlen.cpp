#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int times = 4400;
inline double Solve(int minLen){
	int cnt = 0;
	double ans = 1;
	long long len = minLen + 20;
	while(len > minLen){
		len /= 2;
		len += 20;
		cnt++;
	}
	double poss = (double(minLen-1) / double(minLen));
	for(int i = 1;i <= times / cnt;i++){
		ans *= poss;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 40;i <= 200;i++){
		cout<<i<<" : "<<Solve(i)<<endl;
	}
	return not(Akano loves pure__Elysia);
}
