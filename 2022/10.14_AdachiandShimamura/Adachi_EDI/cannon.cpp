#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 250000;
const int defu = 600;
inline ll read(){
	ll x = 0, f = 1;
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
struct Cannon{
	ll a,d;
	bool available;
}c[506];
ll n,m,k,h[MAXN],tail,ans;
bool cmp4cannon(Cannon a,Cannon b){
	if(a.available == 0)return 0;
	if(b.available == 0)return 1;
	if(a.a != b.a)return a.a < b.a;
	return a.d < b.d;
}
int main(){
	freopen("cannon.in","r",stdin);
	freopen("cannon.out","w",stdout);
	n = read(),m = read(),k = read();
	for(int i = n;i >= 1;i--){
		h[i] = read();
	}
	for(int i = 1;i <= m;i++){
		c[i].a = read(),c[i].d = read();
		c[i].available = 1;
	}
	sort(c+1,c+m+1,cmp4cannon);
	for(int i = m;i >= 1;i--){
		for(int j = i-1;j >= 1;j--){
			if(c[j].d < c[i].d){
				c[j].available = 0;
			}
		}
	}
	sort(c+1,c+m+1,cmp4cannon);
	while(m >= 1 && c[m].available == 0)m--;
	c[0].a = 0;
	for(int i = 1;i <= n;i++){
		int l = 1,r = m+1,ret = defu,req = 0;
		while(l < r){
			int mid = (l+r) >> 1;
			if(mid >= m)mid = m;
			if(h[i] <= c[mid].a){
				ret = min(ret,mid);
				r = mid;
			}else{
				l = mid+1;
			}
		}
		if(ret == defu){
			break;
		}
		for(int j = ret;j >= 1;j--){
			while(j >= 1 && h[i] <= c[j-1].a)j--;
			if(j == 0)break;
			int res = (h[i] - c[j-1].a) / c[j].d;
			if(res * c[j].d < (h[i] - c[j-1].a))res++;
			h[i] -= res * c[j].d;
			req += res;
			if(h[i] <= 0)break;
		}
		if(k >= req){
			ans++;
			k -= req;
		}else{
			break;
		}
	}
	cout<<ans<<" "<<k;
	return 0;
}
