#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e6 + 7;
inline int read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
int n,m,a[MAXN];
bool judge(int x){
	ll sum = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] > x){
			sum += a[i] - x;
		}
	}
	return (sum >= m);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
	}
	int l = 0,r = 1e9 + 1,ret = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(judge(mid)){
			ret = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	printf("%d",ret);
	return 0;
}

