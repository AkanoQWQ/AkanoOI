#include<bits/stdc++.h>
#pragma GCC target("avx")
using namespace std;
using ll = long long;
const ll INF = INT_MAX;
const int MAXN = 5e4 + 1018 + 1108;
inline ll P(ll inx){
	return inx * inx;
}
struct Cxokolado{
	ll x,y,h;
}cko[MAXN];
struct Ask{
	ll a,b,c;
};
struct Node{
	Cxokolado val;
	int l,r;
	ll possitive[3],negative[3],sum;
};
bool CmpX(Cxokolado p1,Cxokolado p2){
	if(p1.x != p2.x)return p1.x < p2.x;
	return p1.y < p2.y;
}
bool CmpY(Cxokolado p1,Cxokolado p2){
	if(p1.y != p2.y)return p1.y < p2.y;
	return p1.x < p2.x;
}
inline bool Judge(const Cxokolado& colado,const Ask& ask){
	return ask.a * colado.x + ask.b * colado.y < ask.c;
}
inline int Minposs(const Node& node,const Ask& ask){
	bool OK1 = ask.a * node.negative[1] + ask.b * node.negative[2] < ask.c;
	bool OK2 = ask.a * node.negative[1] + ask.b * node.possitive[2] < ask.c;
	bool OK3 = ask.a * node.possitive[1] + ask.b * node.negative[2] < ask.c;
	bool OK4 = ask.a * node.possitive[1] + ask.b * node.possitive[2] < ask.c;
	return OK1 + OK2 + OK3 + OK4;
}
int n,m;
class KDTree{
	private:
		Cxokolado* arr;
		Ask ask;
		Node node[MAXN];
		int tot,root;
		int Build(int l,int r){
			const int p = ++tot;
			const int mid = (l + r) >> 1;
			ll fc1 = 0,fc2 = 0,s1 = 0,s2 = 0;
			for(int i = l;i <= r;i++){
				s1 += arr[i].x;
				s2 += arr[i].y;
			}
			s1 /= (r - l + 1),s2 /= (r - l + 1);
			for(int i = l;i <= r;i++){
				fc1 += P(arr[i].x - s1);
				fc2 += P(arr[i].y - s2);
			}
			if(fc1 > fc2){
				nth_element(arr+l,arr+mid,arr+r,CmpX);
			}else{
				nth_element(arr+l,arr+mid,arr+r,CmpY);
			}
			node[p].val = arr[mid],node[p].sum = arr[mid].h;
			node[p].possitive[1] = node[p].negative[1] = arr[mid].x;
			node[p].possitive[2] = node[p].negative[2] = arr[mid].y;
			if(mid-1 >= l)node[p].l = Build(l,mid-1);
			if(r >= mid+1)node[p].r = Build(mid+1,r);
			if(node[p].l != 0){
				node[p].negative[1] = min(node[p].negative[1],node[node[p].l].negative[1]);
				node[p].possitive[1] = max(node[p].possitive[1],node[node[p].l].possitive[1]);
				node[p].negative[2] = min(node[p].negative[2],node[node[p].l].negative[2]);
				node[p].possitive[2] = max(node[p].possitive[2],node[node[p].l].possitive[2]);
				node[p].sum += node[node[p].l].sum;
			}
			if(node[p].r != 0){
				node[p].negative[1] = min(node[p].negative[1],node[node[p].r].negative[1]);
				node[p].possitive[1] = max(node[p].possitive[1],node[node[p].r].possitive[1]);
				node[p].negative[2] = min(node[p].negative[2],node[node[p].r].negative[2]);
				node[p].possitive[2] = max(node[p].possitive[2],node[node[p].r].possitive[2]);
				node[p].sum += node[node[p].r].sum;
			}
			return p;
		}
		ll Query(int p){
			ll ret = 0;
			if(Judge(node[p].val,ask))ret += node[p].val.h;
			if(node[p].l != 0){
				int ValL = Minposs(node[node[p].l],ask);
				if(ValL == 4){
					ret += node[node[p].l].sum;
				}else if(ValL > 0){
					ret += Query(node[p].l);
				}
			}
			if(node[p].r != 0){
				int ValR = Minposs(node[node[p].r],ask);
				if(ValR == 4){
					ret += node[node[p].r].sum;
				}else if(ValR > 0){
					ret += Query(node[p].r);
				}
			}
			return ret;
		}
	public:
		inline void Build(Cxokolado* _arr){
			arr = _arr;
			root = Build(1,n);
			return ;
		}
		inline ll Query(Ask inAsk){
			ask = inAsk;
			return Query(root);
		}
}KDT;
ll mans = INF;
mt19937 rng(time(0));
inline ll Read(){
	ll ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
int otp[66];
inline void Write(ll inx){
	if(inx == 0)putchar('0');
	int len = 0;
	while(inx){
		otp[++len] = inx % 10;
		inx /= 10;
	}
	for(int i = len;i >= 1;i--){
		putchar(otp[i] + '0');
	}
	return ;
}
int main(){
//	freopen("P4475.in","r",stdin);	
//	freopen("P4475.out","w",stdout);	
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	n = Read(),m = Read();
	for(int i = 1;i <= n;i++){
		cko[i].x = Read(),cko[i].y = Read(),cko[i].h = Read();
	}
	shuffle(cko+1,cko+n+1,rng);
	KDT.Build(cko);
	for(int i = 1;i <= m;i++){
		Ask nowAsk;
		nowAsk.a = Read(),nowAsk.b = Read(),nowAsk.c = Read();
		Write(KDT.Query(nowAsk)),putchar('\n');
	}
	return 0;
}
