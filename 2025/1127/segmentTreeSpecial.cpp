#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
template<typename ElementType>
class SegmentTree{
private:
	using sizeT = int;
	struct Node{
		sizeT length;
		ElementType value,lazyTag;
		Node(){
			value = lazyTag = length = 0;
			return ;
		}
	};
	using Nodep = Node*;
	sizeT size;
	Nodep node;
	template<typename ArrayType>
	void Build(sizeT p,sizeT l,sizeT r,ArrayType _array){
		if(l == r){
			node[p].length = 1,node[p].lazyTag = 0;
			node[p].value = _array[l];
			return ;
		}
		const sizeT mid = (l + r) >> 1;
		Build(p*2,l,mid,_array),Build(p*2+1,mid+1,r,_array);
		node[p].length = node[p*2].length + node[p*2+1].length;
		PushUp(p);
		return ;
	}
	void Build(sizeT p,sizeT l,sizeT r){
		if(l == r){
			node[p].length = 1,node[p].lazyTag = 0;
			node[p].value = 0;
			return ;
		}
		const sizeT mid = (l + r) >> 1;
		Build(p*2,l,mid),Build(p*2+1,mid+1,r);
		node[p].length = node[p*2].length + node[p*2+1].length;
		PushUp(p);
		return ;
	}
	inline void Add(sizeT p,ElementType delta){
		node[p].value += node[p].length * delta;
		node[p].lazyTag += delta;
		return ;
	}
	inline void PushDown(sizeT p){
		Add(p*2,node[p].lazyTag),Add(p*2+1,node[p].lazyTag);
		node[p].lazyTag = 0;
		return ;
	}
	inline void PushUp(sizeT p){
		node[p].value = node[p*2].value + node[p*2+1].value;
		return ;
	}
	void Change(sizeT p,sizeT l,sizeT r,sizeT OBJL,sizeT OBJR,ElementType delta){
		if(OBJL <= l && r <= OBJR){
			Add(p,delta);
			return ;
		}
		const sizeT mid = (l + r) >> 1;
		PushDown(p);
		if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,delta);
		if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,delta);
		PushUp(p);
		return ;
	}
	ElementType Query(sizeT p,sizeT l,sizeT r,sizeT OBJL,sizeT OBJR){
		if(OBJL <= l && r <= OBJR){
			return node[p].value;
		}
		const sizeT mid = (l + r) >> 1;
		PushDown(p);
		ElementType ret = 0;
		if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR);
		if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
		return ret;
	}
public:
	inline void ReSize(sizeT _size){
		delete node;
		size = _size;
		node = new Node[size * 4 + 2];
		Build(1,1,size);
		return ;
	}
	template<typename ArrayType>
	inline void SetArray(ArrayType _array,sizeT newSize){
		ReSize(newSize);
		Build(1,1,size,_array);
		return ;
	}
	friend class Reference;
	class Reference{
	private:
		SegmentTree* source;
		sizeT l,r;
	public:
		operator ElementType(){
			return source->Query(1,1,source->size,l,r);
		}
		Reference operator+=(ElementType delta){
			source->Change(1,1,source->size,l,r,delta);
			return *this;
		}
		Reference operator-=(ElementType delta){
			return operator+=(-delta);
		}
		Reference(SegmentTree* _source,sizeT _l,sizeT _r){
			source = _source,l = _l,r = _r;
			return ;
		}
	};
	Reference operator()(sizeT l,sizeT r){
		return Reference(this,l,r);
	}
	SegmentTree(){
		node = nullptr;
		return ;
	}
};
SegmentTree<ll> seg;
ll* inarr;
int n,q;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	inarr = new ll[n+1];
	for(int i = 1;i <= n;i++){
		cin>>inarr[i];
	}
	seg.SetArray(inarr,n);
	delete inarr;
	while(q--){
		int opt,l,r;
		ll k;
		cin>>opt;
		if(opt == 1){
			cin>>l>>r>>k;
			seg(l,r) += k;
		}else{
			cin>>l>>r;
			cout<<seg(l,r)<<'\n';
		}
	}
	return not(Akano loves pure__Elysia);
}