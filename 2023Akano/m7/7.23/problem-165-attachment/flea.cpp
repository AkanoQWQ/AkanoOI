#include "flea.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1018;
const int MAXM = 1e6 + 1018 + 1108;
ll vals[MAXM],a,b,c;
long long find_max(int n, int m){
	for(int i = 1;i <= m;i++)vals[i] = LLONG_MAX;
//	int rd = (rand() % m) + 1;
	get(1,&a,&b,&c);
	for(int i = 2;i <= n;i++){
		int pos = 0;
		ll nowval = 0;
		for(ll i = 1;i <= m;i++){
			vals[i] = min(vals[i],a * i * i + b * i + c);
			if(vals[i] > nowval){
				nowval = vals[i],pos = i;
			}
		}
		get(pos,&a,&b,&c);
		if(a * pos * pos + b * pos + c == nowval)return nowval;
	}
	ll nowval = 0;
	for(int i = 1;i <= m;i++){
		vals[i] = min(vals[i],a * i * i + b * i + c);
		nowval = max(nowval,vals[i]);
	}
	return nowval;
}
