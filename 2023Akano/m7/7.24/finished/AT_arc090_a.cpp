#include<bits/stdc++.h>
using namespace std;
const int MAXN = 106; 
int f[3][MAXN],a[3][MAXN],n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= 2;i++){
		for(int j = 1;j <= n;j++){
			cin>>a[i][j];
			f[i][j] = max(f[i-1][j],f[i][j-1]) + a[i][j];
		}
	}
	cout<<f[2][n]<<endl;
	return 0;
}
