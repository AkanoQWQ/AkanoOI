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
ll main_ans[MAXN];
int arr[MAXN],n,q,blk_len,blk[MAXN];
struct Query{
	int l,r,id;
}ask[MAXN];
bool Cmp(Query q1,Query q2){
	if(blk[q1.l] != blk[q1.l])return blk[q1.l] < blk[q1.l];
	if(q1.r != q2.r)return q1.r < q2.r;
	if(q1.l != q2.l)return q1.l < q2.l;
	return q1.id < q2.id;
}
ClearableArray<int,MAXN> cnt;
vector<int> num;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	blk_len = sqrt(n);
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
		num.push_back(arr[i]);
		blk[i] = ((i-1) / blk_len) + 1;
	}
	sort(num.begin(),num.end());
	auto it = unique(num.begin(),num.end());
	num.erase(it,num.end());
	for(int i = 1;i <= n;i++){
		arr[i] = lower_bound(num.begin(),num.end(),arr[i]) - num.begin();
	}
	for(int i = 1;i <= q;i++){
		cin>>ask[i].l>>ask[i].r;
		ask[i].id = i;
	}
	sort(ask+1,ask+q+1,Cmp);
	for(int b = 0,tail = 0;b < [ask[q].l];b++){
		const int split = b * blk_len;
		int l = split + 1,r = split;
		ll ans = 0;
		while(tail+1 <= q && blk[ask[tail+1].l] == b){
			tail++;
			int OBJL = ask[tail].l,OBJR = ask[tail].r;
			if(OBJR - OBJL <= blk_len){
				main_ans [ask[tail].id] = BF(OBJL,OBJR);
				continue; 
			}
			while(r < OBJR){
				r++;
				cnt[arr[r]]++;
				ans = max(ans,1ll * cnt[arr[r]] * num[arr[r]]);
			}
			ll save_ans = ans;
			
		}
	}
	return not(Akano loves pure__Elysia);
}
