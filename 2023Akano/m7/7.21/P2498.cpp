#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3006;
const double EPS = 1e-6;
int q,n,m,fa[MAXN];
int GetFa(int x){
	if(fa[x] == x)return x;
	return fa[x] = GetFa(fa[x]);
} 
bool GetW[MAXN],GetX[MAXN],GetA[MAXN],GetD[MAXN];//WAXD in keyborad
inline double P(double inx){
	return inx * inx;
}
struct Monster{
	int x,y;	
}mon[MAXN];
inline bool Judge(double k){
	for(int i = 1;i <= q;i++){
		fa[i] = i;
		GetW[i] = GetX[i] = GetA[i] = GetD[i] = false;
		if(P(mon[i].x - 1) < k){
			GetX[i] = true;
		}
		if(P(n - mon[i].x) < k){//n or m?
			GetW[i] = true;
		}
		if(P(mon[i].y - 1) < k){
			GetA[i] = true;
		}
		if(P(m - mon[i].y) < k){//n or m?
			GetD[i] = true;
		}
	}
	for(int i = 1;i <= q;i++){
		for(int j = i+1;j <= q;j++){
			if(P(mon[i].x - mon[j].x) + P(mon[i].y - mon[j].y) < k*4){
				const int u = GetFa(i),v = GetFa(j);
				fa[u] = v;
			}
		}
	}
	for(int i = 1;i <= q;i++){
		fa[i] = GetFa(i);
		GetW[fa[i]] |= GetW[i],GetA[fa[i]] |= GetA[i];
		GetX[fa[i]] |= GetX[i],GetD[fa[i]] |= GetD[i];
	}
	for(int i = 1;i <= q;i++){
		if(GetW[i] && GetX[i])return false;
		if(GetA[i] && GetD[i])return false;
		if(GetA[i] && GetX[i])return false;
		if(GetW[i] && GetD[i])return false;
	}
	return true;
}
inline double Solve(){
	double l = 0,r = P(n) + P(m) + 1,ret = 0;
	while(r - l >= EPS){
		const double mid = (l + r) / 2;
		if(Judge(mid)){
			ret = mid;
			l = mid + EPS;
		}else{
			r = mid;
		}
	}
	return sqrt(ret);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>q>>n>>m;
	for(int i = 1;i <= q;i++){
		cin>>mon[i].x>>mon[i].y;
	}
	cout<<fixed<<setprecision(2)<<Solve()<<endl;
	return 0;
}

