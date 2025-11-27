#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 200006;
vector<ll> mp[MAXN];
ll t,n,m,inll,sum,k,ans;
vector<ll> s[MAXN];
/*void show(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}*/
bool judge(int px1,int py1,int px2,int py2){
	ll fd = s[px2][py2] + s[px1-1][py1-1];
	return ((fd - s[px1-1][py2] - s[px2][py1-1]) == k);
}
int main(){
	freopen("lotus.in","r",stdin);
	freopen("lotus2.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		sum = 0;
		ans = 0;
		s[0].clear();
		for(int i = 0;i <= m;i++){
			s[0].push_back(0);
		}
		for(int i = 1;i <= n;i++){
			mp[i].clear();
			s[i].clear();
			mp[i].push_back(114514);
			s[i].push_back(0);
			for(int j = 1;j <= m;j++){
				scanf("%lld",&inll);
				sum = inll;
				sum += s[i][j-1];
				sum += s[i-1][j];
				sum -= s[i-1][j-1];
				mp[i].push_back(inll);
				s[i].push_back(sum);
			}
		}
		scanf("%lld",&k);
		for(int posx1 = 1;posx1 <= n;posx1++){
			for(int posy1 = 1;posy1 <= m;posy1++){
				for(int posx2 = posx1;posx2 <= n;posx2++){
					for(int posy2 = posy1;posy2 <= m;posy2++){
						ans += judge(posx1,posy1,posx2,posy2);
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
