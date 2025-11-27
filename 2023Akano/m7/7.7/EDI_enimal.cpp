#include <bits/stdc++.h>
using std::cin;
using std::cout;
using LL = long long;
using ull = unsigned long long;
using ld = long double;

const int maxn = 1e6 + 10,mod = 1000000007;

char patt[maxn];
int len;

int pm[maxn];
LL ans[maxn];
void prekmp(){
	int j=0;
	for(int i=1;i<len;i++){
		while(j && patt[i]!=patt[j]) j=pm[j-1];
		j+=patt[i]==patt[j];
		pm[i]=j;
		ans[i]=ans[pm[i-1]]+1; // 向上跳 fail，累加起来 
	}
}

LL cnt;
void kmpplus(){
	int j=0;
	for(int i=0;i<len;i++){
		while(j && patt[i]!=patt[j]) j=pm[j-1];
		j+=patt[i]==patt[j];
		
		while(2*(j+1) >= i) j=pm[j-1];
		cnt=cnt*(ans[j]+1)%mod;
		
//		cout << ans[j] << ' ';
	}
}

int main() {
	std::ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(pm,0,sizeof(pm));
		memset(ans,0,sizeof(ans));
		cnt=1;
		ans[1]=1;
		cin >> patt;
		len=strlen(patt);
		prekmp();
		/// 
		kmpplus();
		cout << cnt << '\n';
	}
	return 0;
}

