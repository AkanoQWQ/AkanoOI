#include<bits/stdc++.h>
using namespace std;
long long n,cache,ans;
priority_queue<long long> g;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>cache;
		g.push(-cache);
	}
	n--;
	while(n--){
		//cout<<g.top()<<endl;
		cache = g.top();
		g.pop();
		//cout<<g.top()<<endl;
		cache += g.top();
		g.pop();
		//cout<<"cache:"<<cache<<endl;
		ans -= cache;
		g.push(cache);
	}
	cout<<ans;
	return 0;
}


//
//10 1/3   31/6
//-2c-c
//-a-3c
