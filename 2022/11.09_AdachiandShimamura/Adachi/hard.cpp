#include<bits/stdc++.h>
using namespace std;
int n,a[200611][2],l,r,opt = 0;
int main(){
	freopen("hard.in","r",stdin);
	//freopen("hard.out","w",stdout);
	scanf("%d",&n);
	if(n > 10000)return 0;
	for(int i = 1;i <= n*2-1;i++){
		scanf("%d",&a[i][0]);
	}
	l = 1,r = n*2-1;
	while(l != r){
		for(int i = l+1;i <= r-1;i++){
			int mx = max(a[i-1][opt],max(a[i][opt],a[i+1][opt]));
			int mn = min(a[i-1][opt],min(a[i][opt],a[i+1][opt]));
			if(a[i-1][opt] != mx && a[i-1][opt] != mn)a[i][!opt] = a[i-1][opt];
			if(a[i][opt] != mx && a[i][opt] != mn)a[i][!opt] = a[i][opt];
			if(a[i+1][opt] != mx && a[i+1][opt] != mn)a[i][!opt] = a[i+1][opt];
		}
		opt = !opt;
		l++,r--;
	}
	cout<<a[l][opt];
	return 0;
}
