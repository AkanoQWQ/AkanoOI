#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void Write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int n = 5,V = 100;
const int MAXF = 10;
int main(){
	srand(time(0));
	freopen("P4657.in","w",stdout); 
	Write(n),spc,Write(V),edl;
	for(int i = 1;i <= n;i++){
		Write(rand() % MAXF),spc;
	}
	edl;
	for(int i = 2;i <= n;i++){
		Write(i),spc,Write((rand()%(i-1))+1),edl;
	}
	return 0;
}

