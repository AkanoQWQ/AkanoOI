#include<bits/stdc++.h>
using namespace std;
void wr(int inx){
	if(inx <= 0)return ;
	wr(inx / 10);
	putchar((inx%10) + '0');
	return ;
}
inline void write(int inx){
	if(inx < 0){
		putchar('-');
		inx = -inx;
	}
	wr(inx);
	putchar('\n');
	return ;
}
int main(){
	int a;
	while(cin>>a){
		write(a);
	}
    return 0;
}


