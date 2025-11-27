#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<int> vi;
typedef pair<int,int> pi;

const int N=1e5+5,M=N*4;
int n,m,q;
vector<pi> row[N],col[N];
void Input(){
	cin>>n>>m>>q;
	rep(i,1,q){
		int op,w,l,r;cin>>op>>w>>l>>r;
		if(op==0){
			row[w].pb(mp(l,r));
		}
		else{
			col[w].pb(mp(l,r));
		}
	}
}
void fix(vector<pi> &v){
	sort(v.begin(),v.end());
	int pre_l=0,pre_r=-1;
	vector<pi> nv;
	for(const pi &x:v){
		if(x.fi<=pre_r+1){
			pre_r=max(pre_r,x.se);
		}
		else{
			if(pre_l!=0){
				nv.pb(mp(pre_l,pre_r));
			}
			pre_l=x.fi,pre_r=x.se;
		}
	}
	if(pre_l!=0){
		nv.pb(mp(pre_l,pre_r));
	}
	swap(v,nv);
	nv.clear();
	vector<pi>().swap(nv);
}
void Getrow(){
	rep(i,1,m){
		fix(col[i]);
		for(const pi &x:col[i]){
			row[x.fi].pb(mp(i,i));
			row[x.se].pb(mp(i,i));
		}
		
	}
}
void Getcol(){
	rep(i,1,n){
//		cerr<<i<<" conSIZE "<<row[i].size()<<endl;
		fix(row[i]);
		for(const pi &x:row[i]){
//			if(i == 67){
//				cerr<<"have "<<x.fi<<","<<x.se<<endl;
//			}
//			cerr<<i<<","<<x.fi<<","<<x.se<<" cont "<<i<<endl;
			col[x.fi].pb(mp(i,i));
		}
	}
	rep(i,1,n-1){
		int pt=0;
		for(const pi &x:row[i]){
//			cerr<<i<<" use "<<x.fi<<","<<x.se<<endl;
			while(pt<(int)row[i+1].size() && row[i+1][pt].se<x.fi){
				pt++;
			}
			while(pt<(int)row[i+1].size() && row[i+1][pt].se<=x.se){
				col[ max(x.fi,row[i+1][pt].se) ].pb(mp(i,i+1));
//				cerr<<"second push "<<max(x.fi,row[i+1][pt].se)<<","<<i<<endl;
				pt++;
			}
			if(pt<(int)row[i+1].size() && row[i+1][pt].fi<=x.se){
				col[ max(x.fi,row[i+1][pt].fi) ].pb(mp(i,i+1));
//				cerr<<"third push "<<max(x.fi,row[i+1][pt].fi)<<","<<i<<endl;
			}
		}
	}
	rep(i,1,m){
		fix(col[i]);
	}
}
struct dsu{
	int fa[M];
	dsu(){iota(fa,fa+M,0);}
	int Find(int u){return u==fa[u]?u:fa[u]=Find(fa[u]);}
	bool Merge(int u,int v){
		u=Find(u),v=Find(v);
		if(u==v){
			return 0;
		}
		fa[u]=v;
		return 1;
	}
}S;
vector<pi> msg[N];
void Getmsg(){
	rep(i,1,m){
		for(const auto &x:col[i]){
			msg[x.fi].pb({i,1});
			msg[x.se+1].pb({i,-1});
		}
	}
}
void solve(){
	Getrow();
	Getcol();
//	for(int i = 1;i <= n;i++){
//		if(row[i].size())cerr<<i<<" sizeLR "<<row[i].size()<<endl;
//	}
//	for(int i = 1;i <= m;i++){
//		if(col[i].size())cerr<<i<<" sizeUD "<<col[i].size()<<endl;
//	}
	Getmsg();
	set<pi> st0{mp(-1,-1),mp(m+1,-1)};
	set<int> st1{1,m+1};
	int tot=0,ans=0;
	rep(i,1,n){
		for(const auto &x:msg[i]){
			if(x.se==1){
				ans++;
//				cerr<<x.fi<<" addans in "<<i<<endl;
				st0.insert(mp(x.fi,++tot));
				st1.insert({x.fi,x.fi+1});
			}
			else{
//				cerr<<x.fi<<" delete in "<<i<<endl;
				st0.erase(st0.lower_bound( mp(x.fi,-1) ));
			}
		}
		for(const auto &x:row[i]){
			int l=x.fi,r=x.se;
			l=max(1,l-1),r=min(m,r+1);
//			cerr<<l<<","<<r<<" size "<<st0.size()<<" and "<<st1.size()<<endl;
//			cerr<<x.fi<<","<<x.se<<" in "<<i<<" lr "<<l<<","<<r<<endl;
			assert(l<=r);
//			cerr<<"kolora ";
//			for(auto h : st1)cerr<<h<<",";
//			cerr<<endl;
			auto itl=st1.upper_bound(l),itr=st1.upper_bound(r);
//			cerr<<l<<","<<r<<" : "<<"itl "<<*itl<<" itr "<<*itr<<" ";
			for(auto it=itl;it!=itr;it++){
				auto R=st0.lower_bound( mp(*it,-1) ),L=prev(R);
				if(L->fi<l || R->fi>r){
//					cerr<<"check "<<L->fi<<" ?< "<<l<<" or "<<R->fi<<" ?> "<<r<<" and BREAK"<<endl;
					continue;
				}
//				cerr<<"merge "<<L->fi<<" and "<<R->fi<<" TRY dec ans "<<endl;
//				cerr<<"ids "<<L->se<<" and "<<R->se<<endl;
				bool res = S.Merge(L->se,R->se);
				ans-= res;
//				cerr<<"RESS "<<res<<endl;
			}
			itl++,itr--;
//			cerr<<*itl<<" and "<<*itr<<endl;
			if(*itl<*itr){
				st1.erase(itl,itr);
			}
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("canvas/canvas2.in","r",stdin);
	Input();
	solve();
	return 0;
}
