#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,c,a[1000006],b[1000006],i;
int main(){
	freopen("que.in","r",stdin);
	freopen("que.out","w",stdout);
	cin>>n>>m;
	for(i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(i = 0;i < m;i++){
		cin>>l>>r>>c;
		b[l] += c;
		b[r+1] -= c;
	}
	for(i = 1;i <= n;i++){
		b[i] += b[i-1];
		a[i] += b[i];
	}
	for(i = 1;i <= n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

