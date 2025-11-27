#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e4 + 1018 + 1108;
const int MAXSQT = 106;
const int MAXW = 2006 + 1018 + 1108 + 1000;
int n,w,k,a[MAXN],b[MAXN];
namespace Subtask1{
	const int INF = 1e9 + 2006 + 1018 + 1108;
	struct Package{
		int f[MAXW];
		int& operator[](int x){
			return f[x];
		}
		inline void Init(){
			for(int i = 0;i <= w;i++){
				f[i] = INF;
			}
			f[0] = 0;
			return ;
		}
		inline void Add(int _a,int _b){
			for(int i = w - _a;i >= 0;i--){
				f[i+_a] = min(f[i+_a],f[i] + _b);
			}
			return ;
		}
	}package[MAXSQT],mainBlk,now;
	int r = 0,nowl = 1,nowr = 0,belL[MAXSQT],belR[MAXSQT];
	int bel[MAXN],blk_len,blk_cnt;
	inline void Update(){
		mainBlk.Init();
		for(int i = nowl;i <= nowr;i++){
			mainBlk.Add(a[i],b[i]);
		}
		return ;
	}
	inline int BF(){
		int ans = n+2;
		for(int l = 1;l <= n;l++){
			now.Init();
			for(int r = l;r <= n;r++){
				now.Add(a[r],b[r]);
				if(now[w] <= k){
					ans = min(ans,r - l + 1);
					break;
				}
			}
		}
		if(ans == n+2)ans = -1;
		return ans;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>w>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i];
	}
	cout<<Subtask1::BF()<<endl;
	return not(Akano loves pure__Elysia);
}
