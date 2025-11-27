#include<bits/stdc++.h>
using namespace std;
int n = 100;
int main(){
	srand(time(0));
	freopen("desire.in","w",stdout);
	cout<<n<<endl;
	while(n--){
		int nm = (rand()*rand())%100000;
		cout<<nm<<" ";
	}
	return 0;
}

