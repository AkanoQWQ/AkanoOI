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
int n = 100,v = 100;
const int MOD = (1<<30);
mt19937 rng(time(0));
int f[106],nowf;
int main(){
	freopen("P3188.in","w",stdout);
	v = MOD;
	cout<<n<<" "<<v<<endl;
	f[1] = f[2] = 1;
	nowf = MOD;
	for(int i = 1;i <= n;i++){
		cout<<nowf<<" "<<nowf+1<<endl;
		nowf >>= 1;
		if(nowf == 0)nowf = MOD;
	}
	cout<<-1<<" "<<-1<<endl;
	return 0;
}


