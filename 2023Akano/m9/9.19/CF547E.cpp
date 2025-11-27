#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
const int MAXLG = 20;
string s[MAXN];
int n,q,tot;
struct Node{
	int nxt[27],fail,cnt;
}node[MAXN * MAXLG];
class ACAutomaton{
	private:
		int root;
	public:
		inline void Init(){
			root = ++tot;
			return ;
		}
		inline void Insert(const string& str){
			int u = root;
			for(auto ch : str){
				int i = ch - 'a';
				if(node[u].nxt[i] == 0)node[u].nxt[i] = ++tot;
				u = node[u].nxt[i];
				node[u].cnt++;
				cerr<<ch<<" get "<<u<<" cnt "<<node[u].cnt<<endl;
			}
			return ;
		}
		inline void Build(){
			queue<int> k;
			node[root].fail = root;
			for(int i = 0;i < 26;i++){
				if(node[root].nxt[i]){
					node[node[root].nxt[i]].fail = root;
					k.push(node[root].nxt[i]);
				}else{
					node[root].nxt[i] = root;
				}
			}
			while(!k.empty()){
				const int u = k.front();
				k.pop();
				for(int i = 0;i < 26;i++){
					if(node[u].nxt[i]){
						node[node[u].nxt[i]].fail = node[node[u].fail].nxt[i];
						if(node[node[u].nxt[i]].fail == 0)node[node[u].nxt[i]].fail = root;
						k.push(node[u].nxt[i]);
					}else{
						node[u].nxt[i] = node[node[u].fail].nxt[i];
						if(node[u].nxt[i] == 0)node[u].nxt[i] = root;
					}
				}
				node[u].cnt += node[node[u].fail].cnt;
			}
			return ;
		}
		inline int Query(const string& str){
			int u = root,ret = 0;
			for(auto ch : str){
				int i = ch - 'a';
				u = node[u].nxt[i];
				ret += node[u].cnt;
			}
			return ret;
		}
};
class SegmentTree{
	private:
		ACAutomaton aca[MAXN * 4];
		void Build(int p,int l,int r){
			aca[p].Init();
			for(int i = l;i <= r;i++)aca[p].Insert(s[i]);
			aca[p].Build();
			return ;//TEST
			if(l == r)return ;
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			return ;
		}
		inline int Query(int p,int l,int r,int OBJL,int OBJR,const string& str){
			if(OBJL <= l && r <= OBJR){
				cerr<<str<<" in "<<l<<" to "<<r<<" app "<<aca[p].Query(str)<<endl; 
				return aca[p].Query(str);
			}
			const int mid = (l + r) >> 1;
			int ret = 0;
			if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR,str);
			if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR,str);
			return ret;
		}
	public:
		inline void Build(){
			Build(1,1,n);
			return ;
		}
		inline int Query(int l,int r,const string& str){
			return Query(1,1,n,l,r,str);
		}
}tr;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i <= n;i++)cin>>s[i];
	tr.Build();
	while(q--){
		int l,r,k;
		cin>>l>>r>>k;
		cout<<tr.Query(l,r,s[k])<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
/**/
