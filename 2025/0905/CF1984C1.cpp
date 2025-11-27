#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
long long t,n,a;
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		long long minn = 0,maxx = 0,temp1 = 0,temp2 = 0;
		while(n--){
			cin>>a;
			temp1 = minn,temp2 = maxx;
			temp1 = minn + a;
			temp1 = min(temp1,abs(minn + a));
			temp1 = min(temp1,maxx + a);
			temp1 = min(temp1,abs(maxx + a));
			temp2 = maxx + a;
			temp2 = max(temp2,abs(maxx + a));
			
			temp2 = max(temp2,minn + a);
			temp2 = max(temp2,abs(minn + a));
			minn = temp1,maxx = temp2;
		}
		cout<<maxx<<'\n';
	}
	cout<<flush;
	return not(Akano loves pure__Elysia);
}
