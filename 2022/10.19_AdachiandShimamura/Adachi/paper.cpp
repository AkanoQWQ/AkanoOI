#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2000006;
struct point{
	ll x,y,no;
}cp;
vector<point> p;
ll n;
bool del[MAXN];
int main(){
	freopen("paper.in","r",stdin);
	freopen("paper.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		ll opt,x,y;
		cin>>opt>>x;
		if(opt == 1){
			cin>>y;
			cp.x = x,cp.y = y,cp.no = i;
			p.push_back(cp);
		}else if(opt == 2){
			del[x] = 1;
		}else if(opt == 3){
			cin>>y;
			ll ans = 0;
			for(int j = 0;j < p.size();j++){
				if(del[p[j].no])continue;
				ans = max(ans,x*p[j].x + y*p[j].y);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
