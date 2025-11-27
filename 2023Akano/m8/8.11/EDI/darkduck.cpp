#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXN = 2e5 + 1018 + 1108;
int fa[MAXN],rnk[MAXN],f[MAXN],n,m,k,tp;
pii e[MAXN];
inline int GetFa(int x){
	while(fa[x] != x)x = fa[x];
	return x;
}
struct Node{
	int x,y,delta;
	Node(){}
	Node(int _x,int _y,int _delta){x = _x,y = _y,delta = _delta;}
};
stack<Node,vector<Node> > stk;
inline bool Merge(int x,int y){
	x = GetFa(x),y = GetFa(y);
	if(x == y)return false;
	if(rnk[x] < rnk[y])swap(x,y);
	stk.push(Node(x,y,rnk[x] == rnk[y]));
	fa[y] = x;
	rnk[x] += (rnk[x] == rnk[y]);
	return true;
}
inline int Save(){
	return stk.size();
}
inline int Load(int org){
	int ret = 0;
	while(int(stk.size()) > org){
		const Node _tp = stk.top();
		stk.pop();
		fa[_tp.y] = _tp.y;
		rnk[fa[_tp.x]] -= _tp.delta;//OK ? x
		ret++;
	}
	return ret;
}
class SegmentTree{
	private:
		int ans;
		vector<int> vec[MAXN * 4];
		void Push(int p,int l,int r,int OBJL,int OBJR,int val){
			if(OBJL <= l && r <= OBJR){
				vec[p].push_back(val);
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJL)Push(p*2,l,mid,OBJL,OBJR,val);
			if(mid < OBJR)Push(p*2+1,mid+1,r,OBJL,OBJR,val);
			return ;
		}
		void Solve(int p,int l,int r){
			int save = Save();
			for(auto i : vec[p]){
				ans -= Merge(e[i].first,e[i].second);
			}
			if(l == r){
				f[l] = f[l-1];
				while(f[l] <= m && ans > k){
					f[l]++;
					if(f[l] > m)break;
					ans -= Merge(e[f[l]].first,e[f[l]].second);
					Push(1,1,m,l+1,f[l],f[l]);
				}
			}else{
				const int mid = (l + r) >> 1;
				Solve(p*2,l,mid),Solve(p*2+1,mid+1,r);
			}
			ans += Load(save);
			return ;
		}
	public:
		inline void Solve(){
			ans = n;
			for(int i = 1;i <= n;i++)fa[i] = i;
			Solve(1,1,m);
			return ;
		}
}tr;
inline void MainSolve(){
	unsigned int lastans = 0;
	int q,l,r;
	cin>>q;
	while(q--){
		cin>>l>>r;
		if(tp == 1){
			l = (l + lastans) % m + 1;
			r = (r + lastans) % m + 1;
			if(l > r)swap(l,r);
		}
		lastans <<= 1;
		if(f[l] <= r){
			cout<<"Yes"<<'\n';
			lastans++;
		}else{
			cout<<"No"<<'\n';
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("darkduck.in","r",stdin);
//	freopen("darkduck.out","w",stdout);
	cin>>n>>m>>k>>tp;
	for(int i = 1;i <= m;i++)cin>>e[i].first>>e[i].second;
	tr.Solve();
	MainSolve();
	return 0;
}
