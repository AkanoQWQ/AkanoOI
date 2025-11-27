#include<bits/stdc++.h>
using namespace std;
int n,m,fa[200611],dis[200611],l,r,d,p,q,i,j,k;
int getfa(int u){
	if(u == fa[u]){
		return u; 
	}else{
		int t = getfa(fa[u]);
		dis[u] += dis[fa[u]];
		fa[u] = t;
		return fa[u];
	}
}
int main(){
	cin>>n>>m;
	for(i = 1;i <= n;i++){
		fa[i] = i;
		dis[i] = 0;
	}
	for(i = 1;i <= m;i++){
		cin>>l>>r>>d;
		if(getfa(l) == getfa(r)){
			if(dis[r] - dis[l] != d){
				cout<<"No";
				return 0;
			}
		}else{
				p = getfa(r);
				q = getfa(l);
				fa[p] = q;
				dis[p] = dis[l] - dis[r] + d;
		}
	}
	cout<<"Yes";
	return 0;
}

