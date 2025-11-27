#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
constexpr int MAXN = 1e5 + 1018 + 1108;
constexpr int MAXM = 106;
int n,m,k;
string mp[MAXN];
int lr[MAXN],ud[MAXM],sumlr[MAXN],sumud[MAXN],nxt0[MAXN],r[MAXN];
ll ans;
map<int,int> mem;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= n;i++){
		cin>>mp[i]; 
		for(auto ch : mp[i]){
			if(ch == '$'){
				lr[i]++;
			}
		}
		sumlr[i] = sumlr[i-1] + lr[i];
	}
	for(int i = n;i >= 1;i--){
		if(lr[i] == 0){
			nxt0[i] = nxt0[i+1] + 1;
		}else{
			nxt0[i] = 0;
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			ud[i] += (mp[j][i-1] == '$');
		}
		sumud[i] = sumud[i-1] + ud[i];
	}
	for(int rangeL = 1;rangeL <= m;rangeL++){
		for(int rangeR = rangeL;rangeR <= m;rangeR++){
			const int res = k - (sumud[rangeR] - sumud[rangeL-1]);
			if(res >= 0){
				mem[res]++;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		r[i] = i;
	}
	for(auto pr : mem){
		ll nowans = 0;
		int w = pr.second,res = pr.first;
		for(int l = 1;l <= n;l++){
			r[l] = max(r[l],r[l-1]); 
			while(r[l] <= n && sumlr[r[l]] - sumlr[l-1] < res){
				r[l]++;
			}
			if(r[l] > n)break;
			if(r[l] <= n && sumlr[r[l]] - sumlr[l-1] == res){
				nowans += nxt0[r[l]+1] + 1;
			}
		}
		ans += nowans * w; 
	}
	cout<<ans<<endl;
	return 0;
}
