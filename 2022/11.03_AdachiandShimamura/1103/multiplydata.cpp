#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>inline void read(T &x){
	x=0;
	char c=getchar();
	T ret=0;
	while(!isdigit(c))ret|=!(c^'-'),c=getchar();
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	if(ret)x=(~x)+1;
	return;
}
template<typename T>inline void print(T x){
	if(x<0)putchar('-'),x=(~x)+1;
	if(x>9)print(x/10);
	putchar((x-x/10*10)^48);
	return;
}
template<typename T>inline void wr1(T x){
	print(x);
	putchar(' ');
	return;
}
template<typename T>inline void wr2(T x){
	print(x);
	putchar('\n');
	return;
}
std::mt19937 rnd(time(0));
int main(){
	freopen("multiply.in","w",stdout);
	wr2(1);
	for(int t=1;t<=1;t++){
		wr2(10);
		for(int i=1;i<=10;++i){
			wr1(rnd()%1000+1);
		}
		putchar('\n');
	}
	return 0;
}

