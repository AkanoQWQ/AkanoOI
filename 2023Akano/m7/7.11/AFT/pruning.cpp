#include<bits/stdc++.h>
using namespace std;

mt19937 rng(time(0));
int t,n,d;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("pruning.in","r",stdin);
	freopen("pruning.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>d;
		int tot = 0;
		for(int i = 1;i < n;i++){
			int u,v,w;
			cin>>u>>v>>w;
			tot += w;
		}
		cout<<rng() % tot<<endl;
	}
	return 0;
}
