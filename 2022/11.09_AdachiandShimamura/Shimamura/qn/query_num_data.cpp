#include<bits/stdc++.h>
using namespace std;
int n = 10000,m = 400,q = 10000;
int main(){
	srand(time(0));
	freopen("qn.in","w",stdout);
	cout<<n<<" "<<q<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rand()%m<<" ";
	}
	cout<<endl;
	while(q--){
		int l = 9,r = 1;
		while(l > r){
			l = rand()%n + 1;
			r = rand()%n + 1;
		}
		cout<<l<<" "<<r<<endl;
	}
	return 0;
}

