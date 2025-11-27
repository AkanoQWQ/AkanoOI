#include<bits/stdc++.h>
#include<AL/rander.h>
using namespace std;
int n = 1000;
int t = 4;
Rander rd(1,1e3); 
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("conqueror.in","w",stdout);
	cout<<t<<endl;
	while(t--){
		int a = randint(50,500),b = randint(50,500);
		cout<<n<<" "<<a<<" "<<b<<endl;
		for(int i = 1;i <= n;i++){
			cout<<rd()<<" ";
		}
		cout<<endl;
	} 
	return 0;
}

