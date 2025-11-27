#include<bits/stdc++.h>
using namespace std;
const int MAXP = 2e7;
struct Node{
	int val,cnt,ls,rs;
};
class PersistentSegmentTree{
	private:
		Node val[MAXP];
		int tot;
		inline void PushUp(int p){
			val[p] = val[node[p].ls] + val[node[p].rs];
			return ;
		}
		void Change(int p,int l,int r,int OBJ,int _val){
			if(l == r){
				node[p].val += _val,node[p]
			}
		}
	public:
		
}tr;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<sizeof(tr)/1000/1000<<endl;
	return 0;
}
