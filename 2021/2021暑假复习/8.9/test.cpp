#include<bits/stdc++.h>
using namespace std;
int n,i,seed = 1982964,c,j;
int main(){
	//freopen(".in","r",stdin);
	freopen("tree.in","w",stdout);
	cin>>n;
	cout<<n<<endl;
	for(i = n;i < seed;i++){
		c = rand()%seed;
	}
	for(i = 0;i < n;i++){
		cout<<rand()%10000<<" "<<rand()%10000<<endl;
	}
	return 0;
}

