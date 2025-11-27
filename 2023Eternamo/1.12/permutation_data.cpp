#include<bits/stdc++.h>
using namespace std;
int t = 30,len = 10;
int main(){
	freopen("permutation.in","w",stdout);
	cout<<t<<endl;
	while(t--){
		for(int i = 1;i <= len;i++){
			cout<<i%10;
		}
		cout<<" "<<rand()%1000<<endl;
	}
	return 0;
}

