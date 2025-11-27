#include<bits/stdc++.h>
#include "comp.h"
using namespace std;
const int MAXN = 2e5 + 6;
const int MAXV = 2e5;
int trees[MAXN];
int n = 2e5;
mt19937 rng(GetTime());
int main(){
//	freopen("./signin/ex_signin4.in","r",stdin);
	freopen("B6304.in","w",stdout);
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		trees[i] = i;
	} 
//	shuffle(trees+1,trees+n+1,rng);
//	for(int i = 1;i < n;i++){
//		cout<<trees[i]<<" "<<trees[i+1]<<endl;
//	}
	for(int i = 1;i < n;i++){
		cout<<1<<" "<<i<<endl;
	}
	for(int i = 1;i <= n;i++){
		cout<<rng() % MAXV<<" ";
	}
	cout<<flush;
	return 0;
}

