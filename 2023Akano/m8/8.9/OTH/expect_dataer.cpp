#include<bits/stdc++.h>
using namespace std;
int n = 14;
double f[22][22];
const double RDM = RAND_MAX * 1.1;
int main(){
	srand(time(0));
	freopen("expect.in","w",stdout);
	printf("%d\n",n);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < i;j++){
			f[i][j] = f[j][i] = (double(rand()) / RDM);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(f[i][j] <= 1e-3){
				printf("0 ");
			}else{
				printf("%.3lf ",f[i][j]);
			}
			
		}
		printf("\n");
	}
	return 0;
}

