#include<bits/stdc++.h>
using namespace std;
int t,n,c,b,a[106],cost;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cost = 0;
		cin>>n>>c;
		for(int i = 1;i <= n;i++){
			cin>>b;
			a[b]++;
		}
		for(int i = 1;i <= 101;i++){
			cost += min(c,a[i]);
		}
		cout<<cost<<endl;
	}
	return 0;
}

