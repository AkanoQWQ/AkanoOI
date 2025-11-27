#include<bits/stdc++.h>
using namespace std;
const int MAXN = 506;
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch>'9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
struct Object{
	int c,z[MAXN];
}o[MAXN];
int p[MAXN],n,m,ans;
int main(){
	freopen("buyy.in","r",stdin);
	freopen("buyy.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			o[i].z[j] = read();
		}
	}
	for(int i = 1;i <= n;i++){
		o[i].c = read();
		ans += o[i].c;
		p[i] = i;
	}
	cout<<n<<" "<<ans<<endl;
	return 0;
}
