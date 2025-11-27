#include<bits/stdc++.h>
using namespace std;
int len = 1000,k = 100;
int main(){
	srand(time(0));
	freopen("easy.in","w",stdout);
	for(int i = 0;i < len;i++){
		cout<<char(rand()%26 + 'a');
	}
	cout<<endl<<k;
	return 0;
}

