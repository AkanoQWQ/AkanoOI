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

const int INF = 0x7fffffff / 2 - 1;
int dis[14][14][506][506];
int main(){
	//freopen(".in","r",stdin);
	for(int _1 = 1;_1 <= 9;_1++){
		for(int _2 = 1;_2 <= 9;_2++){
			for(int _3 = 1;_3 <= 500;_3++){
				for(int _4 = 1;_4 <= 500;_4++){
					dis[_1][_2][_3][_4] = INF;//-1 ? INF ? 
				}
			}
		}
	}
	return 0;
}

