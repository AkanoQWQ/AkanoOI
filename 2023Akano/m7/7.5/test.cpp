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
int cnts[22];
inline int Onenum(const int& _i){
	int ret = 0;
	for(int i = 0;i < 22;i++){
		if(_i & (1<<i)){
			++ret;
		}
	}
	return ret;
}
const int MAXSZ = 1e6 + 50000;
int Stat2Num[MAXSZ];
inline int Zip(int stat){
	if(Stat2Num[stat])return Stat2Num[stat];
	int num = Onenum(stat);
	int to = ++cnts[num];
	Stat2Num[stat] = to;
	return to;
}
int f[22];
int main(){
	memset(f,9,sizeof(f));
	cout<<f[0]<<"!";return 0;
	//freopen(".in","r",stdin);
	for(int i = 0;i < (1<<20);i++){
		Zip(i);
	}
	int ans = 0;
	for(int i = 0;i < 20;i++){
		ans = max(ans,cnts[i]);
	}
	cout<<ans;
	return 0;
}

