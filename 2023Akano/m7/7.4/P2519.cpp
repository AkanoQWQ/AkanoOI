#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
const int MAXN = 1e5 + 6;
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void Write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int n;
struct my_hash{
	unsigned long long operator()(pair<int,int> pii)const {
		return ((1ull * pii.first) << 32) + pii.second;
	}
};
struct Node{
	int l,r,val;
	Node(){}
	Node(int _l,int _r,int _v){l = _l,r = _r,val = _v;}
};
unordered_map<pair<int,int>,int,my_hash> mp;
Node nd[MAXN];
bool cmp(Node na,Node nb){
	if(na.l != nb.l)return na.l < nb.l;
	return na.r < nb.r;
}
int tail,nxt[MAXN],lft[MAXN],f[MAXN];
int main(){
	n = Read();
	for(int i = 1;i <= n;i++){
		int a = Read(),b = Read();
		const int l = a + 1,r = n - b;
		if(l > r)continue;
		mp[make_pair(l,r)]++;
		mp[make_pair(l,r)] = min(mp[make_pair(l,r)],r-l+1);
	}
	for(auto i : mp){
		nd[++tail] = Node(i.first.first,i.first.second,i.second);
	}
	sort(nd+1,nd+tail+1,cmp);
	for(int i = 1;i <= tail;i++){
		lft[i] = nd[i].l;
	}
	for(int i = 1;i <= tail;i++){
		nxt[i] = upper_bound(lft+1,lft+tail+1,nd[i].r) - lft;
	}
	for(int i = tail;i >= 1;i--){
		f[i] = max(nd[i].val + f[nxt[i]],f[i+1]);
	}
	cout<<n-f[1]<<endl;
	return 0;
}
