#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2006;
const int st = 100;
const int ad = 10;
int a[MAXN][MAXN];
int n = 300,m = 300,t = 10;
int main(){
	srand(time(0));
	freopen("potato.in","w",stdout);
	cout<<t<<endl;
	while(t--){
		cout<<n<<" "<<m<<endl;
		for(int i = 1;i <= n;i++){
			a[i][1] = rand()%st;
			for(int j = 2;j <= m;j++){
				a[i][j] = a[i][j-1] + (rand()%ad);
			}
		}
		int s = (rand()%m) + 1;
		int l = (rand()%m) + 1;
		if(rand()%2){
			for(int i = 1;i <= n;i++){
				swap(a[i][s],a[i][l]);
			}
		}else{
			for(int i = 1;i <= n;i++){
				swap(a[i][s],a[i][l]);
			}		
			s = (rand()%m) + 1;
			l = (rand()%m) + 1;	
			for(int i = 1;i <= n;i++){
				swap(a[i][s],a[i][l]);
			}		
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				printf("%d ",a[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}
