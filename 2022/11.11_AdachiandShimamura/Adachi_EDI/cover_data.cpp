#include<bits/stdc++.h>
using namespace std;
int r = 2000,c = 2000;
int main(){
	freopen("cover.in","w",stdout);
	cout<<r<<' '<<c<<endl;
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= c;j++){
			cout<<".";
		}
		cout<<endl;
	}
	return 0;
}

