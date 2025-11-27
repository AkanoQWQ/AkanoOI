#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXN = 2e5 + 6;
const int INF = 1e9;
int n,arr1[MAXN],arr2[MAXN],marr[MAXN];
class SegmentTree{
	private:
		int mn[MAXN * 4],pos[MAXN * 4];
		int* arr;
		inline void PushUp(int p){
			if(mn[p*2] < mn[p*2+1]){
				mn[p] = mn[p*2],pos[p] = pos[p*2];
			}else{
				mn[p] = mn[p*2+1],pos[p] = pos[p*2+1];
			}
			return ;
		}
		void Build(int p,int l,int r){
			if(l == r){
				mn[p] = arr[l],pos[p] = l;
				return ;
			}
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			PushUp(p);
			return ;
		}
		int Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				return pos[p];
			}
			const int mid = (l + r) >> 1;
			int ret1 = 0,ret2 = 0;
			if(mid >= OBJL)ret1 = Query(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)ret2 = Query(p*2+1,mid+1,r,OBJL,OBJR);
			if(arr[ret1] < arr[ret2]){
				return ret1;
			}else{
				return ret2;
			}
		}
	public:
		inline void Build(int* _arr){
			arr = _arr;
			Build(1,1,n);
			return ;
		}
		inline int Query(int l,int r){
			int ret = Query(1,1,n,l,r);
			return ret;
		}
}tr1,tr2;
struct Node{
	int l,r,pos;
	Node(){}
	inline int Val(){
		if(l & 1){
			return tr1.Query(l,r);
		}else{
			return tr2.Query(l,r);
		}
	}
	Node(int _l,int _r){l = _l,r = _r,pos = Val();}
};
bool operator<(Node na,Node nb){
	return marr[na.pos] > marr[nb.pos];
}
priority_queue<Node> q;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	arr1[0] = arr2[0] = marr[0] = INF;
	for(int i = 1;i <= n;i++){
		arr1[i] = arr2[i] = INF;
		cin>>marr[i];
		if(i & 1){
			arr1[i] = marr[i];
		}else{
			arr2[i] = marr[i];
		}
	}
	tr1.Build(arr1),tr2.Build(arr2);
	q.push(Node(1,n));
	while(!q.empty()){
		Node tp = q.top();
		q.pop();
		auto pos1 = tp.pos,pos2 = 0;
		if(pos1 & 1){
			pos2 = tr2.Query(pos1,tp.r);
		}else{
			pos2 = tr1.Query(pos1,tp.r);
		}
		cout<<marr[pos1]<<" "<<marr[pos2]<<" ";
		if(pos1-1 > tp.l)q.push(Node(tp.l,pos1-1));
		if(pos2-1 > pos1+1)q.push(Node(pos1+1,pos2-1));
		if(tp.r > pos2)q.push(Node(pos2,tp.r));
	}
	return 0;
}
