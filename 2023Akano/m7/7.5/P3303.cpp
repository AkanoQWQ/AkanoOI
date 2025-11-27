#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using ll = long long;
using lll = __int128;
using pil = pair<int,long long>;
const int MAXW = 16;
const int MOD = 1e9 + 7;
vector<ll> possval;//possible val
ll n,k,ans;
lll lll1 = 1;
int a[MAXW],len,nxt[MAXW],sz;
void Pre(ll _val,int x){
	if(_val > n)return ;
	if(!x && _val != 0){
		possval.push_back(_val);
		return ;
	}
	Pre(_val * x,x);
	Pre(_val,nxt[x]);
	return ;
}
inline void Trans(ll x){
	len = 0;
	while(x){
		a[++len] = x % 10;
		x /= 10;
	}
	return ;
}
struct my_hash{
	unsigned long long operator()(pil _pil)const {
		return ((1ull * _pil.first) << 32) ^ _pil.second;
	}
};
unordered_map<pil,ll,my_hash> f;
ll dfs(int u,ll x,bool limit,bool lead0){
	if(u == 0){
		return (x == 1) && (!lead0);//??
	}
	const pil ux = make_pair(u,x);
	if(!limit && !lead0 && f.find(ux) != f.end())return f[ux];
	int up = limit ? a[u] : 9;ll ret = 0;
	if(lead0){//add 0
		ret += dfs(u-1,x,false,lead0);
	}
	for(int i = 1;i <= up;i++){
		if(x % i== 0){
			ret += dfs(u-1,x/i,limit && (i==up),false);
		}
	}
	if(!limit && !lead0)f[ux] = ret;
	return ret;
}
inline ll Solve(ll x){
	return dfs(len,x,true,true);
}
vector<ll> dir;
bool CmpBigger(ll _a,ll _b){
	return _a > _b;
}
struct Node{
	int tail1,tail2;
	Node(){}
	Node(int _tail1,int _tail2){tail1=_tail1,tail2=_tail2;}
	inline lll Val(){
		return lll1 * dir[tail1] * dir[tail2];
	}
};
bool operator<(Node _a,Node _b){
	return _a.Val() < _b.Val();
}
priority_queue<Node> q;
int main(){
	freopen("P3303.in","r",stdin);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	Trans(n);
	nxt[2] = 3,nxt[3] = 5,nxt[5] = 7,nxt[7] = 0;
	Pre(1,2);
	for(auto i : possval){
		const ll _ans = Solve(i);
		dir.push_back(_ans);
	}
	sort(dir.begin(),dir.end(),CmpBigger);
	sz = dir.size() - 1;
	for(int i = sz;i >= 0;i--){
		q.push(Node(i,0));
	}
	for(int i = 1;i <= k;i++){
		Node nd = q.top();
		q.pop();
		ans = (ans + nd.Val()) % MOD;
		if(nd.tail2 + 1 <= sz)q.push(Node(nd.tail1,nd.tail2+1));
	}
	cout<<ans<<flush;
	return 0;
}
