#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 4e5 + 1018 + 1108;
const int SQT = 600;
int n,q,a[MAXN],blk_len,bel[MAXN];
struct Block{
	priority_queue<int,vector<int>,less<int> > pq;
	priority_queue<int,vector<int>,greater<int> > lazy;
	int l,r;
	inline void Build(){
		pq = priority_queue<int,vector<int>,less<int> >(a+l,a+r+1);
		return ;
	}
	inline void Calculate(){
		for(int i = l;i <= r;i++){
			if(lazy.empty())break;
			if(!lazy.empty() && lazy.top() < a[i]){
				const int old = a[i];
				a[i] = lazy.top();
				lazy.pop();
				lazy.push(old);
			}
		}
		return ;
	}
	inline int TotalChange(int x){
		const int tp = pq.top();
		if(x > tp)return x;
		pq.pop();
		pq.push(x);
		lazy.push(x);
		return tp;
	}
	inline int PartChange(int x,int l,int r){
		Calculate();
		for(int i = l;i <= r;i++){
			if(x < a[i]){
				swap(x,a[i]);
			}
		}
		Build();
		return x;
	}
}block[SQT];
inline int Pass(int st,int ed,int x){
	for(int i = bel[st];block[i].l != 0;i++){
		const int l = max(block[i].l,st),r = min(block[i].r,ed);
		if(l == block[i].l && r == block[i].r){
			x = block[i].TotalChange(x);
		}else{
			x = block[i].PartChange(x,l,r);
		}
		if(block[i].r >= ed)break;
	}
	return x;
}
vector<int> vec;
struct Query{
	int st,ed,x;
}ask[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	blk_len = sqrt(n)*1.2;
	blk_len = max(blk_len,n / (SQT-5));
	vec.reserve(3*n);
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		vec.push_back(a[i]);
	}
	for(int t = 1;t <= q;t++){
		cin>>ask[t].st>>ask[t].ed>>ask[t].x;
		vec.push_back(ask[t].x);
	}
	sort(vec.begin(),vec.end());
	auto it = unique(vec.begin(),vec.end());
	vec.erase(it,vec.end());
	for(int i = 1;i <= n;i++)a[i] = lower_bound(vec.begin(),vec.end(),a[i]) - vec.begin();
	for(int i = 1;i <= q;i++)ask[i].x = lower_bound(vec.begin(),vec.end(),ask[i].x) - vec.begin();
	for(int i = 1;i <= n;i++){
		bel[i] = ((i-1) / blk_len) + 1;
		if(block[bel[i]].l == 0){
			block[bel[i]].l = i;
		}
		block[bel[i]].r = max(block[bel[i]].r,i);
	}
	for(int i = 1;i <= bel[n];i++){
		block[i].Build();
	}
	for(int t = 1;t <= q;t++){
		int st = ask[t].st,ed = ask[t].ed,x = ask[t].x;
		if(st > ed){
			x = Pass(st,n,x);
			x = Pass(1,ed,x);
		}else{
			x = Pass(st,ed,x);
		}
		cout<<vec[x]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
