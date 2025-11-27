#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 30;
const int MAXS = (1<<24);
int n,x,a[MAXN],f[MAXS];
signed main(){
	freopen("t2.in","r",stdin);
//	freopen("t2.out","w",stdout);
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	
	memset(f,-1,sizeof(f));
	cin>>x;
	f[0] = x;
	for(int stat = 0;stat < (1<<n);stat++){
		if(f[stat] == -1)puts("ERR");
		for(int j = 0;j < n;j++){
			if(!(stat & (1<<j))){
				f[stat | (1<<j)] = max(f[stat | (1<<j)],f[stat] % a[j]);
			}
		}
	}
	cout<<f[(1<<n)-1];
	return 0;
}

