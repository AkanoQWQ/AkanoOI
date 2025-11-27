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
int g[16] = {0,22,23,24,25,26,27,28,29,334,555,999,1024,1942,2006,2023};
int main(){
	int T = 1e3;
	while(T--){
		int l = (rand()%10)+1,r = (rand()%3000)+1;
		if(l > r)swap(l,r);
		int BF = 0;
		for(int i = 1;i <= 15;i++){
			if(l <= g[i] && g[i] <= r){
				++BF;
			}
		}
		int ST = lower_bound(g+1,g+15+1,l) - g;
		int ED = upper_bound(g+1,g+15+1,r) - g - 1;
		int DELTA = ED - ST + 1;
		if(BF != DELTA){
			cout<<BF<<" ? "<<DELTA<<" in "<<l<<","<<r<<endl;
			cout<<ST<<" ~ "<<ED<<endl;
		}
	}
	
	return 0;
}


