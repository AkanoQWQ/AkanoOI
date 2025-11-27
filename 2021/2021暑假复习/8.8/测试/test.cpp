#include<bits/stdc++.h>
using namespace std;
int n,i,seed = 1034,c,a,b,m;
int main(){
	//freopen(".in","r",stdin);
	freopen("db.in","w",stdout);
	cin>>n>>m;
	cout<<n<<" "<<m<<endl;
	for(i = 0;i < seed;i++){
		c = rand()%seed;
	}
	for(i = 0;i < n;i++){
		a = rand()%n;
		b = rand()%n;
		while(a == b){
			b = rand()%n;
		}
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}

