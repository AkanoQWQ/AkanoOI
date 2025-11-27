#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 200006;
ll t,n,m,inll,sum,k,ans,lastm;
bool swp;
vector<ll> s[MAXN];
int judge(int px1,int py1,int px2,int py2){
	ll fd = 1ll * s[px2][py2] + s[px1-1][py1-1] - s[px1-1][py2] - s[px2][py1-1];
	if(fd == k)return 114514;
	if(fd < k){
		return -1;
	}else if(fd > k){
		return 1;
	}
	return 114514;
}
inline ll read(){
	ll ret = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return ret * f;
}
void write(ll inx){
	if(inx < 0){
		inx = -inx;
		putchar('-');
	}
	if(inx > 9){
		write(inx / 10);
	}
	putchar((inx%10) + '0');
}
int calc(int upp,int dwn){
	int l = 1,r = 1,ret = 0,orgr = 0;//91 92
	while(r <= m && l <= m){
		int res = judge(upp,l,dwn,r);
		cout<<orgr<<endl;
		if(orgr != 0){
			cout<<"test";
			ret += (orgr - l);
			cout<<orgr<<"comapre "<<l<<"."<<endl;
		}
		orgr = 0;
		bool addl = 0;
		if(res == -1){
			r++;
		}else if(res == 1){
			l++;
		}
		while(res == 114514){
			addl = 1;
			ret++;
			res = judge(upp,l,dwn,r+1);
			if(res != 114514)break;
			orgr = r;
			r++;
			if(r > m)break;
		}
		if(addl){
			l++;
		}
		while(r < l)r++;
	}
	return ret;
}
int main(){
	freopen("lotus/lotus04.in","r",stdin);//4 6 
	//freopen("lotus.out","w",stdout);
	t = read();
	while(t--){
		n = read(),m = read();
		sum = 0;
		ans = 0;
		s[0].clear();
		for(int i = 0;i <= m+2;i++)s[0].push_back(0);
		for(int i = 1;i <= n;i++){
			s[i].clear();
			s[i].push_back(0);
			for(int j = 1;j <= m;j++){
				inll = read();
				s[i].push_back(inll);
				s[i][j] += s[i][j-1] + s[i-1][j] - s[i-1][j-1];
			}
		}
		k = read();
		if(n < m){
			for(int p1 = 1;p1 <= n;p1++){
				for(int p2 = p1;p2 <= n;p2++){
					ans += calc(p1,p2);
				}
			}
		}else{
			for(int p1 = 1;p1 <= n;p1++){
				for(int p2 = p1;p2 <= n;p2++){
					ans += calc(p1,p2);
				}
			}
		}
		write(ans),putchar('\n');
		lastm = m;
	}
	return 0;
}//3 4 5
