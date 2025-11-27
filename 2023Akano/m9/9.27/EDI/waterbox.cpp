#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXH = 1e6 + 1018 + 1108;
int T,n,m;
int h[MAXN];
bool Cmp(int u1,int u2){
	return h[u1] < h[u2];
}
struct Query{
	int pos,h,type;
}ask[MAXN];
bool Cmp4Query(Query q1,Query q2){
	if(q1.h != q2.h)return q1.h < q2.h;
	if(q1.pos != q2.pos)return q1.pos < q2.pos;
	return q1.type < q2.type;
}
struct Node{
	int l,r,nodeNo;
	Node() = default;
	Node(int _l,int _r,int _no){
		l = _l,r = _r,nodeNo = _no;
		return ;
	}
};
bool operator<(Node n1,Node n2){
	if(n1.l != n2.l)return n1.l < n2.l;
	return n1.r < n2.r;
}
int full[MAXN*2],part[MAXN*2];
inline int GetDelta(vector<Query>& vec){
	int k0 = 0,k1 = 0,delta = 0;
	for(auto i : vec){
		if(i.type == 0)k0++;
	}
	delta = k0;
	for(auto i : vec){
		if(i.type == 0){
			k0--;
		}else{
			k1++;
		}
		delta = max(delta,k0 + k1);
	}
	return delta;
}
inline int Get0(vector<Query>& vec){
	int k0 = 0;
	for(auto i : vec){
		if(i.type == 0)k0++;
	}
	return k0;
}
inline int Get1(vector<Query>& qry){
	int ret = 0;
	for(auto i : qry){
		if(i.type == 1)ret++;
	}
	return ret;
}
map<pii,int> dir;
/*并查姬和确定点的区间部分相关*/
int fa[MAXN],unionL[MAXN],unionR[MAXN],l[MAXN],r[MAXN];
vector<Query> querys[MAXN * 2];
int GetFa(int x){
	if(fa[x] == x)return x;
	return fa[x] = GetFa(fa[x]);
}
inline void PushQuerys(){
	for(int i = 0;i <= n;i++)fa[i] = i;
	for(int i = 1;i <= m;i++){
		unionL[i] = GetFa(ask[i].pos);
		while(h[unionL[i]-1] < ask[i].h){
			fa[unionL[i]] = unionL[i]-1;
			unionL[i] = GetFa(unionL[i]);
		}
	}
	for(int i = 0;i <= n;i++)fa[i] = i;
	for(int i = 1;i <= m;i++){
		unionR[i] = GetFa(ask[i].pos);
		while(h[unionR[i]] < ask[i].h){
			fa[unionR[i]] = unionR[i]+1;
			unionR[i] = GetFa(unionR[i]);
		}
		querys[dir[make_pair(unionL[i],unionR[i])]].push_back(ask[i]);
	}
	return ;
}
/*分段,建树相关*/
vector<int> vec;
int nnt,son[2*MAXN][2],cen[2*MAXN];
inline void ReadIn(){
	cin>>n>>m;
	for(int i = 1;i < n;i++){
		cin>>h[i];
	}
	h[0] = h[n] = MAXH - 2,h[n+1] = 0;
	for(int i = 1;i <= m;i++){
		cin>>ask[i].pos>>ask[i].h>>ask[i].type;
		ask[i].h++;
	}
	vec.clear();
	for(int i = 1;i < n;i++)vec.push_back(i);
	return ;
}
inline void Clear(){
	dir.clear();
	for(int i = 0;i <= n;i++){
		querys[i].clear();
	}
	return ;
}
void dfs(int u){
	if(!u)return ;
	dfs(son[u][0]),dfs(son[u][1]);
	full[u] = full[son[u][0]] + full[son[u][1]] + Get1(querys[u]);
	part[u] = full[son[u][0]] + full[son[u][1]] + GetDelta(querys[u]);
	part[u] = max(part[u],part[son[u][0]] + part[son[u][1]] + Get0(querys[u]));
	return ;
}
inline int Solve(){
	ReadIn();
	Clear();
	sort(vec.begin(),vec.end(),Cmp);
	sort(ask+1,ask+m+1,Cmp4Query);
	set<Node> st;
	for(int i = 1;i <= n;i++){
		st.insert(Node(i,i,++nnt));
		l[nnt] = i,r[nnt] = i,son[nnt][0] = son[nnt][1] = 0;
		cen[nnt] = n+1;
		dir[make_pair(l[nnt],r[nnt])] = nnt;
	}
	for(auto lim : vec){
		auto pre = --st.lower_bound(Node(lim+1,-1,0));
		auto nxt = st.lower_bound(Node(lim+1,-1,0));
		Node newNode = Node(pre->l,nxt->r,++nnt);
		son[nnt][0] = pre->nodeNo,son[nnt][1] = nxt->nodeNo,cen[nnt] = lim;
		l[nnt] = newNode.l,r[nnt] = newNode.r;
		dir[make_pair(l[nnt],r[nnt])] = nnt;
		st.erase(nxt),st.erase(pre),st.insert(newNode);
	}
	PushQuerys();
	dfs(st.begin()->nodeNo);	
	return max(full[st.begin()->nodeNo],part[st.begin()->nodeNo]);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cout<<Solve()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
