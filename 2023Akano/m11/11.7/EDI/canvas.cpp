#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
constexpr int MAXN = 1e5 + 1018 + 1108;

template<int MaxSetSize>
class DisjointSetUnion{
private:
	int size;
	int setFather[MaxSetSize],setSize[MaxSetSize];
	inline int Find(int x){
		if(setFather[x] == x){
			return x;
		}
		return setFather[x] = Find(setFather[x]);
	}
public:
	inline void Init(int _size){
		size = _size;
		for(int i = 1;i <= size;i++){
			setFather[i] = i,setSize[i] = 1;
		}
		return ;
	}
	inline void GetFa(int x){
		return Find(x);
	}
	inline bool Merge(int u,int v){
		u = Find(u),v = Find(v);
		if(u == v)return false;
		if(setSize[u] < setSize[v])swap(u,v);//siz_u >= siz_u;
		setFather[v] = u,setSize[u] += setSize[v];
		return true;
	}
	inline bool ToGether(int u,int v){
		return Find(u) == Find(v);
	}
	DisjointSetUnion(){
		size = 0;
		return ;
	}
	DisjointSetUnion(int _size){
		size = _size;
		return ;
	}
};
template<int SIZE>
using DSU = DisjointSetUnion<SIZE>;

DSU<MAXN * 4> dset;
struct Operation{
	int l,r;
	Operation() = default;
	Operation(int _l,int _r){
		l = _l,r = _r;
		return ;
	}
};
bool operator<(Operation op1,Operation op2){
	if(op1.l != op2.l)return op1.l < op2.l;
	return op1.r < op2.r;
}
vector<Operation>optlr[MAXN],optud[MAXN],pushInlr[MAXN],pushInud[MAXN];
int n,m,q;
inline void Prepare(vector<Operation>& op){
	sort(op.begin(),op.end());
	vector<Operation> newop;
	for(auto it = op.begin();it != op.end();it++){
		if(it != op.begin() && it->l <= newop.back().r+1){
			newop.back().r = max(newop.back().r,it->r);
		}else{
			newop.push_back(*it);
		}
	}
	swap(op,newop);
	return ;
}
inline void PrepareTotal(){
	for(int i = 1;i <= m;i++){
		Prepare(optud[i]);
		for(auto op : optud[i]){
			pushInlr[op.l].emplace_back(i,i);
			pushInlr[op.r].emplace_back(i,i);
		}
	}
	for(int i = 1;i <= n;i++){
		for(auto op : pushInlr[i])optlr[i].push_back(op);
		pushInlr[i].clear();
		Prepare(optlr[i]);
		for(auto op : optlr[i]){
			pushInud[op.l].emplace_back(i,i);
		}
	}
	for(int i = 1;i < n;i++){
		auto it = optlr[i+1].begin();
		for(auto op : optlr[i]){
			while(it != optlr[i+1].end() && it->r < op.l){
				it++;
			}
			while(it != optlr[i+1].end() && it->r <= op.r){
				const int trans = max(op.l,it->r);
				pushInud[trans].emplace_back(i,i+1);
				it++;
			}
			if(it != optlr[i+1].end() && it->l <= op.r){
				const int trans = max(op.l,it->l);
				pushInud[trans].emplace_back(i,i+1);
			}
		}
	}
	for(int i = 1;i <= m;i++){
		for(auto op : pushInud[i])optud[i].push_back(op);
		pushInud[i].clear();
		Prepare(optud[i]);
	}
	return ;
}
inline void SolveTotal(){
	vector<int> offlineAdd[MAXN],offlineDelete[MAXN];
	set<pii> belong;
	set<int> kolora;//colored
	int nowans = 0,nowid = 0;
	belong.insert({-1,-10181108}),belong.insert({m+1,-10181108});
	kolora.insert(1),kolora.insert(m+1);
	for(int i = 1;i <= m;i++){//离线挂载
		for(auto op : optud[i]){
			offlineAdd[op.l].push_back(i);
			offlineDelete[op.r+1].push_back(i);
		}
	}
	const int DSIZE = q * 4;
	dset.Init(DSIZE);//enough?
	for(int scanLine = 1;scanLine <= n;scanLine++){
		for(auto offline : offlineAdd[scanLine]){
			nowans++;
			belong.insert({offline,++nowid});
			kolora.insert(offline);
			kolora.insert(offline+1);
		}
		for(auto offline : offlineDelete[scanLine]){
			auto it = belong.lower_bound({offline,-10181108});
			belong.erase(it);
		}
		for(auto op : optlr[scanLine]){
			const int nowl = max(1,op.l-1),nowr = min(m,op.r+1);
			auto lpos = kolora.upper_bound(nowl),rpos = kolora.upper_bound(nowr);
			for(auto it = lpos;it != rpos;it++){
				auto realL = belong.lower_bound({*it,-10181108}),realR = realL;
				realL--;
				if(realL->first < nowl || realR->first > nowr){
					continue;
				}
				bool suc = dset.Merge(realL->second,realR->second);
				nowans -= suc;
			}
			bool ers = true;
			if(lpos == rpos)ers = false;
			lpos++;
			if(lpos == rpos)ers = false;
			rpos--;
			if(lpos == rpos)ers = false;
			if(ers){
				kolora.erase(lpos,rpos);
			}
		}
		cout<<nowans<<'\n';
	}
	assert(nowid <= DSIZE);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("canvas/canvas3.in","r",stdin);
//	freopen("canvas.out","w",stdout);
	cin>>n>>m>>q;
	for(int i = 1,opt,p;i <= q;i++){
		Operation newop;
		cin>>opt>>p>>newop.l>>newop.r;
		if(opt == 0){
			optlr[p].push_back(newop);
		}else{
			optud[p].push_back(newop);
		}
	}
	PrepareTotal();
	SolveTotal();
	return not(Akano loves pure__Elysia);
}
