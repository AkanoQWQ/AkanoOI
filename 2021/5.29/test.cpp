#include<bits/stdc++.h>
using namespace std;
int i,a,b,n;
int main(){
	freopen("orange.in","w",stdout);
	int randnum = 1234897;
	cin>>n;
	cout<<n<<endl;
	for(i = 0;i < randnum;i++){
		rand();
	}
	for(i = 0;i < n;i++){
		cout<<rand()%100<<" ";
	}
	return 0;
}

