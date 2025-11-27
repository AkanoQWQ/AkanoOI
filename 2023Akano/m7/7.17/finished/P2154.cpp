#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXW = 1e5 + 6;
const int MAXK = 14;
ostream& operator<<(ostream& cout,pii _pii){
	cout<<"("<<_pii.first<<","<<_pii.second<<")";
	return cout;
}
inline bool Cmp4Point(pii p1,pii p2){
	if(p1.first == p2.first)return p1.second < p2.second;
	return p1.first < p2.first;
}
int useless,w,upper[MAXW],lower[MAXW],k;
class SegmentTree{
	private:
		unsigned int val[MAXW * 4];
		inline void PushUp(int p){
			val[p] = val[p*2] + val[p*2+1];
			return ;
		}
		void Change(int p,int l,int r,int OBJ,unsigned int _val){
			if(l == r){
				val[p] = _val;
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJ)Change(p*2,l,mid,OBJ,_val);
			if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,_val);
			PushUp(p);
			return ;
		}
		unsigned int Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				return val[p];
			}
			const int mid = (l + r) >> 1;
			unsigned int ret = 0;
			if(mid >= OBJL)ret = Query(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
			return ret;
		}
	public:
		inline void Change(int pos,unsigned int _val){
			Change(1,1,w,pos,_val);
		}
		inline unsigned int Query(int l,int r){
			if(l > r)return 0;
			return Query(1,1,w,l,r);
		}
}tr;
unsigned int C[MAXW][MAXK];
set<int> xSet,ySet;
vector<int> xVec,yVec,py[MAXW];
pii p[MAXW];
inline void PreInput(){
	cin>>useless>>useless>>w;
	for(int i = 1;i <= w;i++){
		cin>>p[i].first>>p[i].second;
		xSet.insert(p[i].first),ySet.insert(p[i].second);
	}
	xVec.reserve(xSet.size()),yVec.reserve(ySet.size());
	while(!xSet.empty()){
		xVec.push_back(*(xSet.begin()));
		xSet.erase(xSet.begin());
	}
	while(!ySet.empty()){
		yVec.push_back(*(ySet.begin()));
		ySet.erase(ySet.begin());
	}
	for(int i = 1;i <= w;i++){
		p[i].first = lower_bound(xVec.begin(),xVec.end(),p[i].first) - xVec.begin() + 1;
		p[i].second = lower_bound(yVec.begin(),yVec.end(),p[i].second) - yVec.begin() + 1;
		upper[p[i].second]++;
	}
	cin>>k;
	sort(p+1,p+w+1,Cmp4Point);
	for(int i = 1;i <= w;i++){
		py[p[i].first].push_back(p[i].second);
	}
	return ;
}
inline void PreCalc(){
	for(int i = 0;i <= w;i++)C[i][0] = 1;
	for(int i = 1;i <= w;i++){
		for(int j = 1;j <= k;j++){
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
	return ;
}
inline void Edit(int ey){
	lower[ey]++,upper[ey]--;
	const unsigned int upd = 1ll * C[lower[ey]][k] * C[upper[ey]][k];
	tr.Change(ey,upd);
	return ;
}
inline unsigned int Solve(){
	unsigned int ret = 0;
	for(int nowx = 0;nowx <= w;nowx++){
		if(py[nowx].empty())continue;
		py[nowx].push_back(-1);
		for(int tail = 0;tail < int(py[nowx].size()-1);tail++){
			const int now = py[nowx][tail],nxt = py[nowx][tail+1];
			Edit(now);
			const unsigned int poss = 1ll * C[tail+1][k] * C[py[nowx].size()-tail-2][k];
			const unsigned int yposs = tr.Query(now+1,nxt-1);
			ret += poss * yposs;
		}
	}
	if(ret >= (1ll<<31))ret -= (1ll<<31);
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	PreInput();
	PreCalc();
	cout<<Solve();
	return 0;
}
