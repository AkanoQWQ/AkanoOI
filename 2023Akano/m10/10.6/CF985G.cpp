#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int MAXN = 2e5 + 1018 + 1108;
const int MAXM = 2e5 + 2006 + 1018 + 1108;
struct Edge{
	int u,v;
}e[MAXM];
vector<int> edge[MAXN];
ull ans;
ll a,b,c;
int n,m;
inline ull Sum(ull x,ull y){
	if(x > y)return 0;
	x--,y--;
	return (x + y) * (y - x + 1) / 2;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>a>>b>>c;
	for(int i = 1;i <= m;i++){
		cin>>e[i].u>>e[i].v;
		e[i].u++,e[i].v++;
		if(e[i].u > e[i].v)swap(e[i].u,e[i].v);//u < v
	}
	for(int i = 1;i <= n;i++){
		//作为 first
		ans += ull(a * (i-1)) * (ull(n-i) * (n-i-1) / 2);
		//作为 second
		ans += ull(b * (i-1)) * (ull(i-1) * (n-i));
		//作为 third
		ans += ull(c * (i-1)) * (ull(i-1) * (i-2) / 2);
	}
	//第一层容斥,三个中仅出现一条边
	for(int i = 1;i <= m;i++){
		const int u = e[i].u,v = e[i].v;
		//oth为first
		ans -= ull(u-1) * ((u-1) * b + (v-1) * c);
		ans -= Sum(1,u-1) * a;
		//oth为second
		ans -= ull(v-u-1) * ((u-1) * a + (v-1) * c);
		ans -= Sum(u+1,v-1) * b;
		//oth为third
		ans -= ull(n-v) * ((u-1) * a + (v-1) * b);
		ans -= Sum(v+1,n) * c;
	}
	//第二层容斥,三个中出现两条边,使用两条边的交点统计
	for(int u = 1;u <= n;u++){
		sort(edge[u].begin(),edge[u].end());
		ull preSmaller = 0,preBigger = 0,sufSmaller = 0,sufBigger = 0;
		for(auto v : edge[u]){
			sufBigger += (v > u);// * (v-1);
			sufSmaller += (v < u);// * (v-1);
		}
		for(auto v : edge[u]){
			sufBigger -= (v > u);// * (v-1);
			sufSmaller -= (v < u);// * (v-1);
			//v oth u	v考虑自己,oth由oth自己考虑,u在v这里考虑
			if(v < u){
				ans -= ull(v-1) * sufSmaller * a;//v考虑自己
				ans -= ull(u-1) * sufSmaller * c;//u在这里考虑
			}
			//v u oth	v考虑自己,u在这里考虑,oth由oth自己考虑
			if(v < u){
				ans -= ull(v-1) * sufBigger * a;//v考虑自己
				ans -= ull(u-1) * sufBigger * b;//u在这里考虑
			}
			//u v oth	u在这里考虑,v考虑自己,oth由oth自己考虑
			if(v > u){
				ans -= ull(u-1) * sufBigger * a;//u在这里考虑
				ans -= ull(v-1) * sufBigger * b;//v考虑自己
			}
			//oth v u	oth由自己考虑,v考虑自己,u被oth考虑
			if(v < u){
				ans -= ull(v-1) * preSmaller * b;//v考虑自己
			}
			//u oth v	u被oth考虑,oth由自己考虑,v考虑自己
			if(v > u){
				ans -= ull(v-1) * preBigger * c;//v考虑自己
			}
			//oth u v	oth考虑自己,u被oth考虑,v考虑自己
			if(v > u){
				ans -= ull(v-1) * preSmaller * c;//v考虑自己
			}
			
			preBigger += (v > u);// * (v-1);
			preSmaller += (v < u);// * (v-1);
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
