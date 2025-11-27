#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 4; 
int pre[MAXN],lst[MAXN],a[MAXN],n,ans,cnt = 0,nxt[MAXN],pos,tot;
struct node{
	int no,v;
}nd[MAXN];
bool cmp(node na,node nb){
	return na.v < nb.v;
}
int main(){
	//freopen("sequence.in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		ans += a[i];
		pre[i] = pre[i-1] + a[i];
	}
	tot = ans;
	for(int i = n;i >= 1;i--){
		lst[i] = lst[i+1] + a[i];
		nd[i].no = i,nd[i].v = lst[i];
	}
	nd[n+1].no = n + 1,nd[n+1].v = 0;
	sort(nd+1,nd+n+2,cmp);
	for(int i = 1;i <= n;i++){
		nxt[nd[i].no] = nd[i+1].no;
	}
	pos = nd[1].no;
	for(int l = 0;l <= n;l++){
		while(pos <= l){
			pos = nxt[pos];
		}
		ans = max(ans,tot - 2 * (pre[l] + lst[pos]));
	}
	cout<<ans;
	return 0;
}
