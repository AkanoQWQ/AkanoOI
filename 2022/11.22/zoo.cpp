#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int MAXW = 70;
const int MAXN = 1e6 + 8;
const int MAXC = 1e8 + 6;
inline ull ull_read(){
	ull ret = 0,f = 1;
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
int n,m,c,k,p[MAXN],q[MAXN],two = 0;
bool able[MAXW],now[MAXW];
bitset<MAXC> have;
ull ans;
int main(){
//	freopen("zoo.in","r",stdin);
//	freopen("zoo.out","w",stdout);
	n = read(),m = read(),c = read(),k = read();
	for(int i = 1;i <= n;i++){
		ull inx = ull_read();
		int cnt = 0;
		while(inx > 0){
			now[cnt++] |= (inx & 1);
			inx >>= 1;
		}
	}
	for(int i = 1;i <= m;i++){
		p[i] = read(),q[i] = read();
		if(now[p[i]] == 1)have[q[i]] = 1;
	}
	for(int i = 0;i <= 64;i++)able[i] = 1;
	for(int i = 1;i <= m;i++){
		if(have[q[i]] == 0){
			able[p[i]] = 0;
		}
	}
	for(int i = 0;i < k;i++){
		if(able[i])two++;
	}
	if(two == 64 && n == 0){
		puts("18446744073709551616");
		return 0;
	}
	if(two == 0){
		puts("0");
	}else if(two == 64){
		ans = (1ull << 63);
		ans -= n;
		ans *= 2;
		ans += n;
		cout<<ans<<endl;
	}else{
		ans = 1;
		for(int i = 1;i <= two;i++){
			ans *= 2;
		}
		ans -= n;
		cout<<ans<<endl;
	}
	return 0;
}
