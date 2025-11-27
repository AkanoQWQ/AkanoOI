#include<bits/stdc++.h>
using namespace std;
int n = 10,si = 60;
int main(){
	srand(time(0));
	freopen("substr.in","w",stdout);
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= si;j++)cout<<char(rand()%26 + 'A');
		cout<<endl;
	}
	return 0;
}

