#include<bits/stdc++.h>
using namespace std;
int n = 50;
int main(){
	srand(time(0));
	freopen("coin.in","w",stdout);
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rand()%3000 + 1 <<" ";
	}
	return 0;
}

