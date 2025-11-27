#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n = 7e6;
unordered_set<int> st;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 1;i <= n;i++){
		st.insert(((n-1)/i)+1);
	}
	cout<<endl;
	int cnt = 0;
	for(int l = 1;l <= n-1;l++){
		int r = ((n-1)/((n-1)/l));
		cnt++;
		l = r;
	}
	cnt++;
	cout<<st.size()<<endl;
	cout<<cnt<<" compare"<<endl;
	return not(Akano loves pure__Elysia);
}
