#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXN = 2e5 + 1018 + 1108;
int t,n,lst[MAXN],c,sel[MAXN],f[MAXN][2];
vector<pii> seg;
int dfs(int u,bool seled){
	//cout<<" dfs "<<u<<endl;
	if(u >= n)return 0;
	if(f[u][seled] != -1)return f[u][seled];
	//not sel
	int a1 = dfs(u+1,false);
	//sel
	int no = sel[u],a2 = 0;
	//cout<<u<<" sel "<<no<<endl;
	if(no == seg.size()){
		//do nothing because no segment left
	}else{
		a2 = dfs(seg[no].second,true) + seg[no].second - seg[no].first + 1;
		if(seled)--a2;
	}
	f[u][seled] = max(a1,a2);
//	cout<<u<<" f "<<f[u][seled]<<endl;
	return f[u][seled];
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		seg.clear();
		cin>>n;
		for(int i = 1;i <= n;i++){
			lst[i] = 0;
			f[i][0] = f[i][1] = -1;
		}
		for(int i = 1;i <= n;i++){
			cin>>c;
			if(lst[c] != 0){
				seg.push_back(make_pair(lst[c],i));
			}
			lst[c] = i;
		}
		sort(seg.begin(),seg.end());
		int tail = 0;
		for(int i = 1;i <= n;i++){
			while(tail < seg.size() && i > seg[tail].first){
				++tail;
			}
			sel[i] = tail;
		}
		int ans = dfs(1,false);
		cout<<ans<<endl;
	}
	return 0;
}
/*
2
6
1 2 3 1 3 2
11
1 4 4 4 2 1 2 4 4 4 2
*/
