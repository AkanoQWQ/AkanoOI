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
const int MAXVAL = 1000;
int n = 1e5;
mt19937 rng(time(0));
int main(){
	freopen("P3647.in","w",stdout);
	cout<<n<<endl;
	for(int i = 2;i <= n;i++){
		const int v = (rng()%(i-1)) + 1;
		cout<<i<<" "<<v<<" "<<rng()%MAXVAL<<endl;
	}
	return 0;
}

