#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXP = 2006110;
const int MAXN = 2006;
int leaf = 1;
int n,a[MAXN];
int q[MAXP][2],tail;
ll solve1(){
	ll ret = 0;
	q[1][0] = a[1],q[1][1] = 0;
	tail = 1;
	for(int i = 2;i <= n;i++){
		int mincost = 0x7fffffff;
		int pos = -1;
		for(int j = 1;j <= tail;j++){
			const int nowv = q[j][0];
			const int nowd = q[j][1];
			if(nowv == -1 || nowd == -1)continue;
			if(nowv + (nowd+2)*a[i] < mincost){
				mincost = nowv + (nowd+2)*a[i];
				pos = j;
			}
		}
		ret += mincost;
		cout<<"add"<<a[i]<<"under"<<q[pos][0]<<endl;
		q[++tail][0] = q[pos][0];
		q[tail][1] = q[pos][1] + 1;
		q[++tail][0] = a[i];
		q[tail][1] = q[pos][1] + 2;
		q[pos][0] = q[pos][1] = -1;
	}
	return ret;
}
vector<string> deb;
ll solve2(int mo){
	//deb.clear();
	ll ret = 0;
	q[1][0] = a[1],q[1][1] = 0;
	tail = 1;
	for(int i = 2;i <= n;i++){
		int mincost = 0x7fffffff;
		int seccost = 0x7fffffff;
		int pos = -1;
		int p2 = -1;
		for(int j = 1;j <= tail;j++){
			const int nowv = q[j][0];
			const int nowd = q[j][1];
			if(nowv == -1 || nowd == -1)continue;
			if(nowv + (nowd+2)*a[i] < mincost){
				seccost = mincost,p2 = pos;
				mincost = nowv + (nowd+2)*a[i];
				pos = j;
			}else if(nowv + (nowd+2)*a[i] < seccost){
				seccost = nowv + (nowd+2)*a[i];
				p2 = j;
			}
		}
		if(rand()% mo == 0 && p2 != -1){
			pos = p2;
			mincost = seccost;
		}
		ret += mincost;
		//deb.push_back("add"+to_string(a[i])+"under"+to_string(q[pos][0]));
		q[++tail][0] = q[pos][0];
		q[tail][1] = q[pos][1] + 1;
		q[++tail][0] = a[i];
		q[tail][1] = q[pos][1] + 2;
		q[pos][0] = q[pos][1] = -1;
	}
	return ret;
}
int cmp2(int a,int b){
	return a > b;
}
int main(){
	freopen("desire.in","r",stdin);
	//freopen("desire.out","w",stdout);
	srand(time(0));
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp2);
	ll ans = solve1();
	cout<<ans<<endl;
	while(clock() < 1800){
		ll a2 = solve2(25);
		if(a2 < ans){
			for(int j = 0;j < deb.size();j++)cout<<deb[j]<<endl;
		}
		ans = min(ans,a2);
	}
	printf("%lld",ans);
	return 0;
}
