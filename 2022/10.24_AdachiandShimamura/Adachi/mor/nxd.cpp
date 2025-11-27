#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 500006;
int n,tot,cnt = -114514-1,t[(MAXN << 2) + 2];
int head[MAXN],cpos,c2pos,b[MAXN],dir[MAXN],ans;
struct node{
	int v,no;
}a[MAXN];
bool cmp(node a,node b){
	return a.v < b.v;
}
void build(int l,int r,int p){
	if(l == r){
		head[a[l].no] = p;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	return ;
}
int query(int l,int r,int objl,int objr,int p){
	//cout<<"search "<<l<<" "<<r<<" with "<<objl<<" "<<objr<<endl;
	if(objl <= l && r <= objr){
		return t[p];
	}
	int mid = (l + r) >> 1,ret = 0;
	if(mid >= objl)ret = query(l,mid,objl,objr,p*2);
	if(mid < objr)ret += query(mid+1,r,objl,objr,p*2+1);
	return ret;
}
signed main(){
	//freopen("P1908_1.in","r",stdin);
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i].v);
		a[i].no = i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i++){
		if(a[i].v != cnt){
			cnt = a[i].v;
			tot++;
			for(int j = cpos;j < i;j++){
				b[j] = i-1;
			}
			cpos = i;
		}
		a[i].v = tot;
		dir[a[i].no] = i;
	}
	for(int j = cpos;j <= n;j++){
		b[j] = n;
	}
	build(1,n,1);
	for(int i = 1;i <= n;i++){
		cout<<head[i]<<" ";
	}
	cout<<endl;
	for(int i = n;i >= 1;i--){
		cout<<"now "<<a[dir[i]].v<<" ";
		if(a[dir[i]].v > 1){
			cout<<(n-b[i])<<"-"<<query(1,n,a[dir[i]].v,tot,1)<<" ";
			ans += (n-b[i])-query(1,n,a[dir[i]].v,tot,1);
		}else{
			ans += (n-b[i]);
			cout<<(n-b[i])<<" ";
		}
		int pos = head[i];
		while(pos >= 1){
			cout<<" add"<<pos<<" ";
			t[pos]++;
			pos /= 2;
		}
		//cout<<i<<":"<<ans<<endl;
		cout<<endl;
		for(int i = 1;i <= n;i++){
			cout<<query(1,n,a[dir[i]].v,a[dir[i]].v,1)<<" ";
		}
		cout<<endl;
	}
	cout<<ans;
	return 0;
}
/*
8
1 1 2 2 3 3 4 4
*/
