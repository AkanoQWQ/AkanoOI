#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXK = 2e5 + 1018 + 1108;
struct Node {
	int a,b,c,id,sz;
} nodes[MAXN];
bool operator<(Node na,Node nb) {
	if(na.b != nb.b)return na.b < nb.b;
	if(na.c != nb.c)return na.c < nb.c;
	if(na.a != nb.a)return na.a < nb.a;
	return na.id < nb.id;
}
bool Cmp4A(Node na,Node nb) {
	if(na.a != nb.a)return na.a < nb.a;
	if(na.b != nb.b)return na.b < nb.b;
	if(na.c != nb.c)return na.c < nb.c;
	return na.id < nb.id;
}
using pivn = pair<int,vector<Node> >;
int inn,n,k,ans[MAXN],f[MAXN];
class SegmentTree {
	private:
		int val[MAXK * 4];
		bool clear[MAXK * 4];
		inline void PushUp(int p) {
			val[p] = val[p*2] + val[p*2+1];
			return ;
		}
		inline void PushDown(int p) {
			if(!clear[p])return ;
			val[p*2] = val[p*2+1] = 0;
			clear[p*2] = clear[p*2+1] = true;
			clear[p] = false;
			return ;
		}
		void Change(int p,int l,int r,int OBJ,int _val) {
			if(l == r) {
				val[p] += _val;
				return ;
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			if(mid >= OBJ)Change(p*2,l,mid,OBJ,_val);
			if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,_val);
			PushUp(p);
			return ;
		}
		int Query(int p,int l,int r,int OBJL,int OBJR) {
			if(OBJL <= l && r <= OBJR) {
				return val[p];
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			int ret = 0;
			if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
			return ret;
		}
	public:
		inline void Change(int pos,int _val) {
			Change(1,1,k,pos,_val);
			return ;
		}
		inline int Query(int l,int r) {
			return Query(1,1,k,l,r);
		}
		inline void Clear() {
			val[1] = 0;
			clear[1] = true;
			return ;
		}
} tr;
pivn Solve(int l,int r) {
	pivn ret;
	ret.first = 0;
	if(l == r) {
		ret.second.push_back(nodes[l]);
		return ret;
	}
	const int mid = (l + r) >> 1;
	pivn ans1 = Solve(l,mid),ans2 = Solve(mid+1,r);
	merge(ans1.second.begin(),ans1.second.end(),ans2.second.begin(),ans2.second.end(),back_inserter(ret.second));
	ret.first += ans1.first + ans2.first;
	auto tail = ans1.second.begin();
	tr.Clear();
	for(auto i : ans2.second) {
		while(tail != ans1.second.end() && (*tail).b <= i.b) {
			tr.Change((*tail).c,(*tail).sz);
			tail++;
		}
		const int _ADD = tr.Query(1,i.c);
		ans[i.id] += _ADD;
		ret.first += _ADD;
	}
	return ret;
}
map<pair<int,pair<int,int> >,int> getin;
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("P3810.in","r",stdin);
	cin>>inn>>k;
	for(int i = 1; i <= inn; i++) {
		int a,b,c;
		cin>>a>>b>>c;
		getin[ {a,{b,c}}]++;
	}
	for(auto i : getin) {
		nodes[++n] = {i.first.first,i.first.second.first,i.first.second.second};
		nodes[n].id = n,nodes[n].sz = i.second;
	}
	sort(nodes+1,nodes+n+1,Cmp4A);
	Solve(1,n);
	for(int i = 1; i <= inn; i++) {
		const int id = nodes[i].id;
		f[ans[id] + nodes[i].sz - 1] += nodes[i].sz;
	}
	for(int i = 0; i < inn; i++) {
		cout<<f[i]<<endl;
	}
	return 0;
}

