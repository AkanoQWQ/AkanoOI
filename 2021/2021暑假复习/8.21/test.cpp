#include<bits/stdc++.h>
using namespace std;
char a;
int i,j,n = 100000,k;
int main(){
	//freopen(".in","r",stdin);
	freopen("change.in","w",stdout);
	for(i = 0;i < 19242;i++){
		j = rand()%238194491;
	}
	for(i = 0;i < n;i++){
		j = rand()%1;
		if(j)k = rand()%26 + 97;
		if(!j)k = rand()%26 + 65;
		cout<<char(k); 
	}
	return 0;
}

