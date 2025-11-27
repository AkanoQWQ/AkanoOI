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

int n = 9,h = 500,w = 500,cnt;
int main(){
	//freopen(".in","r",stdin);
	for(int len = 2;len <= n;len++){
		for(int l = 1;l + len - 1 <= n;l++){
			const int r = l + len - 1;
			for(int mid = l;mid < r;mid++){
				for(int _x = 1;_x <= h;_x++){
					for(int _y = 1;_y <= w;_y++){
						++cnt;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}

