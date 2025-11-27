#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 30;
const int MAXS = (1<<24);
int n,x,a[MAXN],f[MAXS],c[MAXN],ans,cc[MAXN];
signed main(){
	freopen("t2.in","r",stdin);
//	freopen("t2.ans","w",stdout);
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		c[i+1] = i;
	}
	cin>>x;
	do{
		int cx = x;
		for(int i = 1;i <= n;i++){
			cx %= a[c[i]];
		}
		
		if(cx >= ans){
			for(int j = 1;j <= n;j++){
				cc[j] = c[j];
			}
		}
		ans = max(ans,cx);
	}while(next_permutation(c+1,c+n+1));
	cout<<ans;
	cout<<endl;
	for(int i = 1;i <= n;i++){
		cout<<cc[i]<<" ";
	}
	return 0;
}

