#include<bits/stdc++.h>
using namespace std;
const int INF = 1<<30;
int k,n;
double numone,num;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>k;
	numone = 1.0;
	for(n = 1;n <= INF;n++){
		num += numone/double(n);
		if(num > k){
			cout<<n;
			return 0;
			break;
		}
	}
	return 0;
}

