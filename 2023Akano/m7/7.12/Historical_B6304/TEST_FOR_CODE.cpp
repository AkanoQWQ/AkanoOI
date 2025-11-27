#include <bits/stdc++.h>
using std::cin;
using std::cout;
using LL = long long;
using ull = unsigned long long;
using ld = long double;

const int maxn = 2e5+10;




int a[maxn];
LL siz[maxn],sum[maxn];
std::vector<int> edge[maxn];

bool cmp(int x,int y){
	return siz[x]*sum[y] < siz[y]*sum[x];
}

void pdfs(int now,int fa){
	siz[now]=1;
	sum[now]=a[now];
	for(int i : edge[now]){
		if(i==fa) continue;
		pdfs(i,now);
		siz[now]+=siz[i];
		sum[now]+=sum[i];
	}
	std::sort(edge[now].begin(),edge[now].end(),cmp);
}

// 算出以1为根的ans 在此基础上改 
LL id,ans,ANS=LLONG_MAX;
void dfs1(int now,int fa){
	++id,ans+=id*a[now];
	for(int i : edge[now]){
		if(i==fa) continue;
		dfs1(i,now);
	}
}

// 换根 dp ——保证每个儿子被换到根时，所有（要用到的）数据都是以其为根所得的数据 
void dfs2(int u,int fa){
//	cout << u << ": " << ans << '\n';
	ANS=std::min(ANS,ans);
	LL cntsz = 1,cntsum = a[u]; // 多一个儿子累加一次 
	
	for(int v : edge[u]){
		if(v==fa) {
			cntsz+=siz[v],cntsum+=sum[v];
			continue;
		}
		
		// choose a son to flip to the root
		
		// step1: 复制原数据（只会涉及到 u/v/ans） 
		const LL usiz=siz[u],usum=sum[u],vsiz=siz[v],vsum=sum[v],pans = ans;
		
		// step2: update the siz & sum
		siz[u] = usiz-vsiz;
		sum[u] = usum-vsum;
		siz[v] = usiz;
		sum[v] = usum;
		
		// step3: calc the new answer & get deeper
		
		ans = ans - cntsz*vsum + cntsum*vsiz;
		cntsz+=vsiz,cntsum+=vsum;
		// 原v子树被提起来cntsz格，同时已经遍历过的下降vsiz格 
		
		
		LL ccsiz=0,ccsum=0;
		for(int bro : edge[v]){
			if(bro==u) continue;
			if(cmp(u,bro)) {
				// u比其兄弟小
				ccsiz+=siz[bro],ccsum+=sum[bro];
			}
		}
		ans = ans - ccsiz*sum[u] + siz[u]*ccsum;
		// 统计所有 siz/sum 比新子树u更大的siz.sum之和
		// 并插入到正确的位置更新答案 （u左移，兄弟右移）  
		std::sort(edge[v].begin(),edge[v].end(),cmp);
		
		// well, it looks like a sandwich:: 
		// copy & modify -> dfs(son) -> change back
		// add
		dfs2(v,u);
		// step4: recover
		ans = pans;
		siz[u]=usiz,sum[u]=usum,siz[v]=vsiz,sum[v]=vsum;
		std::sort(edge[v].begin(),edge[v].end(),cmp);
	}
}

int main() {
	freopen("B6304.in","r",stdin);
	int n;
	cin >> n;
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i=1;i<=n;i++) cin >> a[i];
	
	pdfs(1,1);
	dfs1(1,1);
	dfs2(1,1);
	cout << ANS;
	return 0;
}
