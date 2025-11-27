#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<int> vi;
typedef pair<int,int> pi;

const int N=1005,mod=998244353,i3=(mod+1)/3;
void chmax(int &x,const int &y){
	if(y>x){
		x=y;
	}
}
int n,m;
vector<array<int,4>> E;
int ans;
void solve(vector<array<int,4>> &ed){
	sort(ed.begin(),ed.end(),[](array<int,4>A,array<int,4>B){return A[3]<B[3];});
	m=ed.size();
	vi lis[2]{{1,n+1},{1,n+1}};
	rep(i,0,m-1){
		lis[0].pb( ed[i][0]+1 );
		lis[0].pb( ed[i][2] );
		lis[1].pb( ed[i][1]+1 );
		lis[1].pb( ed[i][3] );
	}
	rep(i,0,1){
		sort(lis[i].begin(),lis[i].end());
		lis[i].erase(unique(lis[i].begin(),lis[i].end()),lis[i].end());
		rep(j,0,m-1){
			ed[j][i]=upper_bound(lis[i].begin(),lis[i].end(),ed[j][i])-lis[i].begin()-1;
			ed[j][i+2]=lower_bound(lis[i].begin(),lis[i].end(),ed[j][i+2])-lis[i].begin();
		}
	}
	int cn=(int)lis[0].size()-2,cm=(int)lis[1].size()-2;
	vector<vi> f(m,vi(m,-1));
	rep(i,0,m-1){
		f[i][i]=0;
		rep(j,i,m-1){
			if(f[i][j]==-1){
				continue;
			}
			rep(k,i+1,m-1){
				if(ed[j][2]<=ed[k][0] && ed[j][3]<=ed[k][1]){
					chmax(f[i][k],f[i][j]+1);
				}
			}
		}
	}
	vector<vi> a(m),b(cm+1);
	rep(i,0,m-1){
		cerr<<ed[i][1]<<" pb "<<i<<endl;
		b[ed[i][1]].pb(i);
	}
	rep(i,0,cn){
		vi g(m,-1);
		int cnt=0;
		per(j,cm,0){
			int sz=(lis[0][i+1]-lis[0][i])*(lis[1][j+1]-lis[1][j])%mod;
			for(int id:b[j]){
				if(ed[id][0]>=i){
					rep(k,id,m-1){
						cerr<<k<<" got from "<<id<<endl;
						chmax(g[k],f[id][k]);
					}
					cnt++;
				}
			}
			rep(k,0,cnt-1){
				a[k].clear();
			}
			rep(k,0,m-1){
				cerr<<k<<" f "<<g[k]<<endl;
				if(g[k]!=-1){
					a[g[k]].pb(k);
				}
			}
			rep(k,0,cnt-1){
				if(a[k].empty()){
					break;
				}
				int mn=n+1,pre=0,cur=0;
				for(int id:a[k]){
					int x=lis[0][ ed[id][2] ],y=lis[1][ ed[id][3] ];
					cur+=(y-pre)*(n-mn+1);
					pre=y;
					mn=min(mn,x);
				}
				cur+=(n+1-pre)*(n-mn+1);
				(ans+=cur%mod*sz)%=mod;
			}
		}
	}
}
signed main(){
	freopen("path/path1.in","r",stdin);
//	freopen("path.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>m>>n;
	E.resize(m);
	vector<array<int,4>> ed0,ed1;
	for(auto &x:E){
		rep(i,0,3){
			cin>>x[i];
		}
		if(x[0]>x[2]){
			swap(x[0],x[2]);
			swap(x[1],x[3]);
		}
		if(x[1]<x[3]){
			ed0.pb(x);
		}
		else{
			x[1]=n+1-x[1],x[3]=n+1-x[3];
			ed1.pb(x);
		}
	}
	solve(ed0);
	solve(ed1);
	int ans0=((n*n%mod*n-n)%mod+mod)%mod*n%mod*n%mod*i3%mod;
	ans=(ans0-ans+mod)%mod;
	cout<<ans<<endl;
	return 0;
}
