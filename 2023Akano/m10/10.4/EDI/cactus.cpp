#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e4 + 1018 + 1108;
const int MAXSQT = 106;
const int MAXW = 2006 + 1018 + 1108 + 900;
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
	}mainBlk,now;
	int r = 0,nowl = 1,nowr = 0,blk_len;
	inline void Update(){
		mainBlk.Init();
		for(int i = nowl;i <= nowr;i++){
			mainBlk.Add(a[i],b[i]);
		}
		return ;
	}
	inline int Solve(){
		int ans = n+2;
		blk_len = sqrt(n);
		mainBlk.Init(),now.Init();
		for(int l = 1;l <= n;l++){
			if(l > nowl){//均摊sqrt(n)次,总共n*sqrt(n)*w
				nowl += blk_len;//在sub5中为10*sqrt(n)*w
				Update();
			}
			
			now = mainBlk;
			for(int i = l;i < min(nowl,r+1);i++){//每个l执行sqrt(n) 次,总共 n*sqrt(n)*w
				now.Add(a[i],b[i]);//在sub5中为10*sqrt(n)*w
			}
			while(r+1 <= n && now[w] > k){//均摊O(n) 次,总共 n*w
				r++;
				now.Add(a[r],b[r]);
			}
			if(now[w] > k){
				break;
			}
			ans = min(ans,r - l + 1);
			while(nowr < r){//均摊O(n) 次,总共 n*w
				nowr++;
				if(nowr >= nowl)mainBlk.Add(a[nowr],b[nowr]);
			}
		}
		if(ans == n+2)ans = -1;
		return ans;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("cactus.in","r",stdin);
	freopen("cactus.out","w",stdout);
	cin>>n>>w>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i];
	}
	cout<<Subtask1::Solve()<<endl;
	return not(Akano loves pure__Elysia);
}
