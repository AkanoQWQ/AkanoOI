#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e6 + 7;
int opt,n,a[MAXN];
ll sum;
inline int read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
namespace subtask1{
	ll solve(){
		ll avg = sum / n,ans = 0;
		for(int i = 1;i <= n;i++){
			const int delta = a[i] - avg;
			a[i+1] += delta;
			ans += abs(delta); 
		}
		return ans;
	}
/*	ll solve2(){
		ll avg = sum / n,ans = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] > avg){
				while(!left_need.empty() && a[i] > avg){
					const ll upos = left_need.front().first;
					const ll ndv = left_need.front().second;
					const ll addi = min(a[i]-avg,ndv);
					cout<<i<<" push "<<addi<<" into "<<upos<<endl;
					ans += (i-upos) * addi;
					bool flag = 1;
					if(addi == ndv){
						flag = 0;
					}
					left_need.pop_front();
					if(flag){
						left_need.push_front(make_pair(upos,ndv - (a[i] - avg)));
					}
				}
				cout<<i<<" push "<<a[i] - avg<<" into "<<i+1<<endl;
				a[i+1] += a[i] - avg;
				ans += a[i] - avg;
			}else{
				left_need.push_back(make_pair(i,avg-a[i]));
			}
		}
		return ans;
	}*/
}
namespace subtask2{
	int b[MAXN];
	ll work(ll dp,ll now_ans,ll avg){
		for(int i = 1;i <= n;i++){
			b[i] = a[i];
		}
		ll ans = 0,pos = dp;
		bool st = 1;
		while(pos != dp || st == 1){
			st = 0;
			const int delta = b[pos] - avg;
			int nxt = pos + 1;
			if(nxt == n + 1)nxt = 1;
			b[nxt] += delta;
			ans += abs(delta);
			if(ans > now_ans)return now_ans + 1;
			pos = nxt;
		}
		return ans;
	}
	ll solve(){
		ll avg = sum / n,main_ans = 0x7fffffff * 1ll * (0x7fffffff / 4);
		for(int dp = 1;dp <= n;dp++){
			main_ans = min(main_ans,work(dp,main_ans,avg));
		}
		return main_ans;
	}
}
int main(){
	//freopen("candy.in","r",stdin);
	//freopen("candy.out","w",stdout);
	cin>>opt>>n;
//	opt = read(),n = read();
	for(int i = 1;i <= n;i++){
//		a[i] = read();
		cin>>a[i];
		sum += a[i];
	}
	cout<<subtask1::solve()<<endl;
//	if(opt == 0){
//		printf("%lld\n",subtask1::solve());
//	}else if(n <= 1000){
//		printf("%lld\n",subtask2::solve());
//	}
	return 0;
}

