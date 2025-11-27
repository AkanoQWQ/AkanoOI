#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 2006 + 1018 + 1108;
struct Node{
	int mn,mx,cnt,leniwy,tag,lazy;//leniwy : lazy of mn
};
class SegmentTree{
	private:
		int SIZE;
		Node node[MAXN * 4];
		void Build(int p,int l,int r){
			node[p].cnt = r - l + 1;
			node[p].lazy = node[p].leniwy = node[p].mn = node[p].mx = node[p].tag = 0;
			if(l == r)return ;
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			return ;
		}
		inline void PushUp(int p){
			if(node[p*2].mn == node[p*2+1].mn){
				node[p].mn = node[p*2].mn;
				node[p].cnt = node[p*2].cnt + node[p*2+1].cnt;
			}else if(node[p*2].mn < node[p*2+1].mn){
				node[p].mn = node[p*2].mn;
				node[p].cnt = node[p*2].cnt;
			}else{
				node[p].mn = node[p*2+1].mn;
				node[p].cnt = node[p*2+1].cnt;
			}
			node[p].mx = max(node[p*2].mx,node[p*2+1].mx);
			node[p].tag = min(node[p*2].tag,node[p*2+1].tag);
			return ;
		}
		inline void PushDown(int p){
			if(node[p].lazy){
				node[p*2].tag = max(node[p*2].tag,node[p].lazy);
				node[p*2].lazy = max(node[p*2].lazy,node[p].lazy);
				node[p*2+1].tag = max(node[p*2+1].tag,node[p].lazy);
				node[p*2+1].lazy = max(node[p*2+1].lazy,node[p].lazy);
				node[p].lazy = 0;
			}
			if(node[p].leniwy){
				node[p*2].mn += node[p].leniwy;
				node[p*2].mx += node[p].leniwy;
				node[p*2].leniwy += node[p].leniwy;
				node[p*2+1].mn += node[p].leniwy;
				node[p*2+1].mx += node[p].leniwy;
				node[p*2+1].leniwy += node[p].leniwy;
				node[p].leniwy = 0;
			}
			return ;
		}
		int QueryPos(int p,int l,int r,int OBJ){
			if(l == r)return node[p].mn;
			PushDown(p);
			const int mid = (l + r) >> 1;
			if(mid >= OBJ)return QueryPos(p*2,l,mid,OBJ);
			if(mid < OBJ)return QueryPos(p*2+1,mid+1,r,OBJ);
			return 10181108;
		}
		void AddVal(int p,int l,int r,int OBJL,int OBJR,int _val){
			if(OBJL <= l && r <= OBJR){
				node[p].mn += _val;
				node[p].mx += _val;
				node[p].leniwy += _val;
				return ;
			}
			PushDown(p);
			const int mid = (l + r) >> 1;
			if(mid >= OBJL)AddVal(p*2,l,mid,OBJL,OBJR,_val);
			if(mid < OBJR)AddVal(p*2+1,mid+1,r,OBJL,OBJR,_val);
			PushUp(p);
			return ;
		}
		void AddTag(int p,int l,int r,int OBJL,int OBJR,int _val){
			if(OBJL <= l && r <= OBJR){
				node[p].tag += _val;
				node[p].lazy += _val;
				return ;
			}
			PushDown(p);
			const int mid = (l + r) >> 1;
			if(mid >= OBJL)AddTag(p*2,l,mid,OBJL,OBJR,_val);
			if(mid < OBJR)AddTag(p*2+1,mid+1,r,OBJL,OBJR,_val);
			PushUp(p);
			return ;
		}
		int QueryVal(int p,int l,int r,int OBJL,int OBJR,int k){
			if(node[p].mn == k){
				return r;
			}
			if(l == r)return l - 1;
			PushDown(p);
			const int mid = (l + r) >> 1;
			if(mid >= OBJL && mid < OBJR){
				int ret = QueryVal(p*2,l,mid,OBJL,OBJR,k);
				if(ret < mid){
					return ret;
				}else{
					return QueryVal(p*2+1,mid+1,r,OBJL,OBJR,k);
				}
			}else if(mid >= OBJL){
				return QueryVal(p*2,l,mid,OBJL,OBJR,k);
			}else if(mid < OBJR){
				return QueryVal(p*2+1,mid+1,r,OBJL,OBJR,k);
			}
			cout<<"CERR"<<endl;
			return 10181108;
		}
		int QueryTagMx1(int p,int l,int r,int OBJL,int OBJR){
			if(node[p].tag >= 1 && node[p].mx == 1){
				return r;
			}
			if(l == r)return l - 1;
			PushDown(p);
			const int mid = (l + r) >> 1;
			if(mid >= OBJL && mid < OBJR){
				int ret = QueryTagMx1(p*2,l,mid,OBJL,OBJR);
				if(ret < mid){
					return ret;
				}else{
					return QueryTagMx1(p*2+1,mid+1,r,OBJL,OBJR);
				}
			}else if(mid >= OBJL){
				return QueryTagMx1(p*2,l,mid,OBJL,OBJR);
			}else if(mid < OBJR){
				return QueryTagMx1(p*2+1,mid+1,r,OBJL,OBJR);
			}
			cout<<"CERR"<<endl;
			return 10181108;
		}
		int GetVal(int p,int l,int r,int OBJL,int OBJR){//for debug
			if(OBJL <= l && r <= OBJR){
				return node[p].mn;
			}
			PushDown(p);
			const int mid = (l + r) >> 1;
			int ret = 0;
			if(mid >= OBJL)ret = max(ret,GetVal(p*2,l,mid,OBJL,OBJR));
			if(mid < OBJR)ret = max(ret,GetVal(p*2+1,mid+1,r,OBJL,OBJR));
			return ret;
		}
		int GetTag(int p,int l,int r,int OBJL,int OBJR){//for debug
			if(OBJL <= l && r <= OBJR){
				return node[p].tag;
			}
			PushDown(p);
			const int mid = (l + r) >> 1;
			int ret = 0;
			if(mid >= OBJL)ret = max(ret,GetTag(p*2,l,mid,OBJL,OBJR));
			if(mid < OBJR)ret = max(ret,GetTag(p*2+1,mid+1,r,OBJL,OBJR));
			return ret;
		}
	public:
		inline void Build(int inn){
			SIZE = 5e5 + 1018 + 1108 - 1000;
			Build(1,1,SIZE);
			return ;
		}
		inline void Add(int pos){
			if(QueryPos(1,1,SIZE,pos) <= 1){
				AddVal(1,1,SIZE,pos,pos,1);
				return ;
			}
			int r = QueryVal(1,1,SIZE,pos,SIZE,2);
			AddTag(1,1,SIZE,pos,r,1);
			AddVal(1,1,SIZE,pos,r,-1),AddVal(1,1,SIZE,r+1,r+1,1);
			return ;
		}
		inline void Dec(int pos){
			if(QueryPos(1,1,SIZE,pos) == 2){
				AddVal(1,1,SIZE,pos,pos,-1);
				return ;
			}
			int r = QueryTagMx1(1,1,SIZE,pos,SIZE);
			if(r < pos){//GetTag(1,1,SIZE,pos,pos)
				AddVal(1,1,SIZE,pos,pos,-1);
				return ;
			}
			cout<<node[1].cnt<<" DEC "<<pos<<" to "<<r<<" ";
			AddTag(1,1,SIZE,pos,r,-1);//no r?
			AddVal(1,1,SIZE,pos,r,1),AddVal(1,1,SIZE,r+1,r+1,-1);
			return ;
		}
		inline int Query(){
			return SIZE - node[1].cnt;
		}
}tr;
int n,q,arr[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("merge/merge3.in","r",stdin);
	freopen("merge.out","w",stdout);
	cin>>n>>q;
	tr.Build(n);
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
		tr.Add(arr[i]);
	}
	while(q--){
		int opt,i;
		cin>>opt;
		if(opt == 1){
			cin>>i;
			tr.Dec(arr[i]); 
			cin>>arr[i];
			tr.Add(arr[i]);
		}else{
			cout<<tr.Query()<<'\n';//not endl 
		}
//		tr.Show();
	}
	return 0;
}
