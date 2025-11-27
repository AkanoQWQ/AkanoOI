#include<bits/stdc++.h>
using namespace std;
int n = 50,m = 50,r = 2,c = 2;
int main(){
	srand(time(0) + 114);
	//freopen(".in","r",stdin);
	freopen("matrix.in","w",stdout);
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout<<rand()<<" ";
		}
		cout<<endl;
	}
	cout<<r<<" "<<c<<endl;
	return 0;
}

