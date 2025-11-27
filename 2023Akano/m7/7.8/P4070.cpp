#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
const int MAXN = 2e5 + 6; 
struct Node{
	int link,len;
	map<int,int> nxt;
	inline bool Exist(int ch){
		return nxt.find(ch) != nxt.end();
	}
};
class SAM{
	private:
		Node node[MAXN];
		int last,tot;
		ll ans;
		inline void Init(){
			node[0].link = -1,node[0].len = 0;
			last = tot = 0;
			return ;
		}
		inline void InsertCh(int ch){
			const int cur = ++tot;
			node[cur].len = node[last].len + 1;
			int p = last;
			while(p != -1 && !node[p].Exist(ch)){
				node[p].nxt[ch] = cur;
				p = node[p].link;
			}
			if(p == -1){
				node[cur].link = 0;
			}else{
				int q = node[p].nxt[ch];
				if(node[p].len + 1 == node[q].len){//f?
					node[cur].link = q;
				}else{
					const int clone = ++tot;
					node[clone].len = node[p].len + 1;
					node[clone].link = node[q].link;
					node[clone].nxt = node[q].nxt;
					while(p != -1 && node[p].Exist(ch) && node[p].nxt[ch] == q){
						node[p].nxt[ch] = clone;
						p = node[p].link;
					}
					node[q].link = node[cur].link = clone;
				}
			}
			ans += node[cur].len - node[node[cur].link].len;
			last = cur;
			return ;
		}
	public:
		inline void Insert(const vi& str){
			for(auto i : str){
				InsertCh(i);
				cout<<ans<<endl;
			}
			return ;
		}
		SAM(){Init();}
}sam;
int n,c;
vi mains;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>c;
		mains.push_back(c);
	}
	sam.Insert(mains);
	return 0;
}
