#include<bits/stdc++.h>
#include "comp.h"
using namespace std;
const int MAXN = 1e6 + 7;
int t = 10,n = 1000;
int tr[MAXN]; 
mt19937 rng(GetTime());
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("B7023.in","w",stdout);
	cout<<t<<endl;
	while(t--){
		cout<<n<<endl;
		for(int i = 1;i <= n;i++)tr[i] = i;
		shuffle(tr+1,tr+n+1,rng);
		for(int i = 1;i < n;i++){
			cout<<tr[i]<<" "<<tr[i+1]<<endl;
		}
	}
	return 0;
}

