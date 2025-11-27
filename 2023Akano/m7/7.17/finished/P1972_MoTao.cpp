#include<bits/stdc++.h>
#pragma GCC target("avx")
using namespace std;
const int MAXN = 1e6 + 1018 + 1108;
int val[MAXN],cnt[MAXN],n,q,ans[MAXN],bel[MAXN],klen;
struct Query{
	int l,r,id;
}ask[MAXN];
bool cmp4Query(Query qa,Query qb){
	if(bel[qa.l] != bel[qb.l])return bel[qa.l] < bel[qb.l];
	if(bel[qa.l] & 1){
		return qa.r < qb.r;
	}else{
		return qa.r > qb.r;
	}
}
int nowl = 1,nowr = 0,nowans = 0;
inline void Update(int pos,int w){
	cnt[val[pos]] += w;
	if(cnt[val[pos]] == 0)--nowans;
	if(cnt[val[pos]] == 1 && w == 1)++nowans;
	return ;
}
inline int Solve(int l,int r){
	while(nowl > l)Update(--nowl,1);
	while(nowr < r)Update(++nowr,1);
	while(nowl < l)Update(nowl++,-1);
	while(nowr > r)Update(nowr--,-1);
	return nowans;
}
inline int Read(){//no f
	int ret = 0;
	char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}
int otp[66];
inline void Write(int x){
	int len = 0;
	while(x){
		otp[++len] = x % 10;
		x /= 10;
	}
	for(int i = len;i >= 1;i--)putchar(otp[i] + '0');
	return ;
}
int kol[MAXN],tokol[MAXN];
mt19937 rng(time(0));
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	n = Read();
	for(int i = 1;i <= n;i++){
		kol[i] = n - i + 1;
	}
	shuffle(kol + 1,kol + n + 1,rng);
	for(int i = 1;i <= n;i++){
		val[i] = Read();
		if(!tokol[val[i]])tokol[val[i]] = kol[i];
	}
	for(int i = 1;i <= n;i++){
		val[i] = tokol[val[i]];
	}
	q = Read();
	klen = 1.67f * n / sqrt(0.79f * q);//1.64 0.77
	for(int i = 1;i <= n;i++){
		bel[i] = i / klen;
	}
	for(int i = 1;i <= q;i++){
		ask[i].l = Read(),ask[i].r = Read();
		ask[i].id = i;
	}
	sort(ask+1,ask+q+1,cmp4Query);
	for(int i = 1;i <= q;i++){
		ans[ask[i].id] = Solve(ask[i].l,ask[i].r);
	}
	for(int i = 1;i <= q;i++){
		Write(ans[i]),putchar('\n');
	}
	return 0;
}
