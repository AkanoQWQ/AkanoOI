#include<stdio.h>
unsigned long long a = 2;
inline void TEST(){
	a = (a * a) + a;
	if(a & 1)a = 2 * a;
	return ;
}
int n;
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		TEST();
	}
	TEST();
	for(int j = 1;j <= n;j *= 2){
		TEST();
	}
	return 0;
}
