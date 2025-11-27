#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MAXQ = 4e5 + 1018 + 1108;
const int MAXN = 6e5 + 1018 + 1108;
int no,n,m,q;
ll ans;
struct Code{
	int type,pos,l,r,w;
	Code(){
		type = l = r = pos = w = 0;
	}
};
struct Operation{
	int type,_x1,_y1,_x2,_y2;
	inline void Read(){
		cin>>type>>_x1>>_y1>>_x2>>_y2;
		if(_x1 > _x2)swap(_x1,_x2);
		if(_y1 > _y2)swap(_y1,_y2);
		return ;
	}
}op[MAXQ];
ostream& operator<<(ostream& cout,Operation opt){
	cout<<opt._x1<<","<<opt._y1<<" to "<<opt._x2<<","<<opt._y2;
	return cout;
}
vector<Code> codes;
inline void Add1(int l,int r,int pos){
	Code ret;
	ret.type = 1,ret.l = l,ret.r = r,ret.pos = pos;
	codes.push_back(ret);
	return ;
}
inline void Add2(int point,int ST,int ED){
	Code ret;
	ret.type = 2,ret.l = ret.r = point,ret.pos = ST,ret.w = 1;
	codes.push_back(ret);
	ret.type = 2,ret.l = ret.r = point,ret.pos = ED+1,ret.w = -1;
	codes.push_back(ret);
	return ;
}
bool Cmp4Operation(Operation o1,Operation o2){
	if(o1.type != o2.type)return o1.type < o2.type;
	if(o1.type == 1){
		if(o1._y1 != o2._y1)return o1._y1 < o2._y1;
		return o1._x1 < o2._x1;
	}
	if(o1.type == 2){
		if(o1._x1 != o2._x1)return o1._x1 < o2._x1;
		return o1._y1 < o2._y1;
	}
	return o1._x1 < o2._x1;
}
bool Cmp4Code(Code c1,Code c2){
	if(c1.pos != c2.pos)return c1.pos < c2.pos;
	if(c1.type != c2.type)return c1.type > c2.type;//type2 ÔÚÇ°Ãæ
	if(c1.l != c2.l)return c1.l < c2.l;
	return c1.r < c2.r;
}
inline void Cut(Operation& op1,Operation& op2){
	const int delta = op2._y1 - op2._x1;
	if(op1._x1 - op2._x2 == op1._y1 - op2._y2){
		if(op1._x1 <= op2._x1 && op2._x2 <= op1._x2){//include
			op2._x1 = op2._x2 + 1;
		}else if(op1._x1 <= op2._x1 && op2._x1 <= op1._x2){
			op2._x1 = op1._x2+1;
		}else if(op1._x1 <= op2._x2 && op2._x2 <= op1._x2){
			op2._x2 = op1._x1-1;
		}else if(op2._x1 <= op1._x1 && op1._x2 <= op2._x2){//include
			op1._x1 = op1._x2 + 1;
		}else if(op2._x1 <= op1._x1 && op1._x1 <= op2._x2){
			op1._x1 = op2._x2+1;
		}else if(op2._x1 <= op1._x2 && op1._x2 <= op2._x2){
			op1._x2 = op2._x1-1;
		}
		op2._y1 = op2._x1 + delta;
		op2._y2 = op2._x2 + delta;
		op1._y1 = op1._x1 + delta;
		op1._y2 = op1._x2 + delta;
	}
	return ;
}
class SegmentTree{
	private:
		int val[MAXN * 4];
		inline void PushUp(int p){
			val[p] = val[p*2] + val[p*2+1];
			return ;
		}
		void Change(int p,int l,int r,int OBJ,int _val){
			if(l == r){
				val[p] += _val;
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJ)Change(p*2,l,mid,OBJ,_val);
			if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,_val);
			PushUp(p);
			return ;
		}
		int Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				return val[p];
			}
			const int mid = (l + r) >> 1;
			int ret = 0;
			if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
			return ret;
		}
	public:
		int sz;
		inline void Change(int pos,int inval){
			Change(1,1,sz,pos,inval);
			return ;
		}
		inline int Query(int l,int r){
			return Query(1,1,sz,l,r);
		}
}tr;
inline ll Solve1(){
	ll ret = 0;
	int nowy = 0,nowr = -1018;
	for(int i = 1;i <= q;i++){
		if(op[i].type != 1)break;
		if(op[i]._y1 != nowy){
			nowr = -1018;
			nowy = op[i]._y1;
		}
		int st = op[i]._x1;
		st = max(st,nowr + 1);
		nowr = max(nowr,op[i]._x2);
		ret += max(op[i]._x2 - st + 1,0);
		if(op[i]._x2 >= st){
			Add1(st,op[i]._x2,op[i]._y1);
		}
	}
	return ret;
}
inline ll Pre2(){
	ll ret = 0;
	int nowx = 0,nowr = -1108;
	for(int i = 1;i <= q;i++){
		if(op[i].type != 2)continue;
		if(op[i]._x1 != nowx){
			nowr = -1108;
			nowx = op[i]._x1;
		}
		int st = op[i]._y1;
		st = max(st,nowr + 1);
		nowr = max(nowr,op[i]._y2);
		ret += max(op[i]._y2 - st + 1,0);
		if(op[i]._y2 >= st){
			Add2(op[i]._x1,st,op[i]._y2);
		}
	}
	return ret;
}
inline ll Solve2(){
	ll ret = Pre2();
	vector<int> vec;
	for(auto i : codes){
		vec.push_back(i.l),vec.push_back(i.r);
	} 
	sort(vec.begin(),vec.end());
	auto it = unique(vec.begin(),vec.end());
	vec.erase(it,vec.end());
	tr.sz = vec.size() + 10;
	sort(codes.begin(),codes.end(),Cmp4Code);
	for(auto i : codes){
		i.l = lower_bound(vec.begin(),vec.end(),i.l) - vec.begin() + 1;
		i.r = lower_bound(vec.begin(),vec.end(),i.r) - vec.begin() + 1;
		if(i.type == 1){
			ret -= tr.Query(i.l,i.r);
		} else {
			tr.Change(i.l,i.w);
		}
	}
	return ret;
}
inline ll Solve3(){
	ll ret = 0;
	set<pii> now;
	for(int i = q;i >= 1;i--){
		if(op[i].type != 3)break;
	}
	for(int i = q;i >= 1;i--){
		if(op[i].type != 3)break;
		if(op[i]._x1 > op[i]._x2)continue;
		for(int j = i-1;j >= 1;j--){
			if(op[j].type != 3)break;
			if(op[j]._x1 > op[j]._x2)continue;
			Cut(op[i],op[j]);
		}
	}
	for(int i = q;i >= 1;i--){
		if(op[i].type != 3)break;
		if(op[i]._x1 > op[i]._x2)continue;
//		cout<<op[i]<<" NOW "<<endl;
		ret += op[i]._x2 - op[i]._x1 + 1;
		for(int j = 1;j <= q;j++){
			if(op[j].type == 1){
				const int delta = op[j]._y1 - op[i]._y1;
				int nowx = op[i]._x1 + delta,nowy = op[i]._y1 + delta;
				if(op[i]._x1 <= nowx && nowx <= op[i]._x2 && op[j]._x1 <= nowx && nowx <= op[j]._x2){
					now.insert(make_pair(nowx,nowy));
				}
			}else if(op[j].type == 2){
				const int delta = op[j]._x1 - op[i]._x1;
				int nowx = op[i]._x1 + delta,nowy = op[i]._y1 + delta;
				if(op[i]._x1 <= nowx && nowx <= op[i]._x2 && op[j]._y1 <= nowy && nowy <= op[j]._y2){
					now.insert(make_pair(nowx,nowy));
				}
			}
		}
	}
	ret -= now.size();
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("color/color7.in","r",stdin);
	cin>>no>>n>>m>>q;
	for(int i = 1;i <= q;i++){
		op[i].Read();
	}
	sort(op+1,op+q+1,Cmp4Operation);
	ans += Solve1();
	ans += Solve2();
	ans += Solve3();
	cout<<ans<<endl;
	return 0;
}
