#include<bits/stdc++.h>
using namespace std;
int m = 100,x,y;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&x);
	while(m < x){
		m *= 1.01;
		y++;
	}
	cout<<y;
	return 0;
}
