#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1006;
int n;
double f[2][MAXN][MAXN],ans;//49.475
int main(){
	freopen("game.in","r",stdin);
	cin>>n;
	f[0][0][0] = n;
	for(int i = 0;i <= n;i++){
		const int nw = i % 2;
		const int nxt = (i + 1) % 2;
		for(int j = 0;j <= n;j++){
			for(int k = 0;k <= n;k++){
				f[nxt][j][k] = 0;
			}
		}
		for(int j = 0;j <= n;j++){
			for(int k = 0;k <= n;k++){
				//获得r
				f[nxt][j+1][k] += f[nw][j][k] * 0.5;
				//获得l
				if(j > 0){
					f[nxt][j-1][k+1] += f[nw][j][k] * 0.5;
				}else{
					f[nxt][0][k] += f[nw][j][k] * 0.5;
				} 
//				cout<<f[nw][j][k]<<" ";
			}
//			cout<<endl;
		}
//		cout<<"----------------"<<endl;
	}
	const int nn = n % 2;
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			ans += f[nn][i][j] * (n - (2 * j));
		}
	}
	cout<<f[nn][0][0]<<" "<<f[nn][0][1]<<endl;
	cout<<f[nn][1][0]<<" "<<f[nn][1][1]<<endl;
	printf("%.3Lf",ans / (long double)(n));
	return 0;
}
