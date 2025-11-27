#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXN = 2e5 + 1018 + 1108; 
template<typename T,int SIZE>
class ClearableBIT{
	private:
		stack<pair<int,int>,vector<pair<int,int> > > operations;//
		T val[SIZE];
		inline int Lowbit(int x){
			return x & (-x);
		}
		inline T QueryPre(int x){
			T ret = 0;
			while(x){
				ret += val[x];
				x -= Lowbit(x);
			}
			return ret;
		}
	public:
		inline void Change(int x,T _val){
			operations.push(make_pair(x,_val));
			while(x <= SIZE){
				val[x] += _val;
				x += Lowbit(x);
			}
			return ;
		}
		inline void DeChange(int x,T _val){
			while(x <= SIZE){
				val[x] += _val;
				x += Lowbit(x);
			}
			return ;
		}
		inline T Query(int l,int r){
			return QueryPre(r) - QueryPre(l-1);
		}
		inline void Clear(){
			while(!operations.empty()){
				DeChange(operations.top().first,-operations.top().second);
				operations.pop();
			}
			return ;
		} 
};
ClearableBIT<int,MAXN> bit;
struct Edge{
	int nxt,to,val;
}e[MAXN * 2];
int head[MAXN],ent;
inline void AddEdge(int from,int to,int val){
	e[++ent].to = to;
	e[ent].val = val;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
int n,k,ans;
//µÌ∑€÷  
int siz[MAXN],mss[MAXN],root,sum;//maxSubtreeSize
bool solved[MAXN];
void GetSize(int u,int fa){
	siz[u] = 1,mss[u] = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || solved[v])continue;
		GetSize(v,u);
		siz[u] += siz[v];
		mss[u] = max(mss[u],siz[v]);
	}
	mss[u] = max(mss[u],sum - siz[u]);
	if(mss[u] < mss[root])root = u;
	return ;
}
vector<pii> dist,predist;
void GetDis(int u,int fa,int mn,int mx){
	if(mx - mn <= k)dist.push_back(make_pair(mn,mx));
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || solved[v])continue;
		GetDis(v,u,min(mn,e[i].val),max(mx,e[i].val));
	}
	return ;
}
inline void Compute(const vector<pii>& mnvec,const vector<pii>& mxvec){
	auto it = mxvec.begin();
	bit.Clear();
	cout<<"Compute"<<endl;
	cout<<"THY "<<mxvec.size()<<endl;
	for(auto i : mxvec){
		cout<<"ADD "<<i.first<<","<<i.second<<endl;
		bit.Change(i.second,1);
	}
	cout<<"End Comp"<<endl;
	for(auto i : mnvec){
		while(it != mxvec.end() && (*it).first < i.first){
			cout<<"POP "<<i.first<<","<<i.second<<endl;
			bit.Change((*it).second,-1);
			it++;
		}
		if(i.second - i.first > k)continue;
		ans += bit.Query(i.first+k,i.first+k);
		cout<<"Query "<<i.first+k<<" is "<<bit.Query(i.first+k,i.first+k)<<endl;
	}
	return ;
}
inline void Calc(int u){
	cout<<"Solve "<<u<<endl;
	predist.clear();
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		dist.clear();
		cout<<"Get Dis "<<v<<endl;
		GetDis(v,u,e[i].val,e[i].val);
		sort(dist.begin(),dist.end());
		for(auto i : dist)cout<<i.first<<","<<i.second<<" | ";cout<<endl;
		for(auto i : predist)cout<<i.first<<","<<i.second<<" | ";cout<<endl;
		Compute(dist,predist),Compute(predist,dist);
		merge(dist.begin(),dist.end(),predist.begin(),predist.end(),back_inserter(predist));
		cout<<"END Subtree"<<endl<<endl;
	}
	cout<<endl<<endl<<endl;
	return ;
}
void Solve(int u){
	solved[u] = true;
	Calc(u);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		sum = siz[v],root = 0;
		GetSize(v,u);
		GetSize(root,root);
		Solve(root); 
	}
	return ;
} 
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("route/route1.in","r",stdin);
	mss[0] = 1e9;
	cin>>n>>k;
	for(int i = 1;i < n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	sum = n;
	GetSize(1,1),GetSize(root,root);
	Solve(root);
	cout<<ans;
	return 0;
}
