#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5006;
int t = 3;
int n = 5000,q = 5000,a[MAXN];
int main(){
	srand(time(0));
	freopen("lonely.in","w",stdout);
	cout<<t<<endl;
	while(t--){
		cout<<n<<" "<<q<<endl;
		for(int i = 1;i <= n;i++){
			a[i] = i;
		}
		random_shuffle(a+1,a+n+1);
		for(int i = 1;i < n;i++){
			cout<<a[i]<<" "<<a[i+1]<<endl;
		}
		for(int i = 1;i <= q;i++){
			cout<<(rand()%2) + 1<<" "<<(rand()%n) + 1<<" "<<(rand()%n) + 1<<endl;
		}
		cout<<endl;
	}
	return 0;
}

