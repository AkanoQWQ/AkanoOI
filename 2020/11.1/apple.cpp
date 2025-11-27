#include<bits/stdc++.h>
using namespace std;
long long n,i,j,a[100000];
int main(){
	//freopen("apple.in","r",stdin);
	//freopen("apple.out","w",stdout);
	cin>>n;
	i = n;
	while(i >= 1){
		if(n % i == 0){
			cout<<n/i<<endl;
			j = n/i;
			i -= j;
		}else{
			i -= j;
		}
	}
	return 0;
}
