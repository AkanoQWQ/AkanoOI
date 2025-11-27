#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 6;
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
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int n,m,ans[MAXN],anss[MAXN],dir[MAXN],tr[MAXN*8];
struct node{
	int no,v;
}c[MAXN];
bool cmp(node a,node b){
	return a.v < b.v;
}
void build(int l,int r,int p){
	int mid = (l + r) >> 1;
	if(l == r){
		dir[l] = p;
		return ;
	}
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	return ;
}
int objl,objr;
int query(int l,int r,int p){
	if(objl <= l && r <= objr){
		cout<<objl<<" and "<<l<<" and "<<r<<" and "<<objr<<endl;
		return tr[p];
	}
	int mid = (l + r) >> 1,ret = 0;
	if(mid >= objl)ret = query(l,mid,p*2);
	if(mid < objr)ret += query(mid+1,r,p*2+1);
	cout<<l<<" to "<<r<<" is "<<ret<<endl;
	return ret;
}
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n = 100;
	build(1,100,1);
	for(int i = 1;i <= 3;i++){
		int cc;
		cin>>cc;
		int pos = dir[cc];
		while(pos >= 1){
			tr[pos]++;
			pos /= 2;
		}
	}
	for(int i = 1;i <= 3;i++){
		int cc;
		cin>>cc;
		objl = 1,objr = cc;
		cout<<"ans:"<<query(1,n,1)<<endl;
	}
	for(int i = 1;i <= 3;i++){
		int cc;
		cin>>cc;
		int pos = dir[cc];
		while(pos >= 1){
			tr[pos]++;
			pos /= 2;
		}
	}
	for(int i = 1;i <= 3;i++){
		int cc;
		cin>>cc;
		objl = 1,objr = cc;
		cout<<query(1,n,1)<<endl;
	}
	return 0;
}
