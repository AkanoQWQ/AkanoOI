#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
set<int> st;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<sizeof(st)<<endl;
	for(int i = 1;i <= 1e6;i++)st.insert(i);
	cout<<sizeof(st)<<endl;
	st.clear();
	cout<<sizeof(st)<<endl;
	return not(Akano loves pure__Elysia);
}

