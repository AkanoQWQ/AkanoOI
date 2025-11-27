#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXVAL = 1e9;
int n = 4e4,k = 2;
vector<int> num;
Rander rd;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("CF549F.in","w",stdout);
	cout<<n<<" "<<k<<endl;
	for(int i = 1;i <= 20;i++){
		num.push_back(rd(1,MAXVAL));
	}
	int sz = num.size();
	for(int i = 1;i <= n;i++){
		cout<<num[rd(0,sz-1)]<<" ";
	}
	return not(Akano loves pure__Elysia);
}

