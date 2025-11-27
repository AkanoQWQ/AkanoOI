#include<bits/stdc++.h>
using namespace std;
int n = 5000,m = 5000;
int main(){
	srand(time(0));
	freopen("season.in","w",stdout);
	cout<<n<<" "<<m<<endl;
	while(m--){
		int a = 2,b = 1;
		int c = 2,d = 1;
		while(a > b){
			a = rand()%n + 1;
			b = rand()%n + 1;
		}
		while(c > d){
			c = rand()%n + 1;
			d = rand()%n + 1;
		}
		int w = rand();
		if(rand()%8 == 0)w = -w;
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<w<<endl;
	}
	return 0;
}

