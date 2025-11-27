#include<bits/stdc++.h>
using namespace std;
int n = 20000;
int main(){
	srand(time(0));
	//freopen(".in","r",stdin);
	freopen("sequence.in","w",stdout);
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		if(rand()%2)putchar('-');
		cout<<rand()%10000<<" ";
	}
	return 0;
}

