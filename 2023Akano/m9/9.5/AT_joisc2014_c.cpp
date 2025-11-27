#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
template<typename T,int SIZE>
class ClearableArray{
	private:
		bool vis[SIZE];
		queue<int> clearQueue;
		T content[SIZE];
	public:
		T& operator[](int x){
			if(!vis[x]){
				vis[x] = true,clearQueue.push(x);
			}
			return content[x];
		}
		inline void Clear(){
			while(!clearQueue.empty()){
				const int u = clearQueue.front();
				clearQueue.pop();
				vis[u] = false,content[u] = T();
			}
			return ;
		}
};
ClearableArray<int,MAXN> cnt,cntBF;
ll ans[MAXN];
int n,q,blk_len,arr[MAXN],bel[MAXN];
vector<int> vec;
struct Query{
	int l,r,id;
}ask[MAXN];
bool operator<(Query q1,Query q2){
	if(bel[q1.l] != bel[q2.l])return bel[q1.l] < bel[q2.l];
	return q1.r < q2.r;
}
inline void ReadIn(){
	cin>>n>>q;
	blk_len = sqrt(n) + 1;
	for(int i = 1;i <= n;i++){
		bel[i] = ((i-1) / blk_len)+1;
		cin>>arr[i];
		vec.push_back(arr[i]);
	}
	sort(vec.begin(),vec.end());
	auto it = unique(vec.begin(),vec.end());
	vec.erase(it,vec.end());
	for(int i = 1;i <= n;i++){
		arr[i] = lower_bound(vec.begin(),vec.end(),arr[i]) - vec.begin();
	}
	for(int i = 1;i <= q;i++){
		cin>>ask[i].l>>ask[i].r;
		ask[i].id = i;
	}
	sort(ask+1,ask+q+1);
	return ;
}
inline ll BF(int l,int r){
	ll ret = 0;
	cntBF.Clear();
	for(int i = l;i <= r;i++){
		cntBF[arr[i]]++;
		ret = max(ret,1ll * cntBF[arr[i]] * vec[arr[i]]);
	}
	return ret;
}
inline void Add(int x,ll &nowans){
	cnt[arr[x]]++;
	nowans = max(nowans,1ll * cnt[arr[x]] * vec[arr[x]]);
	return ;
}
inline void Del(int x){
	cnt[arr[x]]--;
	return ;
}
inline ll Calc(int& l,int& r,int OBJL,int OBJR,int blkR,ll& nowans){
	if(bel[OBJL] == bel[OBJR])return BF(OBJL,OBJR);
	while(r < OBJR){
		Add(++r,nowans);
	}
	ll save = nowans;
	while(l > OBJL){
		Add(--l,nowans);
	}
	ll ret = nowans;
	while(l <= blkR){
		Del(l++);
	}
	nowans = save;
	return ret;
}
inline void Solve(){
	int blk_cnt = bel[ask[q].l],tail = 0;
	for(int i = 1;i <= blk_cnt;i++){
		cnt.Clear();
		int l = i * blk_len + 1,r = i * blk_len;
		ll nowans = 0;
		while(tail+1 <= q && bel[ask[tail+1].l] == i){
			tail++;
			ans[ask[tail].id] = Calc(l,r,ask[tail].l,ask[tail].r,i * blk_len,nowans);
		}
	}
	return ;
}
inline void Output(){
	for(int i = 1;i <= q;i++){
		cout<<ans[i]<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	Solve();
	Output();
	return not(Akano loves pure__Elysia);
}
