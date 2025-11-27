#pragma GCC target("avx")
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<bitset>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1018 + 1108;
int n,L,c,v,maxs,s,m;
bitset<MAXN> bag[MAXN],cache,ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("bag/bag3.in","r",stdin);
//	freopen("bag.out","w",stdout);
	cin>>n>>L;
	bag[0][0] = true;
	for(int i = 1;i <= n;i++){
		cin>>c>>v;
		for(int j = i-1;j >= 0;j--){
			if(!bag[j].count())continue;
			int now = 1,res = c - 1;
			cache = bag[j] << v;
			while(now <= res){
				cache |= cache << (now * v);
				res -= now;
				now *= 2;
			}
			if(res){
				cache |= (cache << (res * v));
			}
			bag[j + 1] |= cache;
		}
	}
	cin>>m;
	for(int i = 1;i <= m;i++){
		cin>>s;
		ans |= bag[s];
	}
	for(int i = 1;i <= L;i++){
		if(ans[i])cout<<i<<" ";
	}
	cout<<endl;
	return not(Akano loves pure__Elysia);
}
