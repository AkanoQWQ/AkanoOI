#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
constexpr int MAXN = 1e5 + 1018 + 1108;
constexpr int MAXS = 5e5 + 1018 + 1108; 
constexpr int base = 131;
int n,Tlen,m,ans,chvalue[28];
ull chbase[28][MAXN],basepow[MAXN];
struct SegNode{
	ull val;
	int l,r,len;
	char lazy;
}node[MAXS * 8];//enough?
int tot; 
class SegmentTree{
private:
	int root,siz;
	inline void PushUp(int p){
		node[p].val = node[node[p].l].val * basepow[node[node[p].r].len] + node[node[p].r].val;
		return ;
	}
	inline void Set(int p,char ch){
		node[p].val = chbase[ch - 'a'][node[p].len];
		node[p].lazy = ch;
		return ;
	}
	inline void PushDown(int p){
		if(node[p].lazy == '0')return ;
		if(node[p].l)Set(node[p].l,node[p].lazy);
		if(node[p].r)Set(node[p].r,node[p].lazy);
		node[p].lazy = '0';
		return ;
	}
	void Build(int& p,int l,int r,const string& str){
		p = ++tot;
		node[p].lazy = '0';
		if(l == r){
			node[p].len = 1,node[p].val = chvalue[str[l - 1] - 'a'];
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(node[p].l,l,mid,str),Build(node[p].r,mid+1,r,str);
		node[p].len = node[node[p].l].len + node[node[p].r].len;
		PushUp(p);
		return ;
	}
	void Change(int p,int l,int r,int OBJL,int OBJR,char ch){
		if(OBJL <= l && r <= OBJR){
			Set(p,ch);
			return ;
		}
		const int mid = (l + r) >> 1;
		PushDown(p);
		if(mid >= OBJL)Change(node[p].l,l,mid,OBJL,OBJR,ch);
		if(mid < OBJR)Change(node[p].r,mid+1,r,OBJL,OBJR,ch);
		PushUp(p);
		return ;
	}
public:
	inline void Build(const string& str){
		siz = str.length();
		Build(root,1,siz,str);
		return ;
	}
	inline void Change(int l,int r,char ch){
		Change(root,1,siz,l,r,ch);
		return ;
	}
	inline ull RootVal(){
		return node[root].val;
	}
}tr[MAXN];
map<ull,int> cnt;
mt19937 rng(time(0));
vector<int> valuevec;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	for(int i = 1;i < base;i++){
		valuevec.push_back(i);
	}
	shuffle(valuevec.begin(),valuevec.end(),rng);
	for(int i = 0;i < 26;i++){
		chvalue[i] = valuevec[i];
	}
	cin>>n>>Tlen>>m;
	basepow[0] = 1;
	for(int i = 1;i <= Tlen;i++){
		basepow[i] = basepow[i-1] * base;
	}
	for(int ch = 0;ch < 26;ch++){
		chbase[ch][0] = 0;
		for(int i = 1;i <= Tlen;i++){
			chbase[ch][i] = chbase[ch][i-1] * base + chvalue[ch];
		}
	}
	for(int i = 1;i <= n;i++){
		string str;
		cin>>str;
		tr[i].Build(str);
		cnt[tr[i].RootVal()]++;
		if(cnt[tr[i].RootVal()] == 1)ans++;
	}
	for(int i = 1;i <= m;i++){
		int x,l,r;
		char ch;
		cin>>x>>l>>r>>ch;
		cnt[tr[x].RootVal()]--;
		if(cnt[tr[x].RootVal()] == 0)ans--;
		tr[x].Change(l,r,ch);
		cnt[tr[x].RootVal()]++;
		if(cnt[tr[x].RootVal()] == 1)ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
