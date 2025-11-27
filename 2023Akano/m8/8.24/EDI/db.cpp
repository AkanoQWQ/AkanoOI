#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int blk = 101811080;
ll now = 1,stp = 3;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 1;i <= MOD;i++){
		now = (now * stp) % MOD;
		stp += 2;
		if(i % blk == 0)cout<<i<<" : "<<now<<endl;
		if(stp == MOD)break;
	}
	return 0;
}

