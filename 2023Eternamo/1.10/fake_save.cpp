#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 206;
int n,h[MAXN],q;
vector<int> damage[MAXN];
int ksm(int a,int b){
	int ret = 1;
	while(b){
		if(b & 1)ret = (1ll * ret * a) % MOD;
		a = (1ll * a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
int inv(int inx){
	return ksm(inx,MOD-2) % MOD;
}
int divv(int a,int b){
	return (1ll * a * inv(b)) % MOD;
}
bool selected[MAXN];
int maxdep,trans,tid,ret,cp[MAXN],cps;
void select(int pos){
	if(pos >= maxdep){
		int comm = 0;
		for(int i = 0;i < maxdep;i++){
			if(selected[i] == 1)comm++;
		}
		if(comm  < trans){//alive
			long long apos = 1;
			for(int i = 0;i < maxdep;i++){
				if(selected[i]){
					apos = (apos * damage[tid][i]) % MOD;
				}else{
					apos = (apos * (MOD - damage[tid][i] + 1)) % MOD;
				}
			}
			ret = (ret + apos) % MOD;
		}
		return ;
	}
	selected[pos] = 0;
	select(pos + 1);
	selected[pos] = 1;
	select(pos + 1);
	return ;
}
int calc1(int id){
	if(damage[id].size() < h[id])return 1;
	maxdep = damage[id].size(),trans = h[id],tid = id,ret = 0;
	select(0);
	return ret;
}
int main(){
	freopen("fake.in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&h[i]);
	}
	scanf("%d",&q);
	while(q--){
		int op,id,u,v;
		scanf("%d",&op);
		if(op == 0){
			scanf("%d%d%d",&id,&u,&v);
			damage[id].push_back(divv(u,v));
		}else{
			int k;
			scanf("%d",&k);
			cps = 0;
			for(int i = 1;i <= k;i++){
				int cid;
				scanf("%d",&cid);
				cp[i] = calc1(cid);
				cps += cp[i];
			}
			for(int i = 1;i <= k;i++){
				printf("%d ",divv(cp[i],cps));
			}
			putchar('\n');
		}
	}
/*	for(int i = 1;i <= n;i++){
		cout<<"health "<<h[i]<<" ";
		cout<<i<<":"; 
		for(int j = 0;j < damage[i].size();j++){
			cout<<damage[i][j]<<" damage "<<" ";
		}
		cout<<endl;
	}*/
	
	for(int i = 1;i <= n;i++){
		long long dam = 0;
		bool killed = 0;
		for(int j = 0;j < damage[i].size();j++){
			dam += damage[i][j];
			if(dam >= MOD){
				killed = 1;
				break;
			}
		}
		if(killed){
			printf("0 ");
		}else{
			printf("%d ",(h[i] + MOD - dam) % MOD);
		}
	}
	return 0;
}
