#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int MAXN = 1e5 + 1018 + 1108;

class FHQTreap{
private:
	mt19937 keyRNG;
	struct Node{
		int key,val,siz,l,r,lazy;
		Node() = default;
		Node(int _key,int _val){
			key = _key,val = _val,siz = 1,l = r = lazy = 0;
			return ;
		}
	}node[MAXN * 2];
	int root = 0,tot = 0;
	inline int NewNode(int x){
		node[++tot] = Node(keyRNG(),x);
		return tot;
	}
	inline void PushUp(int p){
		node[p].siz = node[node[p].l].siz + node[node[p].r].siz + 1;
		return ;
	}
	inline void Shift(int p,int _val){
		if(p == 0)return ;
		node[p].val += _val,node[p].lazy += _val;
		return ;
	}
	inline void PushDown(int p){
		Shift(node[p].l,node[p].lazy),Shift(node[p].r,node[p].lazy);
		node[p].lazy = 0;
		return ;
	}
	void SplitbyVal(int p,int k,int& x,int& y){
		if(!p){
			x = y = 0;
			return ;
		}
		PushDown(p);
		if(node[p].val <= k){
			x = p;
			SplitbyVal(node[p].r,k,node[p].r,y);
		}else{
			y = p;
			SplitbyVal(node[p].l,k,x,node[p].l);
		}
		PushUp(p);
		return ;
	}
	void SplitbySize(int p,int k,int& x,int& y){
		if(!p){
			x = y = 0;
			return ;
		}
		PushDown(p);
		if(node[node[p].l].siz + 1 <= k){
			x = p;
			SplitbySize(node[p].r,k - node[node[p].l].siz - 1,node[p].r,y);
		}else{
			y = p;
			SplitbySize(node[p].l,k,x,node[p].l);
		}
		PushUp(p);
		return ;
	}
	int Merge(int x,int y){
		if(!x || !y)return x + y;
		PushDown(x),PushDown(y);
		if(node[x].key <= node[y].key){
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
	inline int GetMax(int& x){
		if(x == 0)return 0;
		int pre,maxval;
		SplitbySize(x,node[x].siz-1,pre,maxval);
		int ret = node[maxval].val;
		x = Merge(pre,maxval);
		return ret;
	}
public:
	inline void Solve(int l,int r){
		int nowmax = GetMax(root),newvalue = 0;
		if(nowmax < r){
			newvalue = max(nowmax+1,l);
		}
		int beforeL = 0,range = 0,afterR = 0,firstUpper = 0,lastPre = 0,useless = 0;
		SplitbyVal(root,l - 1,beforeL,range);
		SplitbyVal(range,r - 1,range,afterR);
		SplitbySize(afterR,1,firstUpper,afterR);
		lastPre = GetMax(beforeL);
		if(node[range].siz + node[firstUpper].siz > 0){
			//在l的值前面插入mx(最小也为l-1,在加一后就是l),并令这些值加一
			range = Merge(NewNode(max(lastPre,l-1)),range);
			Shift(range,1);
			if(firstUpper == 0){//删除末尾值
				SplitbySize(range,node[range].siz - 1,range,useless);
			}
		}
		//组装剩下的部分
		root = Merge(beforeL,Merge(range,afterR));
		if(newvalue){//插入新值,且它大于当前的最大值
			root = Merge(root,NewNode(newvalue));
		}
		return ;
	}
	inline int GetAns(){
		return node[root].siz;
	}
}tr;
int n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n;
	for(int i = 1,l,r;i <= n;i++){
		cin>>l>>r;
		tr.Solve(l,r);
	}
	cout<<tr.GetAns()<<endl;
	return not(Akano loves pure__Elysia);
}
