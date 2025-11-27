#include<bits/stdc++.h>
#include<AL/main.h>
using namespace std;
namespace MAXSOLVE{
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
	int farr[MAXN];
	inline int Solve(){
		farr[0] = s,farr[1] = s;
		if(s >= t)return 0;
		int step = 0;
		for(int i = 1;i <= m;i++){
			if(h[i].id == nowid)continue;
			if(h[i].l > farr[step]){
				step++;
				farr[step+1] = farr[step];
				if(h[i].l > farr[step])return -1;
			}
			farr[step+1] = max(farr[step+1],h[i].r);
			if(h[i].r >= t)return step+1;
		}
		return -1;
	}
	void MySolve(){
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
		return ;
	}
}
int n = 1000,m = 50,q = 100;
Rander rd;
inline void Make(){
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i <= m;i++){
		int l = rd(1,n),r = rd(l,n);
		cout<<l<<" "<<r<<endl;
	}
	cout<<q<<endl;
	for(int i = 1;i <= q;i++){
		int l = rd(1,n),r = rd(l,n);
		cout<<rd(1,m)<<" "<<l<<" "<<r<<endl;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("cheat",1,200,Make,MAXSOLVE::MySolve);
	return 0;
}
