#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
constexpr int MAXM = 516;
constexpr ll INF = 1e16;
constexpr int MOD = 998244353;
constexpr int inv3 = 332748118;
struct Position;
struct Rectangle;
using Pos = Position;
using Rect = Rectangle;
template<typename T>
inline void Update(T& upd,T val){
	upd = max(upd,val);
	return ;
}
inline ll Sum(ll l,ll r){
	if(l > r)return 0;
	return ((r - l + 1) * (l + r) / 2) % MOD;
}

struct Position{
	int x,y;
	Position() = default;
	Position(int _x,int _y){
		x = _x,y = _y;
		return ;
	}
};
struct Rectangle{
	Position u,v;
	Rectangle() = default;
	Rectangle(Pos _l,Pos _r){
		u = _l,v = _r;
		return ;
	}
	Rectangle(int _lx,int _ly,int _rx,int _ry){
		u = Pos(_lx,_ly),v = Pos(_rx,_ry);
		return ;
	}
};
vector<Rect> edge1,edge2;
ll ans,m,n;
inline ll Solve(vector<Rect> edge){//不引用也不会有太多开销吧......
	ll ret = 0;
	static ll dp[MAXM][MAXM],f[MAXM];
	vector<int> xvec,yvec;
	for(auto e : edge){
		xvec.push_back(e.u.x+1),yvec.push_back(e.u.y+1);
		xvec.push_back(e.v.x),yvec.push_back(e.v.y);
	}
	xvec.push_back(1),xvec.push_back(n+1);
	yvec.push_back(1),yvec.push_back(n+1);
	sort(xvec.begin(),xvec.end()),sort(yvec.begin(),yvec.end());
	xvec.erase(unique(xvec.begin(),xvec.end()),xvec.end());
	yvec.erase(unique(yvec.begin(),yvec.end()),yvec.end());
	
	for(auto& e : edge){
		e.u.x = upper_bound(xvec.begin(),xvec.end(),e.u.x) - xvec.begin() - 1;
		e.u.y = upper_bound(yvec.begin(),yvec.end(),e.u.y) - yvec.begin() - 1;
		e.v.x = lower_bound(xvec.begin(),xvec.end(),e.v.x) - xvec.begin();
		e.v.y = lower_bound(yvec.begin(),yvec.end(),e.v.y) - yvec.begin();
//		cerr<<e.u.x<<","<<e.u.y<<" and "<<e.v.x<<","<<e.v.y<<endl;
	}
	int a = int(xvec.size()) - 1,b = int(yvec.size()) - 1,siz = edge.size();
	for(int i = 0;i <= m;i++){
		for(int j = 0;j <= m;j++){
			dp[i][j] = -INF;
		}
	}
	for(int i = 0;i < siz;i++){
		dp[i][i] = 0;
		for(int nxt = i;nxt < siz;nxt++){
			for(int obj = i+1;obj < siz;obj++){
				if(edge[nxt].v.x < edge[obj].u.x && edge[nxt].v.y < edge[obj].u.y){
					Update(dp[i][obj],dp[i][nxt] + 1);
				}
			}
		}
	}
//	for(int i = 0;i < siz;i++){
//		for(int j = 0;j < siz;j++){
//			cerr<<dp[i][j]<<" ";
//		}
//		cerr<<endl;
//	}
	vi offline[MAXM],save[MAXM];
	for(int i = 0;i < siz;i++){
//		cerr<<edge[i].u.y<<" pb "<<i<<endl;
		offline[edge[i].u.y].push_back(i);
	}
	for(int i = 0;i < a;i++){
		for(int j = 0;j <= b;j++)f[j] = -INF;
		int turn = 0;
		for(int j = b-1;j >= 0;j--){
			ll nowsize = ((xvec[i+1] - xvec[i]) * (yvec[i+1] - yvec[i])) % MOD;
			for(auto k : offline[j]){
//				cerr<<edge[k].u.x<<" compare "<<i<<endl;
				if(edge[k].u.x >= i){
					for(int nxt = k;nxt < siz;nxt++){
						Update(f[nxt],dp[k][nxt]);
					}
					turn++;
				}
			}
			for(int k = 0;k <= turn;k++)save[k].clear();
			for(int k = 0;k < siz;k++){
//				cerr<<k<<" f "<<f[k]<<endl;
				if(f[k] >= 0){
					save[f[k]].push_back(k);
				}
			}
			for(int k = 0;k < turn;k++){
				ll farpos = n + 1,lst = 0,delta = 0;
				for(auto p : save[k]){
					delta += (n + 1 - farpos) * (yvec[edge[p].v.y] - lst);
					delta %= MOD;
					lst = yvec[edge[p].v.y];
					farpos = min(farpos,ll(xvec[edge[p].v.x]));
				}
				delta += (n + 1 - farpos) * (n + 1 - lst);
				ret = (ret + delta * nowsize) % MOD;
			}
		}
	}
//	cerr<<"ret "<<ret<<endl;
	return ret;
}
inline ll Calc(){
	ll p2 = (n*n) % MOD,p3 = (((n*n) % MOD) * n) % MOD;
	ll ret = (p3 - n + MOD) % MOD;
	ret = (ret * p2) % MOD;
	ret = (ret * inv3) % MOD;
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	cin>>m>>n;
	for(int i = 1;i <= m;i++){
		Rect nowedge;
		cin>>nowedge.u.x>>nowedge.u.y>>nowedge.v.x>>nowedge.v.y;
		if(nowedge.u.x > nowedge.v.x)swap(nowedge.u,nowedge.v);
		if(nowedge.u.y < nowedge.v.y){
			edge1.push_back(nowedge);
		}else{
			//Reverse
			nowedge.u.y = n + 1 - nowedge.u.y;
			nowedge.v.y = n + 1 - nowedge.v.y;
			edge2.push_back(nowedge);
		}
	}
	ans = Calc();
	ans -= Solve(edge1),ans -= Solve(edge2);
	ans = (ans + MOD + MOD) % MOD;
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
