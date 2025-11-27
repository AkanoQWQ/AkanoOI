#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
template<int SIZE,int _inf = 1000000000>
class SBST{//Segment Binary Search Tree
private:
	struct Node{
		int l,r,tot;
	}node[SIZE];
	int tot,root;
	inline void PushUp(int p){
		node[p].tot = node[node[p].l].tot + node[node[p].r].tot;
		return ;
	}
	int Change(int p,int l,int r,int OBJ,int _val){
		if(!p)p = ++tot;
		if(l == r){
			node[p].tot += _val;
			return p;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)node[p].l = Change(node[p].l,l,mid,OBJ,_val);
		if(mid < OBJ)node[p].r = Change(node[p].r,mid+1,r,OBJ,_val);
		PushUp(p);
		return p;
	}
	inline int GetPreTot(int p,int l,int r,int _val){
		if(!p)return 0;
		if(l == r){
			return (l >= _val);
		}
		const int mid = (l + r) >> 1;
		if(_val <= mid)return GetPreTot(node[p].l,l,mid,_val);
		return node[node[p].l].tot + GetPreTot(node[p].r,mid+1,r,_val);
	}
	int GetVal(int p,int l,int r,int k){
		if(l == r)return l;
		const int mid = (l + r) >> 1;
		if(k <= node[node[p].l].tot){
			return GetVal(node[p].l,l,mid,k);
		}
		return GetVal(node[p].r,mid+1,r,k - node[node[p].l].tot);
	}
	int GetCnt(int p,int l,int r,int OBJ){
		if(!p)return 0;
		if(l == r){
			return node[p].tot;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)return GetCnt(node[p].l,l,mid,OBJ);
		return GetCnt(node[p].r,mid+1,r,OBJ);
	}
public:
	inline void Insert(int _val){
		root = Change(root,-_inf,_inf,_val,1);
		return ;
	}
	inline void Erase(int _val){
		root = Change(root,-_inf,_inf,_val,-1);
		return ;
	}
	inline int GetRank(int _val){
		Insert(_val);
		int ret = GetPreTot(root,-_inf,_inf,_val);
		Erase(_val);
		return ret;
	}
	inline int GetVal(int k){
		return GetVal(root,-_inf,_inf,k);
	}
	inline int GetPre(int _val){
		int rank = GetRank(_val);
		if(rank == 1)return -_inf;
		int ret = GetVal(rank-1);
		return ret;
	}
	inline int GetNext(int _val){
		int rank = GetRank(_val) + GetCnt(root,-_inf,_inf,_val) - 1;
		if(rank == node[root].tot)return _inf;
		int ret = GetVal(rank+1);
		return ret;
	}
};
SBST<MAXN * 20> tr;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("P3369_1.in","r",stdin);
	int n;
	cin>>n;
	while(n--){
		int opt,x;
		cin>>opt>>x;
		if(opt == 1){
			tr.Insert(x);
		}else if(opt == 2){
			tr.Erase(x);
		}else if(opt == 3){
			cout<<tr.GetRank(x)<<'\n';
		}else if(opt == 4){
			cout<<tr.GetVal(x)<<'\n';
		}else if(opt == 5){
			cout<<tr.GetPre(x)<<'\n';
		}else if(opt == 6){
			cout<<tr.GetNext(x)<<'\n';
		}
	}
	return not(Akano loves pure__Elysia);
}
