#include<bits/stdc++.h>
using namespace std;
const int n = 300006,s = 256,mo = 257;
int main(){
	freopen("arrangement.in","w",stdout);
	cout<<n<<endl<<s<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rand()%mo<<" "<<rand()%mo<<endl;
	}
	return 0;
}

