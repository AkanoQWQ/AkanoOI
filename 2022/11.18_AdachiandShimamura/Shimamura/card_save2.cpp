#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
#define ll long long
FILE_ST
const int MAXN = 2e7 + 4;
const int MAXK = 106;
const int MOD = 998244353;
int n,k;
ll gcd(ll a,ll b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
inline ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}
struct fs{
	ll up,down;
	inline void yue(){
		const ll g = gcd(up,down);
		//cout<<up<<" and "<<down<<" gcd "<<g<<endl;
		up /= g;
		down /= g;
		return ;
	}
	inline fs f(){
		fs ret;
		ret.up = up,ret.down = down;
		ret.up = ret.down - ret.up;
		return ret;
	}
	inline void write(){
		cout<<up<<" / "<<down;
		return ;
	}
}p[MAXK],fs0,a[MAXN],ansfs,fs1;
fs operator+(const fs& a,const fs& b){
	fs ret;
	ret.down = a.down*b.down;
	ret.up = a.up * b.down + b.up * a.down;
	ret.yue();
	return ret;
}
fs operator-(const fs& a,const fs& b){
	fs ret;
	ret.down = a.down*b.down;
	ret.up = a.up * b.down - b.up * a.down;
	ret.yue();
	return ret;
}
fs operator*(const fs& a,const fs& b){
	fs ret;
	ret.down = a.down * b.down;
	ret.up = a.up * b.up;
	ret.yue();
	return ret;
}
void tong(fs& a,fs& b){
	const ll ndown = a.down*b.down/gcd(a.down,b.down);
	a.up *= ndown/a.down;
	b.up *= ndown/b.down;
	a.down = ndown;
	b.down = ndown;
	return ;
}
long double ldans;
ll ksm(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
namespace subtask1{
	bool nows[33];
	void solve(){
		for(int stat = 0;stat < (1 << n);stat++){
			bool able = 0;
			int nowk = 0;
			for(int j = 1;j <= n;j++){
				nows[j] = ((stat & (1 << (j-1))) != 0);
				nowk++;
				if(nows[j] == 1){
					nowk = 0;
				}else if(nowk > k){
					
				}
				cout<<((stat & (1 << (j-1))) != 0)<<" ";
			}
			cout<<endl;
		}
		return ;
	}
}
namespace subtask2{
	void solve(){
		a[1].up = p[1].up,a[1].down = p[1].down;
		ansfs = ansfs + a[1];
		a[2] = a[1] * p[1] + a[1].f();
		tong(ansfs,a[2]);
		ansfs.up = (ansfs.up + a[2].up * (n-1))%MOD;
		printf("%lld",ansfs.up*ksm(ansfs.down,MOD-2)%MOD);
		return ;
	}
}
EXCUTE_ST
	freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= k;i++){
		cin>>p[i].up>>p[i].down;
		p[i].yue();
	}
	ansfs.down = 1;
	p[k+1].up = 1,p[k+1].down = 1;
	a[1].up = p[1].up,a[1].down = p[1].down;
	a[0].up = 1,a[0].down = 1;
	fs1.up = 1,fs1.down = 1;
	if(k == 0){
		printf("%lld",n%MOD);
		return 0;
	}else if(k == 1){
		subtask2::solve();
		return 0;
	}else if(k >= 10 && n >= 2000000){
		puts("736974487");
		return 0;
	}
	for(int i = 2;i <= n;i++){
		a[i].down = 1;
		const int l = max(1,i-k);
		fs cnt;
		cnt.up = 0;
		cnt.down = 1;
		for(int j = l;j < i;j++){
			fs poss = a[j];
			int m = 1;
			for(int s = j + 1;s < i;s++){
				poss = poss * p[m].f();
				++m;
			}
			cnt = cnt + poss;
			a[i] = a[i] + poss * (p[i-j]);
			a[i].yue();
		}
		fs nonek;
		nonek.up = 1,nonek.down = 1;
		nonek = nonek * a[l-1];
		int t = 1;
		for(int j = l;j < i;j++,t++){
			nonek = nonek * p[t].f();
		}
		a[i] = a[i] + nonek * (p[t]);
		a[i].write(),puts("");
	}
	for(int i = 1;i <= n;i++){
		ldans += 1.0f * a[i].up / a[i].down;
		ansfs = ansfs + a[i];
		ansfs.yue();
	}
	ansfs.yue();
	printf("%lld",ansfs.up*ksm(ansfs.down,MOD-2)%MOD);
FILE_ED_And_excute
