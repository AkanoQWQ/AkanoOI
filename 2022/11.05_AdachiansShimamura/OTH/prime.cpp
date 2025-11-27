#include<bits/stdc++.h>
using namespace std;
const int MAXP = 1e9;
const int MAXN = 1e5;
int pr[MAXN],cnt;
bool est[MAXP];
void sel(int n){
	for(int i = 1;i <= n;i++){
		est[i] = 1;
	}
	est[1] = 0;
	for(int i = 2;i <= n;i++){
		if(est[i]){
			pr[++cnt] = i;
			for(int j = 1;i+(j*i) <= n;j++){
				est[i+(j*i)] = 0;
			}
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	sel(1000);
	for(int i = 1;i <= cnt;i++){
		cout<<pr[i]<<" ";
	}
	return 0;
}

