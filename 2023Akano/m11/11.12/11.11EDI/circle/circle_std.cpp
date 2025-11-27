#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool mst;
namespace iobuff{
	const int LEN=1000000;
	char in[LEN+5], out[LEN+5];
	char *pin=in, *pout=out, *ed=in, *eout=out+LEN;
	inline char gc(void)
	{
		return pin==ed&&(ed=(pin=in)+fread(in, 1, LEN, stdin), ed==in)?EOF:*pin++;
	}
	inline void pc(char c)
	{
		pout==eout&&(fwrite(out, 1, LEN, stdout), pout=out);
		(*pout++)=c;
	}
	inline void flush()
	{ fwrite(out, 1, pout-out, stdout), pout=out; }
	template<typename T> inline void scan(T &x)
	{
		static int f;
		static char c;
		c=gc(), f=1, x=0;
		while(c<'0'||c>'9') f=(c=='-'?-1:1), c=gc();
		while(c>='0'&&c<='9') x=10*x+c-'0', c=gc();
		x*=f;
	}
	template<typename T> inline void putint(T x, char div)
	{
		static char s[100];
		static int top;
		top=0;
		x<0?pc('-'), x=-x:0;
		while(x) s[top++]=x%10, x/=10;
		!top?pc('0'), 0:0;
		while(top--) pc(s[top]+'0');
		pc(div);
	}
}
using namespace iobuff;

