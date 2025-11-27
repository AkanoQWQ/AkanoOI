#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
ll n,k,ans;
priority_queue<ll,vector<ll>,greater<ll> > q;
int main(){
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		int c;
		cin>>c;
		q.push(c);
	}
	//因为每次会减少k-1个,最后剩下一个所以一共减少了n-1个 
	int res = ((k-1) - ((n-1) % (k-1))) % (k-1);
	for(int i = 1;i <= res;i++)q.push(0);//补全0 
	while(q.size() >= 2){
		ll newNode = 0;
		for(int i = 1;i <= k;i++){
			newNode += q.top();
			q.pop();
		}
		ans += newNode;
		q.push(newNode);
	}
	cout<<ans<<endl;
	return 0;
}
//原先错误原因:在最后一次合并的时候 up < k 相当于补全0
//然而,根据小根堆的原则应该把0补在前面更好 
