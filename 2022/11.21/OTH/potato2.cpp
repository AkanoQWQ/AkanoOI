#include<bits/stdc++.h>
using namespace std;
const int OK = 30;
const int MAXN = 2e5 + 6;
int t,n,m,c[14],l,r;
vector<pair<int,int> > a[MAXN];
bool solve(){
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < m-1;j++){
			if(a[i][j].first > a[i][j+1].first)return 0;
		}
	}
	return 1;
}
inline int read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
bool swp[MAXN];
int main(){
	freopen("potato.in","r",stdin);
//	freopen("potato.out","w",stdout);
	t = read();
	while(t--){
		bool able = 1;
		n = read(),m = read();
		l = -1,r = -1;
		for(int i = 1;i <= n;i++){
			swp[i] = 0;
			a[i].clear();
			for(int j = 1;j <= m;j++){
				int inx = read();
				a[i].push_back(make_pair(inx,j));
			}
			for(int j = 0;j < m;j++){
				cout<<a[i][j].first<<"("<<a[i][j].second<<") ";
			}
			cout<<endl;
			stable_sort(a[i].begin(),a[i].end());
			int cnt = 0;
			for(int j = 0;j < m;j++){
				if(a[i][j].second-1 != j){
					c[++cnt] = j;
					if(cnt >= 3){
						
						puts("ERR");
						able = 0;
						break;
					}
				}
			}
			cout<<endl;
			if(l != -1 && min(c[1],c[2]) != l){
				able = 0;
			}
			if(r != -1 && max(c[1],c[2]) != r){
				able = 0;
			}
			if(cnt >= 2){
				l = min(c[1],c[2]);
				r = max(c[1],c[2]);
				swp[i] = 1;
			}
			if(able == 0)break;
		}
		if(able == 1 && l != -1){
			for(int i = 1;i <= n;i++){
				if(swp[i] == 0){
					swap(a[i][l],a[i][r]);
				}
			}
			if(solve() == 0){
				able = 0;
			}
		}
		if(able == 0){
			puts("-1");
		}else if(l == -1){
			puts("1 1");
		}else{
			printf("%d %d\n",l+1,r+1);
		}
	}
	return 0;
}
