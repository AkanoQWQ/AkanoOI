#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 9;
int child[MAXN*31][2],tot = 1;
int a[MAXN];
vector<int> p[MAXN * 31];
ll f[33][2];
void insert(int u,int num,int pos,int wei){
	if(wei < 0)return ;
	const int c = (num>>wei) & 1;
	if(!child[u][c])child[u][c] = ++tot;
	p[child[u][c]].push_back(pos);
	insert(child[u][c],num,pos,wei-1);
	return ;
}
void dfs(int u,int wei){
	const int lchild = child[u][0];
	const int rchild = child[u][1];
	if(lchild)dfs(lchild,wei-1);
	if(rchild)dfs(rchild,wei-1);
	if(!lchild && !rchild)return ;
	int num = 0;
	ll ret = 0;
	for(int i = 0;i < p[lchild].size();i++){
		const ll lpos = p[lchild][i];
		while(num < p[rchild].size() && p[rchild][num] < lpos){
			num++;
		}
		ret += num;
	}
	f[wei][0] += ret;
	f[wei][1] += 1ll * p[lchild].size() * p[rchild].size() - ret;
	return ;
}
ll answ,ansx;
int n;
int main(){
	freopen("inverse.in","r",stdin);
	freopen("inverse.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		insert(1,a[i],i,30);
	}
	dfs(1,30);
	for(int i = 30;i >= 0;--i){
		answ += min(f[i][0],f[i][1]);
		if(f[i][1] < f[i][0]){
			ansx |= (1ll<<i);
		}
	}
	printf("%lld %lld",answ,ansx);
	return 0;
}
