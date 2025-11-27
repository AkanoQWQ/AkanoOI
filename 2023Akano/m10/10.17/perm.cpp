#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int MAXN = 6e5 + 1018;
const int MAXQ = 1e6 + 1018 + 1108;
const int INF = 1e8;
int n,q,a[MAXN],trans[MAXN],logval2[MAXN * 2];
vector<int> pow2s;
vector<pii> points;
bool CmpBySecond(pii pii1,pii pii2){
	if(pii1.second != pii2.second)return pii1.second < pii2.second;
	return pii1.first < pii2.first;
}
struct Query{
	int l,r,id;
}ask[MAXQ];
bool CmpByR(Query q1,Query q2){
	if(q1.r != q2.r)return q1.r < q2.r;
	return q1.id < q2.id;
}
template<typename T,int SIZE>
class BIT{
private:
	T val[SIZE];
	inline int Lowbit(int x){
		return x & (-x);
	}
	inline T QueryPre(int x){
		T ret = 0;
		while(x){
			ret += val[x];
			x -= Lowbit(x);
		}
		return ret;
	}
public:
	inline void Change(int x,T _val){
		while(x <= SIZE){
			val[x] += _val;
			x += Lowbit(x);
		}
		return ;
	}
	inline T Query(int l,int r){
		return QueryPre(r) - QueryPre(l-1);
	}
	inline void Clear(){
		memset(val,0,sizeof(val));
		return ;
	}
	BIT(){Clear();}
};
BIT<int,MAXN> bit;
int ans[MAXQ];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		trans[a[i]] = i;//映射
	}
	for(int i = 0;i <= 2*n;i++){
		logval2[i] = -INF;
	}
	logval2[1] = 0;
	for(int i = 2;i <= 2*n;i++){
		if(i % 2 == 0)logval2[i] = logval2[i / 2] + 1;
	}
	points.reserve(2e6);
	pow2s.reserve(100);
	pow2s.push_back(1);
	while(pow2s.back()*2 <= 2*n){
		pow2s.push_back(pow2s.back() * 2);
	}
	for(int i = 1;i <= n;i++){
		for(auto p2 : pow2s){
			int oth = p2 - i;
			if(oth <= 0)continue;
			if(__gcd(oth,i) != 1)continue;
			if(logval2[p2] >= 0){
				for(int j = 1;j <= n;j++){
					if(i*j > n || oth*j > n)break;
					if(trans[i*j] < trans[oth*j])points.emplace_back(trans[i*j],trans[oth*j]);
				}
			}
		}
	}
	sort(points.begin(),points.end(),CmpBySecond);
	cin>>q;
	for(int i = 1;i <= q;i++){
		cin>>ask[i].l>>ask[i].r;
		ask[i].id = i;
	}
	sort(ask+1,ask+q+1,CmpByR);
	auto it = points.begin();
	for(int i = 1;i <= q;i++){
		while(it != points.end() && it->second <= ask[i].r){
			bit.Change(it->first,logval2[(a[it->first] + a[it->second]) / __gcd(a[it->first],a[it->second])]);
			it++;
		}
		ans[ask[i].id] = bit.Query(ask[i].l,n);
	}
	for(int i = 1;i <= q;i++){
		cout<<ans[i]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
