#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 5e4 + 1018 + 1108;
const int maxTimes = 1006;
int nxt[MAXN],val[MAXN],n,x,start,lst,res = 1996;
inline void Query(int x){
	if(nxt[x])return ;
	res--;
	cout<<"? "<<x<<endl;
	cin>>val[x]>>nxt[x];
	return ;
}
unsigned long long BASE = 2006 + 10181108;
inline int rng(int l,int r){
	BASE ^= BASE >> 7;
	BASE ^= BASE << 19;
	BASE ^= BASE >> 11;
	BASE ^= BASE << 13;
	return ((BASE) % (r - l + 1)) + l;
}
mt19937 rd(time(0));
int main(){
	val[0] = -1;
	cin>>n>>start>>x;
	lst = start;
	Query(lst);
	vector<int> vec(n);
	for(int i = 0;i < n;i++)vec[i] = i+1;
	shuffle(vec.begin(),vec.end(),rd);
	for(int i = 0;i < min(maxTimes,n);i++){
		const int u = vec[i];
		Query(u);
		if(val[lst] < val[u] && val[u] <= x){
			lst = u;
		}
	}
	int u = lst;
	while(res >= 0 && u > 0){
		if(val[u] >= x)break;
		const int v = nxt[u];
		if(v == -1)break;
		Query(v);
		if(val[v] < x){
			u = v;
		}else{
			u = v;
			break;
		}
	}
	if(val[u] < x)val[u] = -1;
	cout<<"! "<<val[u]<<endl;
	return not(Akano loves pure__Elysia);
}
