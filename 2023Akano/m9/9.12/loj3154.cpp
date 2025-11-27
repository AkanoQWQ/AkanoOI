#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e6 + 1018 + 1108;
int n,a[MAXN],b[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i];
	}
	while(true){
		bool give = false;
		for(int i = 1;i <= n;i++){
			int res = ceil((a[i] - b[i]) / 2.0f);
			if(2 * res > a[i])res--;
			if(res > 0){
				a[i] -= res * 2;
				if(i == n){
					a[1] += res;
				}else{
					a[i+1] += res;
				}
				give = true;
			}
		}
		if(give == false)break;
	}
	for(int i = 1;i <= n;i++){
		if(a[i] != b[i]){
			cout<<"No"<<endl;
			return not(Akano loves pure__Elysia);
		}
	}
	cout<<"Yes"<<endl;
	return not(Akano loves pure__Elysia);
}

