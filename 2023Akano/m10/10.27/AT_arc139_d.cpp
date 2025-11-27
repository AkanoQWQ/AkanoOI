#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 1018 + 1108;
ll f[MAXN][MAXN];//数字i在第j的位置的方案数
ll n,m,k,x;
vector<ll> a;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k>>x;
	for(int i = 1,c;i <= n;i++){
		cin>>c;
		a.push_back(c);
	}
	sort(a.begin(),a.end());
	for(int i = 1;i <= n;i++){
		f[a[i-1]][i] = 1;
	}
	for(int nowk = 1;nowk <= k;nowk++){
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= n;j++){
				for(int nxt = 1;nxt <= m;nxt++){
					if(j == x){
						
						continue;
					}
					int nxtrk = j;
					if(j > x){
						nxtrk--;
					}
					if(i > nxt){
						nxtrk++;
					}else{
						nxtrk--;
					}
				}
			}
		}
	}
	return not(Akano loves pure__Elysia);
}
