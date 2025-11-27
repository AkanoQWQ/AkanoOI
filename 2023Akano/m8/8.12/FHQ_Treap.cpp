#include<bits/stdc++.h>
using namespace std;
const int SIZE = 100;
struct FHQNode{
	int val,key,l,r,sz;
}node[SIZE];
int tot;
class FHQ_Treap{
	private:
		int root;
		inline void PushUp(int p){
			node[p].sz = node[node[p].l].sz + node[node[p].r].sz + 1;
			return ;
		}
		void Split(int p,int k,int& x,int& y){//Split by rank
			if(!p){
				x = y = 0;
				return ;
			}
			if(node[node[p].l].sz+1 <= k){
				x = p;
				Split(node[p].r,k - (node[node[p].l].sz+1),node[p].r,y);
			}else{
				y = p;
				Split(node[p].l,k,x,node[p].l);
			}
			PushUp(p);
			return ;
		}
		int Merge(int x,int y){
			if(x == 0 || y == 0)return x + y;
			if(node[x].val < node[y].val){
				node[y].l = Merge(x,node[y].l);
				PushUp(y);
				return y;
			}else{
				node[x].r = Merge(node[x].r,y);
				PushUp(x);
				return x;
			}
			return 10181108;
		}
		void dfs(int p,vector<int>& vec){
			if(!p)return ;
			dfs(node[p].l,vec);
			vec.push_back(node[p].key);
			dfs(node[p].r,vec);
			return ;
		}
	public:
		inline void Insert(int _key,int kth){
			if(root == 0){
				root = ++tot;
				node[tot].key = _key,node[tot].val = rand(),node[tot].sz = 1;
			}else{
				++tot;
				node[tot].key = _key,node[tot].val = rand(),node[tot].sz = 1;
				int r1,r2;
				Split(root,kth,r1,r2);
				r1 = Merge(r1,tot);
				root = Merge(r1,r2);
			}
			return ;
		}
		inline int Size(){
			return node[root].sz;
		}
		inline vector<int> Output(){
			vector<int> ret;
			dfs(root,ret);
			return ret;
		}
}tr;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	tr.Insert(1,0);
	tr.Insert(2,1);
//	tr.Insert(3,0);
//	tr.Insert(4,0);
//	tr.Insert(5,0);
//	tr.Insert(10,5);
	vector<int> now = tr.Output();
	for(auto i : now)cout<<i<<" ";
	return 0;
}
/*
DEBUG part:

void Output(int p){
	if(!p)return ;
	Output(node[p].l);
	cout<<node[p].key<<endl;
	Output(node[p].r);
	return ;
}
inline void Output(){
	Output(root);
	return ;
}
void Debug(int p){
	if(!p)return ;
	Debug(node[p].l);
	cout<<p<<" : "<<node[p].key<<" and "<<node[p].sz<<endl;
	if(node[p].sz != node[node[p].l].sz + node[node[p].r].sz){
		cout<<"ERR "<<endl;
	}
	Debug(node[p].r);
	return ;
}
inline void Debug(){
	Debug(root);
	return ;
}

*/
