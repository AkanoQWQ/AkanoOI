#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
const double EPS = 1e-4;
const int INF = 1e9;
const int MOD1 = 39989;
const int MOD2 = 1e9;
const int SIZE = 39989;
struct Segment{
	double k,b;
	int id;
	Segment(){k = 0,b = -INF,id = 0;}
	inline double Calc(double x){
		return k * x + b;
	}
};
ostream& operator<<(ostream& cout,Segment seg){
	cout<<"("<<seg.k<<"*x+"<<seg.b<<")";
	return cout;
}
inline bool Cmp(Segment s1,Segment s2,double x){
	double _y1 = s1.Calc(x),_y2 = s2.Calc(x);
	if(fabs(_y1 - _y2) <= EPS){
		cerr<<"TEST SIM"<<endl;
		return s1.id < s2.id;
	}else{
		return _y1 > _y2;
	}
}
struct Answer{
	double val;
	int id;
	Answer(){val = 0,id = 0;}
	Answer(double _val,int _id){val = _val,id = _id;}
};
bool operator<(Answer a1,Answer a2){
	if(fabs(a1.val - a2.val) <= EPS){
		return a1.id > a2.id;
	}else{
		return a1.val < a2.val;
	}
}
class LiChaoSegmentTree{
	private:
		Segment lazy[MAXN * 4];
		void PushDown(int p,int l,int r,Segment v){
			Segment& u = lazy[p];
			const int mid = (l + r) >> 1;
			if(Cmp(v,u,mid))swap(u,v);//OK?
			bool psdL = Cmp(v,u,l),psdR = Cmp(v,u,r);
			if(psdL)PushDown(p*2,l,mid,v);
			if(psdR)PushDown(p*2+1,mid+1,r,v);
			return ;
		}
		void Change(int p,int l,int r,int OBJL,int OBJR,Segment v){
			if(OBJL <= l && r <= OBJR){
				PushDown(p,l,r,v);
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,v);
			if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,v);
			return ;
		}
		Answer Query(int p,int l,int r,int pos){
			Answer ret = Answer(lazy[p].Calc(pos),lazy[p].id);
			if(l == r)return ret;
			const int mid = (l + r) >> 1;
			if(mid >= pos)ret = max(ret,Query(p*2,l,mid,pos));
			if(mid < pos)ret = max(ret,Query(p*2+1,mid+1,r,pos));
			return ret;
		}
	public:
		inline void Change(int l,int r,Segment v){
			Change(1,1,SIZE,l,r,v);
			return ;
		}
		inline Answer Query(int pos){
			return Query(1,1,SIZE,pos);
		}
}tr;
int n,lastans,cnt;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		int opt,k,_x0,_x1,_y0,_y1;
		cin>>opt;
		if(opt == 0){
			cin>>k;
			k = ((k + lastans - 1) % MOD1) + 1;
			lastans = tr.Query(k).id;
			cout<<lastans<<'\n';
		}else if(opt == 1){
			cin>>_x0>>_y0>>_x1>>_y1;
			_x0 = ((_x0 + lastans - 1) % MOD1) + 1;
			_x1 = ((_x1 + lastans - 1) % MOD1) + 1;
			_y0 = ((_y0 + lastans - 1) % MOD2) + 1;
			_y1 = ((_y1 + lastans - 1) % MOD2) + 1;
			Segment ins;
			ins.id = ++cnt;
			if(_x0 == _x1){
				ins.k = 0,ins.b = max(_y0,_y1);
			}else{
				if(_x0 > _x1){
					swap(_x0,_x1),swap(_y0,_y1);
				}
				ins.k = 1.0 * (_y1 - _y0) / (_x1 - _x0),ins.b = _y1 - (_x1 * ins.k);
			}
			tr.Change(_x0,_x1,ins);
		}
	}
	return 0;
}
