#include<bits/stdc++.h>
using namespace std;
long long a = 200000,i,c[100000];
int main(){
	//freopen(".in","r",stdin);
	freopen("palindrome.in","w",stdout);
	cout<<a<<endl;
	for(i = 0;i < 100000;i++){
		c[i] = rand()%200000;
	}
	for(i = 0;i < a;i++){
		cout<<c[rand()%100000]<<" ";
	}
	return 0;
}

