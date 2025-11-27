#include<bits/stdc++.h>
using namespace std;
int t;
char a[66][66];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		char ans = ' ';
		for(int i = 1;i <= 8;i++){
			for(int j = 1;j <= 8;j++){
				cin>>a[i][j];
			}
		}
		for(int i = 1;i <= 8;i++){
			int AA = 0;
			for(int j = 1;j <= 8;j++){
				AA += (a[j][i] == 'B');
			}
			if(AA == 8)ans = 'B';
		}
		for(int i = 1;i <= 8;i++){
			int BB = 0;
			for(int j = 1;j <= 8;j++){
				BB += (a[i][j] == 'R');
			}
			if(BB == 8)ans = 'R';
		}
		cout<<ans<<endl;
	}
	return 0;
}

