#include<bits/stdc++.h>
#include "ds.h"
using namespace std;
const int MAXN = 1006;
int vl[MAXN],dee[MAXN];
void eex(int a,int b){
	swap(dee[a],dee[b]);
	if(a != b)exchange(a,b);
	return ;
}
void solve(int n, int lim1, int lim2) {
	vector<int> par(n - 1),val(n - 1),pos(n+2);
	pos[1] = 1;
	for(int i = 1;i < n;i++){
		dee[i] = i;
	}
	for(int i = 1;i < n;i++){
		for(int j = 2;j <= n;j++){
			vl[j] = query(j);
			if(vl[j] == i-1){
				par[j-2] = pos[i-1];
				pos[i] = j;
			}
		}
		sort(vl+1,vl+n+1);
		eex(i,vl[i+1]);
	}
	for(int j = 2;j <= n;j++){
		vl[j] = query(j);
		if(vl[j] == n-1){
			par[j-2] = pos[n-1];
			pos[n] = j;
		}
	}
	for(int i = 1;i < n;i++){
		val[pos[i+1]-2] = dee[i];
	}
	answer(par, val);
	return ;
}
