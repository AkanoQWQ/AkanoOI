#include<bits/stdc++.h>
using namespace std;
int n = 1e3,m = 114514;
int main(){
	int c = 0;
	freopen("a.in","w",stdout);
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i <= n;i++){
		cout<<c<<" ";
		c += rand();
	}
	return 0;
}

