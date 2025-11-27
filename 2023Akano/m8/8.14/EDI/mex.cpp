#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int MAXN = 1e4 + 1018 + 1108;
ull rng(ull seed){
	seed ^= (seed<<13);
	seed ^= (seed>>7);
	seed ^= (seed<<17);
	return seed;
}
struct Node{
	int k,w,m;
	ull seed;
}node[MAXN];
bool Cmp(Node n1,Node n2){
	return n1.w > n2.w;
}
int a[MAXN],n,ans;
inline void Generate(int mod,ull seed){
	for(int i = 1;i <= n;i++){
		seed = rng(seed);
		a[i] = seed % mod;
	}
	return ;
}
int cnt[MAXN],arr[10];
inline bool Judge(int obj,int k){
	if(obj > n)return false;
	int query = obj,r = 0,ret = 0;
	for(int i = 0;i <= obj;i++)cnt[i] = 0;
	for(int l = 1;l <= n;l++){
		while(r < n && query > 0){
			r++;
			if(a[r] < obj){
				if(cnt[a[r]] == 0)query--;
				cnt[a[r]]++;
			}
		}
		ret += r - l;
		if(ret >= k)return false;
		if(a[l] < obj){
			if(cnt[a[l]] == 1)query++;
			cnt[a[l]]--;
		}
	}
	//mex <= obj的个数小于k,说明第k小的mex大于obj 
	return (ret < k);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>node[i].k>>node[i].w>>node[i].m>>node[i].seed;
		ans = max(ans,node[i].w);
	}
	for(int i = 1;i <= n;i++){//卡常,上界 n/2 
		Generate(node[i].m,node[i].seed);
		int mx = 0;
		for(int i = 1;i <= n;i++)mx = max(mx,a[i]);
		while(ans + 1 - node[i].w <= mx && Judge(ans + 1 - node[i].w,node[i].k))++ans;
	}
	cout<<ans;
	return 0;
}
