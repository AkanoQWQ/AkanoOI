#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = __int128;
istream& operator>>(istream& is,ll& val){
	long long cache;
	is>>cache;
	val = cache;
	return is;
}
ostream& operator<<(ostream& os,ll val){
	long long cache;
	cache = val;
	os<<cache;
	return os;
}
const int SIZE = 11;
const int prime[SIZE + 1] = {0,2,3,5,7,11,13,17,19,23,27,29};
int powCnt[SIZE+1];
ll n,primePow[SIZE+1][70],ansVal,ansSize;
inline ll GetAns(){
	ll ret = 1;
	for(int i = 1;i <= SIZE;i++){
		ret *= (powCnt[i] + 1);
	}
	return ret;
}
void dfs(int u,ll nowval){
	if(nowval > n)return ;
	if(u > SIZE){
		ll res = GetAns();
		if((res > ansSize) || (res == ansSize && nowval < ansVal)){
			ansVal = nowval;
			ansSize = res;
		}
		return ;
	}
	for(int i = 0;i <= powCnt[u-1];i++){
		if(primePow[u][i] == 0)break;
		powCnt[u] = i;
		dfs(u+1,nowval * primePow[u][i]);
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	powCnt[0] = n;
	for(int i = 1;i <= SIZE;i++){
		primePow[i][0] = 1;
		for(int j = 1;j < 60;j++){
			primePow[i][j] = primePow[i][j-1] * prime[i];
			if(primePow[i][j] >= n)break;
		}
	}
	dfs(1,1);
	cout<<ansVal<<endl;
	return not(Akano loves pure__Elysia);
}
