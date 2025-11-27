#include<bits/stdc++.h>
using namespace std;
int n = 100;
bool used[200611];
const int mo = 1e5;
int main(){
	srand(time(0));
	freopen("desire.in","w",stdout);
	cout<<n<<endl;
	while(n--){
		int nm = rand()%mo + 1;
		//while(used[nm])nm = rand()%mo + 1;
		used[nm] = 1;
		cout<<nm<<" ";
	}
	return 0;
}

