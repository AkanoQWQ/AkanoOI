#include<bits/stdc++.h>
using namespace std;
double r(){
	double rr = 2;
	while(rr > 1)rr = 1.0f * rand()/rand(); 
	return rr*1000;
}
int main(){
	srand(time(0));
	freopen("tran.in","w",stdout);
	for(int i = 1;i <= 2;i++){
		cout<<r()<<" "<<r()<<" "<<r()<<" "<<r()<<endl;
	}
	cout<<5<<" "<<4<<" "<<3;
	return 0;
}

