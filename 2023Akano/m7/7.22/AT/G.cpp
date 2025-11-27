#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 306;
const int MAXV = 300;
int n,m;
ll cnt[MAXN][MAXN][MAXN];//number line pos
ll sum[MAXN][MAXN],arr[MAXN][MAXN];
bool EXIST(int line,int l,int r,int num){
	return cnt[num][line][r] - cnt[num][line][l-1];
}
ll ans;
vector<int> del[MAXN];
inline int GetMin(int x,int l,int r){
	int L = 0,R = MAXV + 1,ret = 0;
	while(L < R){
		const int mid = (L + R) >> 1;
		if(EXIST(x,l,r,mid)){
			ret = mid;
			R = mid;
		}else{
			L = mid + 1;//correct?
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("G.in","r",stdin);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>arr[i][j];
			cnt[arr[i][j]][i][j]++;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			for(int k = 1;k <= MAXV;k++)cnt[k][i][j] += cnt[k][i][j-1];
			sum[i][j] = sum[i][j-1] + arr[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			for(int k = 1;k <= MAXV;k++)cnt[k][i][j] += cnt[k-1][i][j];
		}
	}
	for(int l = 1;l <= m;l++){
		for(int r = l;r <= m;r++){
			ll upd = 0;
			for(int i = 0;i <= MAXV;i++){
				del[i].clear();
			}
			for(int i = 1;i <= n;i++){
				upd += sum[i][r] - sum[i][l-1];
				del[GetMin(i,l,r)].push_back(i);
			}
			for(int val = 1;val <= MAXV;val++){
				for(auto i : del[val-1]){
					upd -= sum[i][r] - sum[i][l-1];
				}
				ans = max(ans,upd * val);
				if(upd == 0)break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