const int N=3e6+5, mod=1e9+7;
int a[2*N], fa[2*N], siz[2*N];
int lst[2*N], nxt[2*N], h[1000005];
int find_fa(int x, int *fa){
	return x==fa[x]?x:fa[x]=find_fa(fa[x], fa);
}
void hb(int x, int y, int *fa, int *siz){
	x=find_fa(x, fa), y=find_fa(y, fa);
	if(x==y) return;
	if(x<y) swap(x, y);
	fa[y]=x;
	siz[x]+=siz[y];
}
vector<int> pos[1000005];
int pid[2*N];
int vis1[2*N], vis2[2*N], vs[1000005];
int no_use[2*N], no_cnt[1000005], q_vis[2*N];
int clnxt[2*N], clsiz[2*N];
int hbct[2*N];
int s[N];
int n;
bool check(int l, int r){
	memset(h, 0, sizeof(h));
	s[l]++, s[r+1]--;
	for(int i=l+1; i<=r-1; ++i){
		if(pos[a[i]][0]==i){
			s[pos[a[i]][1]]++, s[pos[a[i]][2]+1]--;
		}else if(pos[a[i]][1]==i){
			s[pos[a[i]][2]]++, s[pos[a[i]][3]+1]--;
		}else if(pos[a[i]][2]==i){
			s[pos[a[i]][0]]++, s[pos[a[i]][1]+1]--;
		}else{
			assert(0);
		}
	}
	for(int i=1; i<=6*n; ++i){
		s[i]+=s[i-1];
	}
	for(int i=1; i<=3*n; ++i){
		s[i]+=s[i+3*n];
		if(s[i]>1) return 0;
	}
	return 1;
}
bool med;
namespace bao{
	int a[105], b[105], c[105];
	vector<int> pos[105];
	int pid[105];
	int ans=0;
	bool check(){
		memset(c, 0, sizeof(c));
		for(int i=1; i<=n; ++i){
			int l=0, r=0;
			if(b[i]==0) l=pos[i][1], r=pos[i][2];
			if(b[i]==1) l=pos[i][2], r=pos[i][0]+3*n;
			if(b[i]==2) l=pos[i][0], r=pos[i][1];
			for(int i=l; i<=r; ++i){
				int j=i>3*n?i-3*n:i;
				c[j]++;
			}
		}
		for(int i=1; i<=3*n; ++i){
			if(c[i]>1) return 0;
		}
		return 1;
	}
	void dfs(int x){
		if(x==n+1){
			ans+=check();
			ans%=mod;
			return;
		}
		for(int i=0; i<3; ++i){
			b[x]=i;
			dfs(x+1);
		}
	}
	int main(){
		for(int i=1; i<=3*n; ++i){
			scan(a[i]);
			pos[a[i]].push_back(i);
			pid[i]=pos[a[i]].size()-1;
		}
		dfs(1);
		printf("%d\n", ans);
		return 0;
	}
}
int main(){
//	freopen("circle.in", "r", stdin);
//	freopen("circle.out", "w", stdout);
	scan(n);
	for(int i=1; i<=3*n; ++i){
		scan(a[i]);
		a[i+3*n]=a[i];
	}
	for(int i=1; i<=6*n; ++i){
		pos[a[i]].push_back(i);
		pid[i]=pos[a[i]].size()-1;
	}
	for(int i=1; i<=6*n; ++i){
		lst[i]=h[a[i]];
		nxt[h[a[i]]]=i;
		h[a[i]]=i;
	}
	for(int i=1, p=-1; i<=6*n; ++i){
		if(p>lst[i]){
			vis1[i]=1;
		}else if(lst[i]){
			p=max(p, lst[i]);
		}
	}
	for(int i=6*n, p=6*n+1; i>=1; --i){
		if((p!=6*n+1)&&(!nxt[i]||nxt[i]>p)){
			vis2[i]=1;
		}else if(nxt[i]){
			p=min(p, nxt[i]);
		}
	}
	for(int i=1; i<=3*n; ++i){
		vis1[i]|=vis1[i+3*n];
		vis2[i]|=vis2[i+3*n];
	}
	for(int i=1; i<=3*n; ++i){
		if(vis1[i]){
			no_use[nxt[i]]=1;
		}
	}
	for(int i=3*n+1; i<=6*n; ++i){
		if(vis2[i]){
			no_use[lst[i]]=1;
		}
	}
	for(int i=1; i<=3*n; ++i){
		no_use[i]|=no_use[i+3*n];
	}
	for(int i=1, p=-1; i<=6*n; ++i){
		if(p!=-1&&p>lst[i]){
			no_use[nxt[i]]=1;
		}
		if(no_use[i]){
			p=i;
		}
	}	
	for(int i=6*n, p=-1; i>=1; --i){
		if(p!=-1&&p<nxt[i]){
			no_use[lst[i]]=1;
		}
		if(no_use[i]){
			p=i;
		}
	}
	for(int i=1; i<=3*n; ++i){
		no_use[i]|=no_use[i+3*n];
		if(no_use[i]) no_cnt[a[i]]++;
	}
	queue<int> q;
	for(int i=1; i<=3*n; ++i){
		if(!no_use[i]&&no_cnt[a[i]]==2){
			q.push(i);
//			printf("push %d\n", i);
		}
	}
	for(int i=1; i<=6*n; ++i){
		clnxt[i]=i;
	}
	int ttg=0;
	while(!q.empty()){
		int x=q.front(); q.pop();
		if(q_vis[x]) continue;
		q_vis[x]=1;
		int l=0, r=0;
		if(pid[x]==0) l=pos[a[x]][1], r=pos[a[x]][2];
		if(pid[x]==1) l=pos[a[x]][2], r=pos[a[x]][3];
		if(pid[x]==2) l=pos[a[x]][0], r=pos[a[x]][1];
		for(int i=l+1; i<=r-1; ){
			int p=i>3*n?i-3*n:i;
			if(!no_use[p]){
				for(int i=0; i<3; ++i){
					if(!no_use[pos[a[p]][i]]&&pos[a[p]][i]!=p){
						no_use[pos[a[p]][i]]=1;
						no_cnt[a[p]]++;
					}
				}
//				printf("  push %d %d\n", p, a[p]);
				q.push(p);
			}else{
				ttg=1; //非法标记，答案为0 
				break;
			}
			int tp=i;
			i=find_fa(i, clnxt)+1;
			hb(tp, r, clnxt, clsiz);
		}
	}
	for(int i=1; i<=3*n; ++i){
		if(no_cnt[i]==3) ttg=1;
	}
	if(ttg){
		puts("0");
		return 0;
	}
	int tag=0;
	for(int i=1; i<=3*n; ++i){
		if(no_cnt[a[i]]==0) tag=a[i];
		if(no_use[i]&&no_cnt[a[i]]==1){
			vs[a[i]]=i;
		}
	}
	if(tag){
		ll ans=0;
		for(int i=0; i<3; ++i){
			if(check(pos[tag][i], pos[tag][i+1])) ans++;
		}
		printf("%lld\n", ans);
		return 0;
	}
	for(int i=1; i<=n; ++i){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1, p=0; i<=6*n; ++i){
		if(vs[a[i]]){
			if(p){
				hb(p, a[i], fa, siz);
				hbct[p]++, hbct[a[i]]++;
			}
			if(pos[a[i]][0]==vs[a[i]]&&pos[a[i]][2]==i) p=a[i];
			if(pos[a[i]][1]==vs[a[i]]&&pos[a[i]][0]==i) p=a[i];
			if(pos[a[i]][2]==vs[a[i]]&&pos[a[i]][1]==i) p=a[i];
			if(p==a[i]&&pos[a[i]][0]==vs[a[i]]&&pos[a[i]][4]==i) p=0;
			if(p==a[i]&&pos[a[i]][1]==vs[a[i]]&&pos[a[i]][2]==i) p=0;
			if(p==a[i]&&pos[a[i]][2]==vs[a[i]]&&pos[a[i]][3]==i) p=0;
		}
	}
	int ct=0;
	for(int i=1; i<=n; ++i){
		if(vs[i]&&find_fa(i, fa)==i){
			ct++;
		}
	}
	ll ans=1, tg=0;
	if(!tg){
		for(int i=1; i<=n; ++i){
			if(vs[i]&&find_fa(i, fa)==i){
				ans=ans*(siz[i]+1)%mod;
				//			printf("%d\n", siz[i]);
			}
		}
	}
	printf("%lld\n", ans);
	flush();
	return 0;
}
