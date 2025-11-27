#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+6;
int n,m,len,a[MAXN],ind[MAXN];
int tot,ls[MAXN<<5],rs[MAXN<<5],sum[MAXN<<5],rt[MAXN];
int id(int val){
	return lower_bound(ind+1,ind+len+1,val) - ind;
}
int build(int l,int r){
	int no = ++tot;
	if(l == r)return no;
	int mid = (l+r)>>1;
	ls[no] = build(l,mid);
	rs[no] = build(mid+1,r);
	return no;
}
int update(int v,int l,int r,int root){
	int no = ++tot;
	ls[no] = ls[root],rs[no] = rs[root],sum[no] = sum[root] + 1;
	if(l == r)return no;
	int mid = (l+r)>>1;
	if(v <= mid){
		ls[no] = update(v,l,mid,ls[no]);
	}else{
		rs[no] = update(v,mid+1,r,rs[no]);
	}
	return no;
}
int query(int u,int v,int l,int r,int k){
	int mid = (l+r)>>1,x = sum[ls[v]] - sum[ls[u]];
	if(l == r)return l;
	if(k <= x){
		return query(ls[u],ls[v],l,mid,k);
	}else{
		return query(rs[u],rs[v],mid+1,r,k-x);
	}
	return 114514;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		ind[i] = a[i];
	}
	sort(ind+1,ind+n+1);
	len = unique(ind+1,ind+n+1)-ind-1;
	rt[0] = build(1,len);
	for(int i = 1;i <= n;i++)rt[i] = update(id(a[i]),1,len,rt[i-1]);
	while(m--){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",ind[query(rt[l-1],rt[r],1,len,k)]); 
	}
	return 0;
}
