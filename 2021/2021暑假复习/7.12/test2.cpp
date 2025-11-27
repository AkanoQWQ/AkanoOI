#include<bits/stdc++.h>
using namespace std;
int n,k,i,c,t = 1,l,q,aa,bb;
int main(){
	//freopen("maxm.in","r",stdin);
	freopen("hotel.in","w",stdout);
	cin>>n>>l>>q;
	cout<<n<<endl;
	for(i = 0;i < 12823;i++){
		c = rand();
	}
	for(i = 0;i < n;i++){
		t += rand()%int(0.7 * l);
		t++;
		cout<<t<<" "; 
	}
	cout<<endl<<l<<endl<<q<<endl;
	for(i = 0;i < q;i++){
		aa = rand()%n;
		bb = rand()%n;
		while(aa ==bb){
			aa = rand()%n;
		}
		cout<<aa<<" "<<bb<<endl;
	}
	return 0;
}

