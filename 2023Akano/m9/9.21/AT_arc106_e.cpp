#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXS = (1<<18) + 1018 + 1108;
const int MAXN = 24;
const int MAXD = 2 * 18 * 1e5 + 1018 + 1108;
int n,k,day,maxstat,a[MAXN],popset[MAXD],f[MAXS];
inline int popcnt(int x){
	return __builtin_popcount(x);
}
inline bool Judge(int x){
	for(int stat = 0;stat <= maxstat;stat++){
		f[stat] = 0;
	}
	for(int i = 1;i <= x;i++)f[popset[i]]++;
	for(int i = 1;i <= n;i++){
		for(int stat = 0;stat <= maxstat;stat++){
			if(not((stat >> (i-1)) & 1)){
				f[stat | (1<<(i-1))] += f[stat];
			}
		}
	}
	for(int i = 0;i <= maxstat;i++){
		if(x - f[maxstat ^ i] < popcnt(i) * k)return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	maxstat = (1<<n)-1;
	for(int i = 1;i <= n;i++)cin>>a[i];
	day = 2 * n * k;
	for(int i = 1;i <= day;i++){
		for(int j = 1;j <= n;j++){
			if(((i-1) / a[j]) % 2 == 0){
				popset[i] |= 1<<(j-1);
			}
		}
	}
	int l = 1,r = day + 1;
	while(l < r){
		const int mid = (l + r) >> 1;
		if(Judge(mid)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	cout<<r<<endl;
	return not(Akano loves pure__Elysia);
}
