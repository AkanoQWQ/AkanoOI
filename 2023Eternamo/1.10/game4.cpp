#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1006;
int n;
double f[2][MAXN][MAXN],ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	f[0][0][0] = 1<<n;
	for(int i = 0;i <= n;i++){
		const int mm = (i + 1) % 2;
		for(int j = 0;j <= n;j++){
			for(int k = 0;k <= n;k++){
				f[mm][j][k] = 0;
			}
		}
		for(int j = 0;j <= n;j++){
			for(int k = 0;k <= n;k++){
				//获得r
				f[(i+1)%2][j+1][k] += f[i%2][j][k] * 0.5;
				//获得l
				if(j > 0){
					f[(i+1)%2][j-1][k+1] += f[i%2][j][k] * 0.5;
				}else{
					f[(i+1)%2][0][k] += f[i%2][j][k] * 0.5;
				} 
				cout<<f[i%2][j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<"----------------"<<endl;
	}
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			ans += f[n%2][i][j] * (n - (2 * j));
		}
	}
	printf("%.3lf",ans / double(1<<n));
	return 0;
}
