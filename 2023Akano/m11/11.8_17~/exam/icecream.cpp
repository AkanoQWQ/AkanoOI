#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n;
double ans[22] = {1018.1108,0.0000000,0.6931472,1.0986123,1.3862944,1.7917595,1.7917595,2.4849066,2.7080502,2.9957323,3.4011974,3.4011974,4.0943446,4.0943446,4.4308168,4.4308168,4.9416424,4.9416424,5.3471075,5.3471075,5.6347896};
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("icecream.in","r",stdin);
	freopen("icecream.out","w",stdout);
	cin>>n;
	cout<<fixed<<setprecision(7)<<ans[n]<<endl;
	return not(Akano loves pure__Elysia);
}
