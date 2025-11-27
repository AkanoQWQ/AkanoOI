#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
#define ll long long
FILE_ST
const int MAXN = 2e7;
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
EXCUTE_ST
	freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= k;i++){
		cin>>p[i].up>>p[i].down;
		p[i].yue();
	}
	if(k == 0){
		printf("%lld",n%MOD);
		return 0;
	}
	p[k+1].up = 1,p[k+1].down = 1;
	a[1].up = p[1].up,a[1].down = p[1].down;
	a[1].write();
	a[0].up = 1,a[0].down = 1;
	fs1.up = 1,fs1.down = 1;
	cout<<endl;
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
				poss = poss * a[s].f();
				//poss = poss * p[m].f();
				++m;
			}
			cnt = cnt + poss;
			cout<<"add "<<j<<" to "<<i<<":";
			(poss * (p[i-j])).write();
			cout<<" bec poss";
			poss.write();
			cout<<endl;
			a[i] = a[i] + poss * (p[i-j]);
			a[i].yue();
		}
		fs nonek;
		nonek.up = 1,nonek.down = 1;
		nonek = nonek * a[l-1];
		int t = 1;
		for(int j = l;j < i;j++,t++){
			nonek = nonek * a[j].f();
		}
		cout<<t<<"nonek:";
		nonek.write();cout<<"*";
		p[t].write();cout<<"=";
		(nonek * (p[t])).write();
		cout<<endl;
		a[i] = a[i] + nonek * (p[t]);		
		cout<<"a["<<i<<"]:";
		a[i].write();
		cout<<endl;
		cnt = cnt + nonek;
		cout<<"!!CNT";
		cnt.write();
		cout<<"    -    ";
		(fs1-cnt).write();
		cout<<endl<<endl;
	}
	ansfs.down = 1;
	for(int i = 1;i <= n;i++){
		ldans += 1.0f * a[i].up / a[i].down;
		ansfs = ansfs + a[i];
		ansfs.yue();
	}
	printf("%Lf\n",ldans);
	ansfs.yue();
	ansfs.write();
	printf("\n%lld",ansfs.up*ksm(ansfs.down,MOD-2)%MOD);
FILE_ED_And_excute
