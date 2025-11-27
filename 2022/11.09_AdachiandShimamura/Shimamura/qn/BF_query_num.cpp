#include<bits/stdc++.h>
using namespace std;
const int MAXM = 100006;
const int MAXN = 100006;
int a[MAXM],n,q,ans[MAXN],lef = 1,rig,cnt[MAXM],cur,m;
struct Query{
	int no,l,r;
}qry[MAXN];
bool cmp4qry(Query a,Query b){
	if(a.l / m != b.l / m){
		return (a.l/m) < (b.l/m);
	}
	if(a.l/m & 1){
		return a.r < b.r;
	}
	return a.r > b.r;
}
void Add(int x){
	if(cnt[x] == 0)cur++;
	cnt[x]++;
	return ;
}
void Del(int x){
	if(cnt[x] == 1)cur--;
	cnt[x]--;
	return ;
}
int main(){
	freopen("qn.in","r",stdin);
	freopen("qn_BF.out","w",stdout);
	cin>>n>>q;
	m = sqrt(n);
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= q;i++){
		cin>>lef>>rig;
		memset(cnt,0,sizeof(cnt));
		cur = 0;
		for(int j = lef;j <= rig;j++){
			if(cnt[a[j]] == 0)cur++;
			cnt[a[j]]++;
		}
		cout<<cur<<endl;
	}
	return 0;
}
