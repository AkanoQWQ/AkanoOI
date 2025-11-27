#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 1000006;
int zkwt[MAXN * 5],head[MAXN],n,p;
ll sum[MAXN],mainans;
struct node{
	ll v;
	int no;
}a[MAXN];
void build(int l,int r,int p){
	if(l == r){
		head[a[l].no] = p;
		return ;
	}
	int mid = (l+r) >> 1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	return ;
}
bool cmp4(node a,node b){
	return a.v > b.v;
}
int query(int l,int r,int objl,int objr,int p){
	if(objl <= l && r <= objr)return zkwt[p];
	int mid = (l + r) >> 1,ret = 0;
	if(mid >= objl)ret = query(l,mid,objl,objr,p*2);
	if(mid < objr)ret += query(mid+1,r,objl,objr,p*2+1);
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i].v);
		a[i].no = i;
	}
	scanf("%d",&p);
	for(int i = 1;i <= n;i++){
		a[i].v -= p;
		a[i].v += a[i-1].v;
		sum[i] = a[i].v;
	}
	for(int i = 1;i <= n;i++){
		a[i].v = -sum[i-1];
	}
	sort(a+1,a+n+1,cmp4);
	build(1,n,1);
	for(int i = n;i >= 1;i--){
		ll obj = -sum[i];
		int l = 1,r = n+1,ret = 0;
		while(l < r){
			int mid = (l + r) >> 1;
			if(a[mid].v >= obj){
				ret = mid;
				l = mid + 1;
			}else{
				r = mid; 
			} 
		}
		if(ret >= 1){
			mainans += ret - query(1,n,1,ret,1);
		}
		int pos = head[i];
		while(pos >= 1){
			zkwt[pos]++;
			pos /= 2;
		}
	}
	cout<<mainans;
	return 0;
}
