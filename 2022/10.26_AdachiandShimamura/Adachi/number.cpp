#include<bits/stdc++.h>
using namespace std;
const int MAXX = 10002006;
bool sv[MAXX];
int ans[MAXX],t,x;
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
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i = 1;i <= 1e7 + 12;++i){
		if(sv[i])continue;
		int s = i;
		while(s){
			if(s % 10 == 7){
				sv[i] = 1;
				break;
			}
			s /= 10;
		}
		if(sv[i]){
			for(int j = 2 * i;j <= 1e7+12;j += i){
				sv[j] = 1;
			}
		}
	}
	for(int i = 1;i <= 1e7+2;++i){
		if(sv[i]){
			ans[i] = -1;
		}else{
			for(int j = i + 1;;j++){
				if(sv[j] == 0){
					ans[i] = j;
					break;
				} 
			}
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&x);
		write(ans[x]);
	}
    return 0;
}//为什么cin比起scanf要快的多??? 
//但是配合write就是scanf快 
