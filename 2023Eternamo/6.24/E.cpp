#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
int n,k,A;
ll ans;
struct Point{
	int x,y,l,cost;
	Point(){
		x = y = l = cost = 0;
	}
	Point(int inx,int iny,int inl,int inc){
		x = inx,y = iny,l = inl,cost = inc;
	}
};
bool operator<(Point a,Point b){
	return a.l < b.l;
}
vector<Point> ps;
class SegmentTree{
	private:
		bool lazy[MAXN * 4];
		ll c[MAXN * 4];
		inline void PushDown(int p){
			if(!lazy[p])return ;
			c[p*2] = c[p*2+1] = 0;
			lazy[p*2] = lazy[p*2+1] = true;
			lazy[p] = false;
			return ;
		}
		inline void PushUp(int p){
			c[p] = c[p*2] + c[p*2+1];
			return ;
		}
		void Change(int p,int l,int r,int OBJ,ll val){
			if(l == r){//l == r == OBJ
				c[p] = val;
				return ;
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			if(mid >= OBJ)Change(p*2,l,mid,OBJ,val);
			if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,val);
			PushUp(p);
			return ;
		}
		void Clear(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				c[p] = 0,lazy[p] = true;
				return ;
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			if(mid >= OBJL)Clear(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)Clear(p*2+1,mid+1,r,OBJL,OBJR);
			PushUp(p);
			return ;
		}
		ll Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				return c[p];
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			ll ret = 0;
			if(mid >= OBJL)ret = Query(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
			return ret;
		}
	public:
		inline ll Query(int OBJL,int OBJR){
			return Query(1,0,n,OBJL,OBJR);
		}
		inline void Clear(int OBJL,int OBJR){
			Clear(1,0,n,OBJL,OBJR);
			return ;
		}
		inline void Change(int OBJ,ll val){
			Change(1,0,n,OBJ,val);
			return ;
		}
}tr;
int main(){
	//freopen("E.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>k>>A;
	for(int i = 1;i <= n;i++){
		int inx,iny,inc;
		cin>>inx>>iny>>inc;
		ps.push_back(Point(inx,iny,k-inx-iny,inc));
	}
	sort(ps.begin(),ps.end());
	for(auto i : ps){
		const int x1 = i.x,x2 = k - i.y;
		ll val1 = tr.Query(x1,x2) + i.cost;
		ll val2 = i.l * A;
		tr.Clear(x1,x2);
		tr.Change(x1,min(val1,val2));
	}
	cout<<tr.Query(0,k)<<endl;
	return 0;
}
//思路错了啊...没办法
//错误思路:以l为关键字排序,每个点的右上角点一定会优先处理掉
//然后用树状数组维护点的x坐标,在l排序后点的x坐标可以确定其右上角的点
//对应的x坐标的范围,然后用树状数组维护cost
//错误点:"关键点",即操作的点,不一定是题目中给出的点 
