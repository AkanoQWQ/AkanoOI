#include<bits/stdc++.h>
using namespace std;
long long n,i,c,seed = 19842;
int main(){
	//freopen(".in","r",stdin);
	freopen("board.in","w",stdout);
	cin>>n;
	for(i = 0;i < (n+seed) * 13;i++){
		c = rand() % (n+1);
	}
	cout<<n<<endl;
	for(i = 0;i < n;i++){
		cout<<rand()%1000000000<<" "; 
	}
	return 0;
}

