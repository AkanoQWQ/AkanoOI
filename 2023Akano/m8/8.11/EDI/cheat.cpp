#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXN = 2e5 + 1018 + 1108;
int n,m,q,nowid,s,t;
struct Hack{
	int l,r,id;
}h[MAXN];
bool Cmp(Hack h1,Hack h2){
	if(h1.l != h2.l)return h1.l < h2.l;
	if(h1.r != h2.r)return h1.r < h2.r;
	return h1.id < h2.id;
}
inline void ReadIn(){
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		cin>>h[i].l>>h[i].r;
		h[i].id = i;
	}
	return ;
}
int f[MAXN][20],g[MAXN][20],choice[MAXN][2],now1,now2,hl[MAXN],hr[MAXN];
inline void Pre(){
	sort(h+1,h+m+1,Cmp);
	int tail = 0;
	for(int i = 1;i <= n;i++){
		while(tail < m && h[tail+1].l <= i){
			++tail;
			if(h[tail].r >= h[now1].r){
				now2 = now1,now1 = tail;
			}else if(h[tail].r > h[now2].r){
				now2 = tail;
			}
		}
		f[i][0] = max(i,h[now1].r);
		g[i][0] = max(i,h[now2].r);
		choice[i][0] = h[now1].id,choice[i][1] = h[now2].id;
	}
	for(int i = n;i >= 1;i--){
		for(int j = 1;j <= 18;j++){
			f[i][j] = f[f[i][j-1]][j-1];
			g[i][j] = g[g[i][j-1]][j-1];
		}
	}
	for(int i = 1;i <= m;i++){
		hl[i] = n+1,hr[i] = 0;
	}
	for(int i = 1;i <= n;i++){
		const int now = choice[i][0];
		hl[now] = min(hl[now],i);
		hr[now] = max(hr[now],i);
	}
	return ;
}
bool flag;
inline pii Run(int l,int r,int nowf[MAXN][20]){
	if(l >= r)return make_pair(0,l);//?WHY
	int pos = l,cnt = 0;
	for(int i = 18;i >= 0;i--){
		if(nowf[pos][i] < r){
			cnt += (1<<i);
			pos = nowf[pos][i];
		}
	}
	if(pos != r){
		pos = nowf[pos][0];
		cnt += 1;
	}
	if(pos < r)return make_pair(-1,0);
	return make_pair(cnt,pos);
}
inline int Execute(){
	if(hl[nowid] > hr[nowid] || t < hl[nowid] || s > hr[nowid]){//≤ª ‹”∞œÏ 
		return Run(s,t,f).first;
	}else if(hl[nowid] <= s && t <= hr[nowid]){
		return Run(s,t,g).first;
	}else if(hl[nowid] <= s && s <= hr[nowid]){
		pii step1 = Run(s,hr[nowid]+1,g);
		pii step2 = Run(step1.second,t,f);
		if(step1.first == -1 || step2.first == -1)return -1;
		return step1.first + step2.first;
	}else if(hl[nowid] <= t && t <= hr[nowid]){
		pii step1 = Run(s,hl[nowid],f);
		pii step2 = Run(step1.second,t,g);
		if(step1.first == -1 || step2.first == -1)return -1;
		return step1.first + step2.first;
	}else if(s <= hl[nowid] && hr[nowid] <= t){
		pii step1 = Run(s,hl[nowid],f);
		pii step2 = Run(step1.second,hr[nowid]+1,g);
		pii step3 = Run(step2.second,t,f);
		if(step1.first == -1 || step2.first == -1 || step3.first == -1)return -1;
		return step1.first + step2.first + step3.first;
	}
	return 10181108;
}
inline void Solve(){
	cin>>q;
	for(int nowq = 1;nowq <= q;nowq++){
		cin>>nowid>>s>>t;
		cout<<Execute()<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("cheat.in","r",stdin);
	freopen("cheat.out","w",stdout);
	ReadIn();
	Pre();
	Solve();
	return 0;
}
