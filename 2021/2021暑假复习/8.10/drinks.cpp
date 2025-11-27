#include<bits/stdc++.h>
using namespace std;
long long c1,m1,c2,m2,c3,m3,i;
int main(){
	freopen("drinks.in","r",stdin);
	freopen("drinks.out","w",stdout);
	cin>>c1>>m1>>c2>>m2>>c3>>m3;
	for(i = 0;i < 100;i++){
		if(i%3 == 0){
			if(m1 >= (c2 - m2)){
				m1 -= (c2 - m2);
				m2 = c2;
			}else{
				m2 += m1;
				m1 = 0;
			}
		}
		if(i%3 == 1){
			if(m2 >= (c3 - m3)){
				m2 -= (c3 - m3);
				m3 = c3;
			}else{
				m3 += m2;
				m2 = 0;
			}
		}
		if(i%3 == 2){
			if(m3 >= (c1 - m1)){
				m3 -= (c1 - m1);
				m1 = c1;
			}else{
				m1 += m3;
				m3 = 0;
			}
		}
	}
	cout<<m1<<endl<<m2<<endl<<m3;
	return 0;
}

