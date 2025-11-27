#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1018;
vector<int> vec[MAXN];
int n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		vec[i].push_back(0);
		int k,x;
		cin>>k;
		for(int i = 1;i <= k;i++){
			cin>>x;
			vec[i].push_back(x);
		}
	}
	return not(Akano loves pure__Elysia);
}

