#include<bits/stdc++.h>
using namespace std;
const int MAXM = 1000006;
const int MAXN = 30006;
const int MAXQ = 200006;
int a[MAXM],n,q,ans[MAXN],lef = 1,rig,cnt[MAXM],cur,m;
struct Query{
	int no,l,r;
}qry[MAXQ];
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
	if(cnt[a[x]] == 0)cur++;
	cnt[a[x]]++;
	return ;
}
void Del(int x){
	if(cnt[a[x]] == 1)cur--;
	cnt[a[x]]--;
	return ;
}
int main(){
	//freopen("qn.in","r",stdin);
	//freopen("qn.out","w",stdout);
	cin>>n;
	m = sqrt(n);
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	cin>>q;
	for(int i = 1;i <= q;i++){
		cin>>qry[i].l>>qry[i].r;
		qry[i].no = i;
	}
	sort(qry+1,qry+q+1,cmp4qry);
	for(int i = 1;i <= q;i++){
		while(lef > qry[i].l)Add(--lef);
		while(rig < qry[i].r)Add(++rig);
		while(lef < qry[i].l)Del(lef++);
		while(rig > qry[i].r)Del(rig--);
		ans[qry[i].no] = cur;
	}
	for(int i = 1;i <= q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
