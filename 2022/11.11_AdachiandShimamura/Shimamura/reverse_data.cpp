#include<bits/stdc++.h>
using namespace std;
int n = 2000;
int main(){
	srand(time(0));
	freopen("reverse.in","w",stdout);
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		cout<<char(rand()%26+'a');
	}
	return 0;
}

