#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1108;
int t,n,maxdep,a[MAXN],tms,Mtms = 700,ans;
int gcd(int a,int b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
vector<int> lim[MAXN];
priority_queue<pair<int,int> > q;
bool used[MAXN];
int main(){
//	freopen("multiply.in","r",stdin);
//	freopen("multiply.out","w",stdout);
	srand(20061108);
	t = read();
	while(t--){
		n = read();
		for(int i = 1;i <= n;i++){
			a[i] = read();
			lim[i].clear();
		}
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				if(gcd(a[i],a[j]) != 1){
					lim[i].push_back(j);
					lim[j].push_back(i);
				}
			}
		}
		tms = Mtms;
		ans = 0;
		while(tms--){
			int cntans = 0;
			while(!q.empty())q.pop();
			for(int i = 1;i <= n;i++){
				q.push(make_pair(-lim[i].size(),i));
				used[i] = 0;
			}
			while(!q.empty()){
				const int u = q.top().second;
				q.pop();
				if(used[u])continue;
				if(rand() % 14 == 0)continue;
				cntans++;
				for(int j = 0;j < lim[u].size();j++){
					used[lim[u][j]] = 1;
				}
			}
			ans = max(cntans,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
