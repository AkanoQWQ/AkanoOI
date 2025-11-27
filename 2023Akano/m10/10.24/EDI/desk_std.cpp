//12252024832524
#include <bits/stdc++.h>
#define TT template<typename T>
using namespace std;

typedef long long LL;
const int MAXN = 200005;
const LL INF = 1ll << 60;
int m,n,k;
int o[MAXN << 1]; 
bool tag[MAXN];
struct desk
{
	int l,r;
	bool operator < (const desk &px)const{
		if(l^px.l) return l < px.l;
		return r > px.r;
	}
}d[MAXN];
vector<desk> a[MAXN];
vector<int> fs[MAXN];//final students list

LL Read()
{
	LL x = 0,f = 1; char c = getchar();
	while(c > '9' || c < '0'){if(c == '-')f = -1;c = getchar();}
	while(c >= '0' && c <= '9'){x = (x*10) + (c^48);c = getchar();}
	return x * f;
}
TT void Put1(T x)
{
	if(x > 9) Put1(x/10);
	putchar(x%10^48);
}
TT void Put(T x,char c = -1)
{
	if(x < 0) putchar('-'),x = -x;
	Put1(x); if(c >= 0) putchar(c);
}
TT T Max(T x,T y){return x > y ? x : y;}
TT T Min(T x,T y){return x < y ? x : y;}
TT T Abs(T x){return x < 0 ? -x : x;}

LL Get(int h,desk des)//student & desk
{
	if(h < des.l) return des.l - h;
	if(h > des.r) return h - des.r;
	return 0;
}
LL pre[MAXN << 1];
LL Query(int l,int r)
{
	if(l > r) return 0;
	LL ret = pre[r];
	if(!l) return ret;
	return ret - pre[l-1];
}
LL solve(int sl,int sr,int dl,int dr)//student lr,desk lr,O((k+nm)log_2n)
{
	if(sl > sr) return 0;
	LL cur = 0,MIN = INF;
	int lid = 0,rid = 0,B = dl,mid = (sl+sr) >> 1;
	for(int i = 0;i < (m<<1);++ i) pre[i] = ((i ? pre[i-1] : 0) + fs[mid][i]);
	for(int i = dl;i <= dr;++ i)
	{
		while(lid < (m<<1) && fs[mid][lid] < d[i].l) ++lid;
		while(rid < (m<<1) && fs[mid][rid] <= d[i].r) ++rid;
		cur = 1ll * d[i].l * lid - Query(0,lid-1) + Query(rid,(m<<1)-1) - 1ll * ((m<<1)-rid) * d[i].r;
//		cerr<<mid+1<<" choose "<<i<<" : "<<" + "<<1ll * d[i].l * lid<<" - "<<1ll * ((m<<1)-rid) * d[i].r<<" - "<<Query(0,lid-1)<<" + "<<Query(rid,(m<<1)-1)<<endl;
		if(cur < MIN){
			MIN = cur,B = i;
		}
	}
	return MIN+solve(sl,mid-1,dl,B)+solve(mid+1,sr,B,dr);
}

int main()
{
	freopen("desk/desk3.in","r",stdin);
//	freopen("party.out","w",stdout);
	m = Read(); n = Read(); k = Read();
	for(int i = 1;i <= k;++ i) d[i].l = Read(),d[i].r = Read();
	sort(d+1,d+k+1);
	int R = 0;
	for(int i = 1;i <= k;++ i)
	{
		if(R >= d[i].r) tag[i] = 1;
		R = Max(R,d[i].r);
	}
	int kk = k; k = 0;
	for(int i = 1;i <= kk;++ i) if(!tag[i]) d[++k] = d[i];
	for(int i = 1;i <= k;i++){
		cerr<<d[i].l<<","<<d[i].r<<endl;
	}
	for(int i = 1;i <= m;++ i)
	{
		for(int j = 0;j < (n<<1);++ j) o[j] = Read();
		sort(o,o+(n<<1));
		for(int j = 0;j < (n<<1);j += 2) fs[j >> 1].emplace_back(o[j]),fs[j >> 1].emplace_back(o[j+1]);
	}
	for(int i = 0;i < n;++ i){
		sort(fs[i].begin(),fs[i].end());
		cerr<<i+1<<" : ";
		for(auto j : fs[i]){
			cerr<<j<<",";
		}
		cerr<<endl;
	}
	

	Put(solve(0,n-1,1,k),'\n');
	return 0;
}

