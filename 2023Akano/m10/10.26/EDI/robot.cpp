#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
const int INF = 1e9 + 1018 + 1108;
int n,len,endPos;
char cmd[MAXN];
int t[MAXN];
vector<int> rk;
int maxdeltaTime,maxPos;
class SegmentTree{
private:
	struct Node{
		int delta,mn,mx;
		Node(){
			delta = 0,mn = INF,mx = -INF;
			return ;
		}
	}node[MAXN * 4];
	inline void PushUp(int p){
		node[p].delta = node[p*2].delta + node[p*2+1].delta;
		node[p].mn = min(node[p*2+1].mn,node[p*2].mn + node[p*2+1].delta);
		node[p].mx = max(node[p*2+1].mx,node[p*2].mx + node[p*2+1].delta);
		node[p].mn = max(node[p].mn,0);
		node[p].mx = min(node[p].mx,len);
		return ;
	}
	void Change(int p,int l,int r,int pos){
		if(l == r){
			if(cmd[pos] == '+'){
				node[p].delta = 1;
			}else{
				node[p].delta = -1;
			}
			node[p].mn = len,node[p].mx = 0;
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= pos)Change(p*2,l,mid,pos);
		if(mid < pos)Change(p*2+1,mid+1,r,pos);
		PushUp(p);
		return ;
	}
public:
	inline void Change(int pos){
		Change(1,1,n,pos);
		return ;
	}
	inline pair<int,int> GetRoot(){
		return {node[1].mn,node[1].mx};
	}
}tr;
inline int DeltaT(int x){
	return t[x] - t[x-1];
}
bool Cmp(int x,int y){
	return DeltaT(x) < DeltaT(y);
}
inline int Solve(int x,int maxDelta){
	for(int i = 2;i <= n;i++){
		if(t[i] - t[i-1] <= maxDelta){
			if(cmd[i] == '+'){
				x = max(0,min(len,x+1));
			}else{
				x = max(0,min(len,x-1));
			}
		}
	}
	if(x < endPos)return -1;
	if(x == endPos)return 0;
	if(x > endPos)return 1;
	return 10181108;
}
inline void SolvePos(){
	for(int i = len;i >= 0;i--){
		if(Solve(i,DeltaT(rk[maxdeltaTime+1]) - 1) == 0){
			maxPos = i;
			return ;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("robot/robot3.in","r",stdin);
//	freopen("robot.out","w",stdout);
	cin>>n>>len>>endPos;
	for(int i = 1;i <= n;i++){
		cin>>cmd[i]>>t[i];
		rk.push_back(i);
	}
	sort(rk.begin(),rk.end(),Cmp);
	rk.insert(rk.begin(),0);
	for(int nowtime = 1;nowtime <= n;nowtime++){
		tr.Change(rk[nowtime]);
		while(nowtime + 1 <= n && DeltaT(rk[nowtime+1]) == DeltaT(rk[nowtime])){
			nowtime++;
			tr.Change(rk[nowtime]);
		}
		auto it = tr.GetRoot();
		if(it.first == endPos || it.second == endPos){
			maxdeltaTime = nowtime;
		}
	}
	if(maxdeltaTime == n){
		cout<<"infinity"<<endl;
	}else{
		SolvePos();
		cout<<DeltaT(rk[maxdeltaTime+1]) - 1<<" "<<maxPos<<endl;
	}
	return not(Akano loves pure__Elysia);
}
