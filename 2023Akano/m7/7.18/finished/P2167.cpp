#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXS = (1<<15) + 1018;
const int MAXN = 20;
const int MAXLEN = 53;
const int MOD = 1000003;
int t,n,k,len;
ll f[MAXLEN][MAXS],ans;
string str[MAXN];
inline int BitCnt(int x){
	int ret = 0;
	while(x){
		ret += x & 1;
		x >>= 1;
	}
	return ret;
}
inline string Bit(int x){
	string ret;
	while(x){
		ret += '0' + (x & 1);
		x >>= 1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P2167.in","r",stdin);
	cin>>t;
	while(t--){
		cin>>n>>k;
		ans = 0;
		for(int i = 1;i <= n;i++){
			cin>>str[i];
		}
		len = str[1].length();
		for(int i = 0;i <= len;i++)memset(f[i],0,sizeof(f[i]));
		f[0][(1<<n)-1] = 1;
		for(int i = 0;i < len;i++){
			for(int s = 0;s < (1<<n);s++){
				if(f[i][s] == 0)continue;
				if(BitCnt(s) < k)continue;
				for(char c = 'a';c <= 'z';c++){
					int nxt = 0;
					for(int no = 1;no <= n;no++){
						nxt += (1<<(no-1)) * (str[no][i] == c || str[no][i] == '?');
					}
					nxt &= s;
					f[i+1][nxt] += f[i][s],f[i+1][nxt] %= MOD;
				}
			}
		}
		for(int i = 0;i < (1<<n);i++){
			if(BitCnt(i) != k)continue;
			ans = (ans + f[len][i]) % MOD;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

