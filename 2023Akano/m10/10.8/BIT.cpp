#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

template<int SIZE,typename T = int>
class BIT{
private:
	T val[SIZE];
	inline int Lowbit(int x){
		return x & (-x);
	}
	inline T QueryPre(int x){
		T ret = 0;
		while(x){
			ret += val[x];
			x -= Lowbit(x);
		}
		return ret;
	}
	class Reference{
	private:
		friend class BIT;
		BIT* source;
		int pos;
	public:
		Reference& operator+=(T _val){
			source->Change(pos,_val);
			return *this;
		}
		Reference() = default;
		Reference(BIT* _source,int _pos){
			source = _source,pos = _pos;
			return ;
		}
	};
public:
	inline void Change(int x,T _val){
		while(x <= SIZE){
			val[x] += _val;
			x += Lowbit(x);
		}
		return ;
	}
	inline T Query(int l,int r){
		return QueryPre(r) - QueryPre(l-1);
	}
	inline void Clear(){
		memset(val,0,sizeof(val));
		return ;
	}
	BIT(){Clear();}
	Reference operator[](int x){
		return Reference(this,x);
	}
	Reference operator()(int x){
		return Reference(this,x);
	}
	T operator[](pair<int,int> lr){
		return Query(lr.first,lr.second);
	}
	T operator()(int l,int r){
		return Query(l,r);
	}
};
BIT<1024> bit;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	bit(1) += 2;
	bit(5) += 3;
	cout<<bit(1,6)<<endl;
	return not(Akano loves pure__Elysia);
}
