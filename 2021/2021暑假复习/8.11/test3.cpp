#include<bits/stdc++.h>
using namespace std;
int n = 1000,m = 1000000,i,j,s,t,w;
int main(){
	//freopen(".in","r",stdin);
	freopen("ticket.in","w",stdout);
	for(i = 0;i < 12983;i++){
		j = rand()%123;
	}
	cout<<n<<" "<<m<<endl;
	for(i = 1;i < m;i++){
		cout<<rand()%100000<<" ";
	}
	cout<<endl;
	for(i = 0;i < n;i++){
		t = rand()%m;
		s = max(t-(rand()%m),3);
		w = rand()%100000;
		cout<<s<<" "<<t<<" "<<w<<endl;
	}
	return 0;
}

