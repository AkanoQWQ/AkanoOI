#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
using ll = long long;
const int MAXN = 5e4 + 1018 + 1108;
const int MAXP = 506;
const ll INF = 1e14;
int n,mod;
ll cache[MAXP];
struct Package{
	ll val[MAXP];
	inline void Add(int w,int v){
		for(int i = 0;i <= mod;i++){
			cache[i] = -INF;
		}
		for(int i = 0;i < mod;i++){
			cache[(i + w) % mod] = max(cache[(i + w) % mod],val[i] + v);
		}
		for(int i = 0;i < mod;i++){
			val[i] = max(val[i],cache[i]);
		}
		return ;
	}
	Package(){
		for(int i = 0;i <= mod;i++){
			val[i] = -INF;
		}
		val[0] = 0;
		return ;
	}
};
ll ans[MAXN];
class SegmentTree{
private:
	struct Node{
		vector<pii> element;
		int queryNum,queryL,queryR,queryID;
	}node[MAXN * 4];
	inline void PushUp(int p){
		node[p].queryNum = node[p*2].queryNum + node[p*2+1].queryNum;
		return ;
	}
	void Insert(int p,int l,int r,int OBJL,int OBJR,pii object){
		if(OBJL <= l && r <= OBJR){
			node[p].element.push_back(object);
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJL)Insert(p*2,l,mid,OBJL,OBJR,object);
		if(mid < OBJR)Insert(p*2+1,mid+1,r,OBJL,OBJR,object);
		return ;
	}
	void Execute(int p,int l,int r,Package now){
		for(auto ele : node[p].element){
			now.Add(ele.first,ele.second);
		}
		if(l == r){
			for(int i = node[p].queryL;i <= node[p].queryR;i++){
				ans[node[p].queryID] = max(ans[node[p].queryID],now.val[i]);
			}
			return ;
		}
		const int mid = (l + r) >> 1;
		if(node[p*2].queryNum >= 1)Execute(p*2,l,mid,now);
		if(node[p*2+1].queryNum >= 1)Execute(p*2+1,mid+1,r,now);
		return ;
	}
	void PushQuery(int p,int l,int r,int OBJ,int _queryL,int _queryR,int _queyrID){
		if(l == r){
			node[p].queryL = _queryL,node[p].queryR = _queryR,node[p].queryID = _queyrID;
			node[p].queryNum++;
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)PushQuery(p*2,l,mid,OBJ,_queryL,_queryR,_queyrID);
		if(mid < OBJ)PushQuery(p*2+1,mid+1,r,OBJ,_queryL,_queryR,_queyrID);
		PushUp(p);
		return ;
	}
public:
	inline void Insert(int l,int r,pii object){
		Insert(1,1,n,l,r,object);
		return ;
	}
	inline void Execute(){
		Package emp;
		Execute(1,1,n,emp);
		return ;
	}
	inline void PushQuery(int pos,int _queryL,int _queryR,int _queryID){
		PushQuery(1,1,n,pos,_queryL,_queryR,_queryID);
		return ;
	}
}tr;
pii object[MAXN];
deque<int> device;//device可还行
int nowID,queryCnt,startTime[MAXN],endTime[MAXN];
int main(){
	//"为了锻炼你的水平，请尽量使用在线做法。"
	//实在不会在线做法啊（-_-||）  锻炼不了一点
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("tanwan.in","r",stdin);
	freopen("tanwan.out","w",stdout);
	cin>>n>>mod;
	for(int i = 1;i <= n;i++){
		string opt;
		cin>>opt;
		if(opt == "QU"){
			int l,r;
			cin>>l>>r;
			tr.PushQuery(i,l,r,++queryCnt);
			ans[queryCnt] = -INF;
		}else if(opt == "IF"){
			nowID++;
			cin>>object[nowID].first>>object[nowID].second;
			startTime[nowID] = i;
			device.push_front(nowID);
		}else if(opt == "IG"){
			nowID++;
			cin>>object[nowID].first>>object[nowID].second;
			startTime[nowID] = i;
			device.push_back(nowID);
		}else if(opt == "DF"){
			const int u = device.front();
			device.pop_front();
			endTime[u] = i;
		}else if(opt == "DG"){
			const int u = device.back();
			device.pop_back();
			endTime[u] = i;
		}
	}
	while(!device.empty()){
		const int u = device.front();
		device.pop_front();
		endTime[u] = n;
	}
	for(int i = 1;i <= nowID;i++){
		tr.Insert(startTime[i],endTime[i],object[i]);
	}
	tr.Execute();
	for(int i = 1;i <= queryCnt;i++){
		if(ans[i] < 0)ans[i] = -1;
		cout<<ans[i]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
