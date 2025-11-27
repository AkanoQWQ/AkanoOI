#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 19961993;
const int MAXN = 1e5 + 6; 
const int n = 100000;
int pr[62],tail;
struct Node{
	int c[62];
	inline int& operator[](const int& _x){
		return c[_x];
	}
	inline void Init(){
		memset(c,0,sizeof(c));
		return ;
	}
	Node(){Init();}
};
Node Decompose(int _val){
	Node ret;
	for(int i = 1;i <= 60;i++){
		while(_val % pr[i] == 0){
			ret[i]++;
			_val /= pr[i];
		}
	}
	return ret;
}
Node operator+(Node _a,Node _b){
	Node ret;
	for(int i = 1;i <= 60;i++)ret[i] = _a[i] + _b[i];
	return ret;
}
ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
inline void PreGetPr(){
	for(int i = 2;i <= 10181108;i++){
		bool ISP = true;
		const int up = sqrt(i);
		for(int j = 2;j <= up;j++){
			if(i % j == 0){
				ISP = false;
				break;
			}
		}
		if(ISP)pr[++tail] = i;
		if(tail == 60)break;
	}
	return ;
}
class SegmentTree{
	private:
		Node node[MAXN * 4];
		inline void PushUp(const int& p){
			node[p] = node[p*2] + node[p*2+1];
			return ;
		}
		void Build(int p,int l,int r){
			if(l == r){
				node[p][2] = 1;
				return ;
			}
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid);
			Build(p*2+1,mid+1,r);
			PushUp(p);
			return ;
		}
		void Change(int p,int l,int r,int OBJ,int _val){
			if(l == r){
				node[p] = Decompose(_val);
				return ;
			}
			const int mid = (l + r) >> 1;
			if(OBJ <= mid)Change(p*2,l,mid,OBJ,_val);
			if(OBJ > mid)Change(p*2+1,mid+1,r,OBJ,_val);
			PushUp(p);
			return ;
		}
		Node Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				return node[p];
			}
			const int mid = (l + r) >> 1;
			Node ret;
			if(mid >= OBJL)ret = Query(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)ret = ret + Query(p*2+1,mid+1,r,OBJL,OBJR);
			return ret;
		}
	public:
		inline void Build(){
			Build(1,1,n);
			return ;
		}
		inline void Change(int pos,int _val){
			Change(1,1,n,pos,_val);
			return ;
		}
		inline Node Query(int l,int r){
			return Query(1,1,n,l,r);
		}
}tr;
inline ll UPD(ll _x){
	if(_x < 0)_x += MOD;
	return _x;
}
inline ll Ask(int l,int r){
	Node now = tr.Query(l,r);
	ll ret = 1;
	for(int i = 1;i <= 60;i++){
		if(now[i] > 0){
			ret = (ret * UPD(KSM(pr[i],now[i]) - KSM(pr[i],now[i]-1))) % MOD;
		}
	}
	return ret;
}
int q;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	PreGetPr();
	cin>>q;
	tr.Build();
	while(q--){
		int opt,x,y;
		cin>>opt>>x>>y;
		if(opt == 0){
			cout<<Ask(x,y)<<endl;
		}else{
			tr.Change(x,y);
		}
	}
	return 0;
}

