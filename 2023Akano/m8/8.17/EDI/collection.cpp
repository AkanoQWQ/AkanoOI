#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 20;
const int MAXS = (1<<18) + 1018 + 1108;
const ll INF = 1e18;
ll e[MAXN][MAXN],value[MAXN],n,m,q;
inline void ReadIn(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			e[i][j] = INF;
		}
	}
	for(int i = 1;i <= n;i++)cin>>value[i];
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u][v] = w;//f
	}
	return ;
}
inline void Floyd(){
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				e[i][j] = min(e[i][j],e[i][k] + e[k][j]);
			}
		} 
	}
	return ;
}
struct Segment{
	ll k,b;
	Segment(){}
	Segment(ll _k,ll _b){k = _k,b = _b;}
};
bool Cmp4Segment(Segment seg1,Segment seg2){
	if(seg1.k != seg2.k)return seg1.k < seg2.k;
	return seg1.b < seg2.b;//OK?????
}
struct Space{
	vector<Segment> segments;
	double point[MAXS];
	Segment seg[MAXS];
	int tail;
	inline double GetPoint(Segment seg1,Segment seg2){
		if(seg1.k == seg2.k){
			return (seg1.b > seg2.b) ? -INF : INF;//OK????????
		}
		return double(seg2.b - seg1.b) / double(seg1.k - seg2.k);//OK?????
	}
	inline void Calc(){
		sort(segments.begin(),segments.end(),Cmp4Segment);
		tail++;
		point[tail] = -1e18,seg[tail] = Segment(0,0);
		for(auto now : segments){
			while(tail > 1 && GetPoint(now,seg[tail]) < point[tail])tail--;
			tail++;
			point[tail] = GetPoint(now,seg[tail-1]),seg[tail] = now;
		}
		return ;
	}
	inline ll GetAns(ll x){
		int choice = lower_bound(point+1,point+tail+1,x) - point - 1;
		return seg[choice].k * x + seg[choice].b;
	}
}spc[MAXN];

ll sum[MAXS],f[MAXS][MAXN];
inline void DP(){
	int maxs = (1<<n) - 1;
	for(int i = 0;i <= maxs;i++){
		for(int j = 1;j <= n;j++){
			f[i][j] = INF;
		}
	}
	for(int i = 1;i <= n;i++){
		f[1<<(i-1)][i] = 0;
	}
	for(int stat = 1;stat <= maxs;stat++){
		for(int v = 1;v <= n;v++){
			if(!(stat & (1<<(v-1))))continue;
			sum[stat] += value[v];
			int lst = stat - (1<<(v-1));
			for(int u = 1;u <= n;u++){
				if(!(lst & (1<<(u-1))))continue;
				if(e[u][v] >= INF)continue;
				f[stat][v] = min(f[stat][v],f[lst][u] + sum[lst] * e[u][v]);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int stat = 1;stat <= maxs;stat++){
			if(!(stat & (1<<(i-1))))continue;
			spc[i].segments.emplace_back(sum[stat],-f[stat][i]);
		}
		spc[i].Calc();
	}
	return ;
}
inline void Solve(){
	cin>>q;
	while(q--){
		ll s,ed;
		cin>>s>>ed;
		cout<<spc[ed].GetAns(s)<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	Floyd();
	DP();
	Solve();
	return 0;
}
