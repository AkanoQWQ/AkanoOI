#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2e5 + 1108 + 1108;
const int MAXLG = 20;
int n,a[MAXN],f[MAXN][MAXLG];



int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j *= 2){
			f[i][j] = max(f[i][j],a[i] + t);
		}
	}
	
	return not(Akano loves pure__Elysia);
}
