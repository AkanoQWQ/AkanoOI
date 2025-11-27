#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int MAXW = 14;
const int MAXSTAT = (1<<12) + 10 + 18 + 11 + 8;
const int MAXN = 2006 + 1018 + 1108 + 1000;
string str;
int n,step,maxs,res;
int pos[28][MAXN],postail[28],nowst[MAXN];
pii q[MAXN],nxt[MAXN];
int vis[MAXN][MAXN],qTail,nxtTail;
string ans;
mt19937 rng(time(0));
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>str;
	n = str.length();
	str = "." + str;
	for(int i = 1;i <= n;i++){
		pos[str[i] - 'a'][++postail[str[i] - 'a']] = i;
	}
	step = log2(n);
	maxs = (1<<step) - 1;
	res = n - maxs;
	q[++qTail] = {1,maxs};
	for(int i = 1;i <= res;i++){
		sort(q+1,q+qTail+1);
		nxtTail = 0;
		for(int ch = 0,st = 1;ch < 26;ch++){
		//	int st = 1;
			for(int nowi = 1,sameCnt = 0;nowi <= qTail;nowi++){
				int stTail = nxtTail;
				auto u = q[nowi];
				while(st <= postail[ch] && pos[ch][st] < u.first)st++;
				for(int it = st;it <= postail[ch];it++){
					const int j = pos[ch][it];
					if(((u.second & (j - u.first)) == (j - u.first))){
						if(vis[j+1][u.second - (j - u.first)] != i){
							vis[j+1][u.second - (j - u.first)] = i;
							nxt[++nxtTail] = {j+1,u.second - (j - u.first)};
						}
					}
					if(j > u.first + u.second)break;
				}
				if(nxtTail == stTail){
					sameCnt++;
				}else{
					sameCnt = 0;
				}
				if(sameCnt > 60)break;
			}
			cerr<<i<<" ch "<<ch<<" tail "<<nxtTail<<endl;
			if(nxtTail != 0){
				swap(q,nxt),swap(qTail,nxtTail);
				ans += 'a' + ch;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
