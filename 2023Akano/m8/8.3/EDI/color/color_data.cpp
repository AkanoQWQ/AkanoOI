#include<bits/stdc++.h>
#include "AL/rander.h"
using namespace std;
int n = 3,m = 3,q = 4;
int tms3 = 5;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<0<<endl;
	cout<<n<<" "<<m<<" "<<q<<endl;
	Rander rdx(1,n),rdy(1,m),rd(1,3);
	for(int i = 1;i <= q;i++){
		int nowx = rdx(),nowy = rdy();
		int typ = rd();
		if(typ == 3){
			--tms3;
			if(tms3 < 0){
				typ = rd(1,2);
			}
		}
		if(typ == 1){
			cout<<typ<<" "<<rdx()<<" "<<nowy<<" "<<rdx()<<" "<<nowy<<endl;
		}else if(typ == 2){
			cout<<typ<<" "<<nowx<<" "<<rdy()<<" "<<nowx<<" "<<rdy()<<endl;
		}else if(typ == 3){
			int mx = min(n - nowx,m - nowy);
			int delta = rd(0,mx);
			cout<<typ<<" "<<nowx<<" "<<nowy<<" "<<nowx+delta<<" "<<nowy+delta<<endl;
		}
	}
	return 0;
}

