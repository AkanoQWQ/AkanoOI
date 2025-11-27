#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,c,i,t;
int main(){
	//freopen(".in","r",stdin);
	freopen("que.in","w",stdout);
	cin>>n>>m;
	cout<<n<<" "<<m<<endl;
	for(i = 0;i < 1923;i++){
		c = rand();
	}
	for(i = 0;i < n;i++){
		cout<<rand()%1000<<" ";
	}
	cout<<endl;
	for(i = 0;i < m;i++){
		l = 12,r = 1;
		while(l >= r){
			l = rand()%n;
			r = rand()%n;
		}
		cout<<l<<" "<<r<<" "<<rand()%1000<<endl;
	}
	return 0;
}

