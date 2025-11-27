#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6; 
const int SZ = (1<<8) + 2;
int T,n,a[MAXN],s[MAXN];
int tr[SZ][2],ad[10],cnt;
inline int Check(int x){
	int len = 0;
	for(int i =8;i >= 1;i--)ad[i] = 0;
	while(x){
		ad[++len] = x & 1;
		x >>= 1;
	}
	int pos = 0,ret = 0;
	for(int i = 8;i >= 1;i--){
		if(tr[pos][!ad[i]] != 0){
			ret += (1<<(i-1));
			pos = tr[pos][!ad[i]];
		}else if(tr[pos][ad[i]] != 0){
			pos = tr[pos][ad[i]];
		}
	}
	return ret;
}
inline void Insert(int x){
	int len = 0;
	for(int i =8;i >= 1;i--)ad[i] = 0;
	while(x){
		ad[++len] = x & 1;
		x >>= 1;
	}
	int pos = 0;
	for(int i = 8;i >= 1;i--){
		if(tr[pos][ad[i]] == 0)tr[pos][ad[i]] = ++cnt;
		pos = tr[pos][ad[i]];
	}
	return ;
}
inline void Clear(){
	for(int i = 0;i <= cnt;i++){
		tr[i][0] = tr[i][1] = 0;
	}
	cnt = 0;
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		Clear();
		Insert(0);
		cin>>n;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			s[i] = s[i-1] ^ a[i];
			ans = max(ans,Check(s[i]));
			Insert(s[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
