#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n = 8000,m = 1e6;
set<pii> st;
pii rd(){
	int u = (rand() % n) + 1,v = (rand() % n) + 1;
	if(u > v)swap(u,v);
	return make_pair(u,v);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("easy4.in","w",stdout);
	cout<<n<<" "<<m<<endl;
	while(m--){
		pii e = rd();
		while(e.first == e.second || st.find(e) != st.end())e = rd();
		cout<<e.first<<" "<<e.second<<" "<<rand()<<endl;
	}
	return 0;
}

