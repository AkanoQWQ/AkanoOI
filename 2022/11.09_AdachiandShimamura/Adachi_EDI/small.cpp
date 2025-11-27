#include<bits/stdc++.h>
#define int long long
#define mp make_pair
using namespace std;
int k;
deque<pair<int,int> > q;
bool vis[200006];
signed main(){
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);
	cin>>k;
	q.push_front(mp(1,1));
	while(!q.empty()){
		const int u = q.front().first,noww = q.front().second;
		q.pop_front();
		if(u == 0){
			cout<<noww;
			goto ed;
		}
		if(!vis[(u*10) % k]){
			q.push_front(mp((u*10) % k,noww));
			vis[(u*10) % k] = 1;
		}
		if(!vis[u+1]){
			q.push_back(mp(u+1,noww+1));
		}
	}
	ed:
	return 0;
}
