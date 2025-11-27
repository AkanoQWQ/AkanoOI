#include<bits/stdc++.h>
using namespace std;
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
int far[MAXN];
inline void Pre(){
	if(s >= t)return 0;
	int step = 0;
	for(int i = 1;i <= m;i++){
		if(h[i].id == nowid)continue;
		if(h[i].l > far[step]){
			step++;
			if(h[i].l > far[step])return ;
		}
		far[step+1] = max(far[step+1],h[i].r);
	}
	return ;
}
inline int Solve(){
	return step[];
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("data/cheat/ex_cheat3.in","r",stdin);
	freopen("cheat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		cin>>h[i].l>>h[i].r;
		h[i].id = i;
	}
	sort(h+1,h+m+1,Cmp);
	cin>>q;
	while(q--){
		cin>>nowid>>s>>t;
		cout<<Solve()<<endl;
	}
	return 0;
}
