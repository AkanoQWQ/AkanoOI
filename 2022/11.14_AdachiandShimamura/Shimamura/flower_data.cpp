#include<bits/stdc++.h>
using namespace std;
int a = 100000,n = 4000,m = 4000;
int r(){
	return (rand()*rand());
}
int main(){
	freopen("flower.in","w",stdout);
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i <= n;i++){
		cout<<r()%a + 1<<" "; 
	}
	cout<<endl;
	while(m--){
		int lef = 2,rig = 1;
		cout<<1<<" "<<n<<" "<<r()%a + 1<<endl;
	}
	return 0;
}

