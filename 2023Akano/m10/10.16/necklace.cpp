#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 5e5 + 1018 + 1108;
struct Edge{
	int u,v,val;
	Edge() = default;
	Edge(int _u,int _v,int _val){
		if(_u > _v)swap(_u,_v);
		u = _u,v = _v,val = _val;
		return ;
	}
};
bool operator<(Edge e1,Edge e2){
	if(e1.val != e2.val)return e1.val < e2.val;
	if(e1.u != e2.u)return e1.u < e2.u;
	return e1.v < e2.v;
}
bool operator==(Edge e1,Edge e2){
	return e1.u == e2.u && e1.v == e2.v && e1.val == e2.val;
}
int tid,n,m,a[MAXN],mx,pre[MAXN],nxt[MAXN];
template<typename T>
struct DeleteablePriorityQueue{
	priority_queue<T> pq,del;
	inline void Check(){
		while(!pq.empty() && !del.empty() && pq.top() == del.top()){
			pq.pop(),del.pop();
		}
		return ;
	}
	inline void Insert(T content){
		pq.push(content);
		return ;
	}
	inline void Delete(T content){
		del.push(content);
		return ;
	}
	inline T Top(){
		Check();
		return pq.top();
	}
	inline void Pop(){
		Check();
		pq.pop();
		return ;
	}
	inline bool Empty(){
		Check();
		return pq.empty();
	}
};
DeleteablePriorityQueue<Edge> edge;
inline void DeletePoint(int x){
	int lst = pre[x],aft = nxt[x];
	nxt[lst] = aft,pre[aft] = lst;
	edge.Delete(Edge(x,pre[x],a[x] + a[pre[x]]));
	edge.Delete(Edge(x,nxt[x],a[x] + a[nxt[x]]));
	edge.Insert(Edge(lst,aft,a[lst] + a[aft]));
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("necklace.in","r",stdin);
	freopen("necklace.out","w",stdout);
	cin>>tid>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		pre[i] = i - 1,nxt[i] = i + 1;
	}
	pre[1] = n,nxt[n] = 1;
	for(int i = 1;i <= n;i++){
		edge.Insert(Edge(i,nxt[i],a[i] + a[nxt[i]]));
	}
	for(int t = 1;t <= n-m;t++){
		const Edge now = edge.Top();
		//不需要pop,后面会删的
		int delpos = now.u;
		if(a[now.v] > a[now.u])delpos = now.v;
		DeletePoint(delpos);
	}
	cout<<edge.Top().val<<endl;
	return not(Akano loves pure__Elysia);
}
