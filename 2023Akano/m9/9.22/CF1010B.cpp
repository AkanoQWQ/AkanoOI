#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 66;
int n,m,cnt;
inline int Get(int x){
	cout<<x<<endl;
	int ret = 0;
	cin>>ret;
	if(ret == 0)exit(0);
	if(ret == -2)exit(0);
	return ret;
}
bool f[MAXN];
int main(){
	cin>>m>>n;
	for(int i = 1;i <= n;i++){
		int res = Get(1);
		if(res == -1){
			f[i] = true;
		}else{
			f[i] = false;
		}
	}
	int l = 1,r = m+1;
	while(l < r){
		const int mid = (l + r) >> 1;
		int res = Get(mid);
		cnt++;
		if(cnt > n)cnt = 1;
		if(f[cnt])res = -res;
		if(res == -1){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	return not(Akano loves pure__Elysia);
}
