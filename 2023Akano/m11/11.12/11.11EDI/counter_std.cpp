#include<bits/stdc++.h>
using namespace std;
using ll = long long;
namespace Solve{
	constexpr int N = 100020;
	constexpr int n = 1e5 + 9;
	bool gg[N][10];
	
	int dis[N][20];bool vis[N][20];
	struct Item{
		int x,i;
	};
	void spfa(){
		memset(dis,0x3f,sizeof dis);
		queue<Item>q;
		for(int i=0;i<=n;i++){
			dis[i][10]=0,vis[i][10]=1;
			q.push({i,10});
			
			for(int j=1;j<10;j++)
				if(gg[i][j]){
					dis[i][10-j]=1,vis[i][10-j]=1;
					q.push({i,10-j});
					dis[i][10+j]=1,vis[i][10+j]=1;
					q.push({i,10+j});
				}
		}
		while(q.size()){
			int x=q.front().x,i=q.front().i;q.pop();
			vis[x][i]=0;
			int z=x+i-10;
			for(int y=x-9;y<=x+9;y++)
				if(y>=0&&y<=n&&abs(z-y)<=9&&dis[y][x-y+10]+dis[x][i]<dis[y][z-y+10]){
					dis[y][z-y+10]=dis[y][x-y+10]+dis[x][i];
					if(!vis[y][z-y+10])vis[y][z-y+10]=1,q.push({y,z-y+10});
				}
			for(int y=z-9;y<=z+9;y++)
				if(y>=0&&y<=n&&abs(x-y)<=9&&dis[x][i]+dis[z][y-z+10]<dis[x][y-x+10]){
					dis[x][y-x+10]=dis[x][i]+dis[z][y-z+10];
					if(!vis[x][y-x+10])vis[x][y-x+10]=1,q.push({x,y-x+10});
				}
		}
	}
	
	inline void Min(int&x,int y){
		x=(x<y?x:y);
	}
	
	const int Log=20;
	int f[Log][10][N],g[Log][10][N];//go back
	
	void build(int dep,int l,int r){
		if(r-l<=9)return;
		int mid=(l+r)>>1;
		int L=mid-8,R=mid;
		if(L<l)L=l,R=l+8;
		
		for(int z=L;z<=R;z++){
			int *f=Solve::f[dep][z-L],*g=Solve::g[dep][z-L];
			f[z]=0;
			for(int i=z-1;i>=l;i--){
				for(int j=1;j<=9&&i+j<=z;j++){
					Min(f[i],f[i+j]+dis[i][10+j]);
				}
			}
			for(int i=z+1;i<=r;i++){
				for(int j=1;j<=9&&i-j>=z;j++){
					Min(f[i],f[i-j]+dis[i][10-j]);
				}
			}
			g[z]=0;
			for(int i=z-1;i>=l;i--){
				for(int j=1;j<=9&&i+j<=z;j++){
					Min(g[i],g[i+j]+dis[i+j][10-j]);
				}
			}
			for(int i=z+1;i<=r;i++){
				for(int j=1;j<=9&&i-j>=z;j++){
					Min(g[i],g[i-j]+dis[i-j][10+j]);
				}
			}
		}
		build(dep+1,l,L-1),build(dep+1,R+1,r);
	}
	
	int query(int dep,int l,int r,int x,int y,bool o){
		int mid=(l+r)>>1;
		int L=mid-8,R=mid;
		if(L<l)L=l,R=l+8;
		if(y<L){
			return query(dep+1,l,L-1,x,y,o);
		}
		if(x>R){
			return query(dep+1,R+1,r,x,y,o);
		}
		int ans=0x3f3f3f3f;
		if(!o){
			for(int z=L;z<=R;z++){
				int *f=Solve::f[dep][z-L],*g=Solve::g[dep][z-L];
				Min(ans,f[x]+g[y]);
			}
		}
		else{
			for(int z=L;z<=R;z++){
				int *f=Solve::f[dep][z-L],*g=Solve::g[dep][z-L];
				Min(ans,f[y]+g[x]);
			}
		}
		return ans;
	}
	void main(){
		for(int i=0;i<=n;i++){
			int x=i;
			while(x){
				gg[i][x%10]=1;
				x/=10;
			}
		}
		spfa();
//		for(int i=1;i<=9;i++)cerr<<dis[16][10+i]<<' ';cerr<<"D\n";
//		for(int i=1;i<=9;i++)cerr<<dis[26-i][10+i]<<' ';cerr<<"D\n";
		
		memset(f,0x3f,sizeof f);
		memset(g,0x3f,sizeof g);
		build(0,0,n);
		
		int T;cin>>T;
		int lst=0;
		while(T--){
			int x,y;cin>>x>>y;
			x^=(lst+1),y^=(lst+1);
			int ans=0;
			if(abs(y-x)<=9){
				ans=dis[x][y-x+10];
			}
			else{
				if(x<=y){
					ans=query(0,0,n,x,y,0);
				}
				else{
					ans=query(0,0,n,y,x,1);
				}
			}
			if(ans==0x3f3f3f3f){
				cout<<-1<<'\n';
				lst=-1;
			}
			else{
				cout<<ans<<'\n';
				lst=ans;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	Solve::main();
	
	return 0;
}
