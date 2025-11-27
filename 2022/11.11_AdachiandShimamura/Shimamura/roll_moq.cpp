#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200006;
int n,a[MAXN],m,len,num[MAXN],numl,ans[MAXN],k[MAXN],maxk;
struct question{
	int l,r,id;
}q[MAXN];
bool cmp4q(question a,question b){
	if(k[a.l] != k[b.l])return k[a.l] < k[b.l];
	return a.r < b.r;
}
int cnt[MAXN],clr[MAXN],tp,qk = 1,cans,st[MAXN];
void clearcnt(){
	while(tp >= 1){
		cnt[clr[tp]] = 0;
		st[clr[tp]] = 0;
		--tp;
	}
	return ;
}
int calc_cnt[MAXN];
int calc(int l,int r){
	int ret = 0;
	for(int i = l;i <= r;i++){
		calc_cnt[a[i]] = 0;
	}
	for(int i = l;i <= r;i++){
		if(calc_cnt[a[i]] == 0){
			calc_cnt[a[i]] = i;
		}else{
			ret = max(ret,i-calc_cnt[a[i]]);
		}
	}
	return ret;
}
int main(){
	freopen("rmoq.in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	len = sqrt(n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		num[i] = a[i];
		k[i] = (i-1) / len + 1;
	}
	maxk = k[n];
	sort(num+1,num+n+1);
	numl = unique(num+1,num+n+1) - num - 1;
	for(int i = 1;i <= n;i++){
		a[i] = lower_bound(num+1,num+numl+1,a[i]) - num;
	}
	scanf("%d",&m);
	for(int i = 1;i <= m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id = i;
	}
	sort(q+1,q+m+1,cmp4q);
	for(int rk = 1;rk <= maxk;rk++){
		const int mainr = min(n,rk * len);
		int tl = mainr + 1,tr = mainr;
		cans = 0;
		while(qk <= m && k[q[qk].l] == rk){
			const int ql = q[qk].l,qr = q[qk].r;
			if(k[ql] == k[qr]){
				ans[q[qk].id] = calc(ql,qr);
				qk++;
				continue;
			}
			while(tr < qr){
				++tr;
				cnt[a[tr]] = tr;
				if(!st[a[tr]]){
					st[a[tr]] = tr;
					clr[++tp] = a[tr];
				}
				cans = max(cans,tr - st[a[tr]]);
			}
			int cache_ans = cans;
			while(tl > ql){
				--tl;
				if(cnt[a[tl]] == 0){
					cnt[a[tl]] = tl;
				}else{
					cans = max(cans,cnt[a[tl]] - tl);
				}
			}
			ans[q[qk].id] = cans;
			cans = cache_ans;
			while(tl <= mainr){
				if(cnt[a[tl]] == tl){
					cnt[a[tl]] = 0;
				}
				++tl;
			}
			qk++;
		}
		clearcnt();
	}
	for(int i = 1;i <= m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
