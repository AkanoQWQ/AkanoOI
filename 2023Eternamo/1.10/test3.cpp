#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 206;
int n,h[MAXN],q;
vector<int> damage[MAXN];
int ksm(int a,int b){
	int ret = 1;
	while(b){
		if(b & 1)ret = (1ll * ret * a) % MOD;
		a = (1ll * a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
int inv(int inx){
	return ksm(inx,MOD-2) % MOD;
}
int divv(int a,int b){
	return (1ll * a * inv(b)) % MOD;
}
bool selected[MAXN];
int maxdep,trans;
void select(int pos){

	selected[pos] = 0;
	select(pos + 1);
	selected[pos] = 1;
	select(pos + 1);
}
int calc1(int id){
	if(damage[id].size() < h[id])return 1;
	maxdep = damage[id].size(),trans = h[id];
	select(0);
	return 1;
}
int main(){
	cout<<divv(2,5)<<" "<<divv(3,5)<<" "<<(divv(2,5)+divv(3,5) - 1);
	return 0;
}
