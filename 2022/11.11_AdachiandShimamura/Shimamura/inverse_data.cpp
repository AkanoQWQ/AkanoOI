#include<bits/stdc++.h>
using namespace std;
int n = 3e5;
int main(){
	srand(time(0));
	freopen("inverse.in","w",stdout);
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rand()%2<<" ";
	}
	return 0;
}

