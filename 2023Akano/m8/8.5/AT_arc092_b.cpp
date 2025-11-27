#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
const int MAXV = (1<<28) + 1018 + 1108;
int n,a[MAXN],b[MAXN],c[MAXN],ans,mx;
inline int Read(){
	int ret = 0;//no f
	char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
// 	freopen("AT092.in","r",stdin);
	n = Read();
	for(int i = 1;i <= n;i++){
		a[i] = Read();
		mx = max(a[i],mx);
	}
	for(int i = 1;i <= n;i++){
		b[i] = Read();
		mx = max(b[i],mx);
	}
	sort(a+1,a+n+1);
	int maxw = log2(mx)+2;
	for(int w = 1;w <= maxw;w++){
		const int lower1 = 1<<(w-1),upper1 = (1<<w)-1;
		const int lower2 = (1<<w) + (1<<(w-1)),upper2 = (1<<(w+1))-1;
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			c[i] = b[i] % (1<<w);
		}
		sort(c+1,c+n+1);
		for(int i = 1;i <= n;i++){
			const int v = a[i] % (1<<w);
			int nowl = max(lower1 - v,0),nowr = upper1 - v;
			if(nowr >= nowl){
				cnt += upper_bound(c+1,c+n+1,nowr) - lower_bound(c+1,c+n+1,nowl);
			}
			nowl = max(lower2 - v,0),nowr = upper2 - v;
			if(nowr >= nowl){
				cnt += upper_bound(c+1,c+n+1,nowr) - lower_bound(c+1,c+n+1,nowl);
			}
		}
		if(cnt & 1){
			ans += 1<<(w-1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
