#include<bits/stdc++.h>
using namespace std;
int n,i,j,k;
char m[1006][1006];
int main(){
	//freopen(".in","r",stdin);
	freopen("count.in","w",stdout);
	cin>>n;
	cout<<n<<endl;
	for(i = 0;i < 1923;i++){
		k = rand()%1923; 
	}
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			k = rand()%3;
			if(k == 0){
				m[i][j] = '#';
			}else{
				m[i][j] = '.';
			}
		}
	}
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			cout<<m[i][j];
		}
		cout<<endl;
	}
	return 0;
}

