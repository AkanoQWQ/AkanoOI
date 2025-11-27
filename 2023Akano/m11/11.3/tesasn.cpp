#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n = 44,ans = 0;
inline int Sum(int l,int r){
	if(l > r)return 0;
	return (r - l + 1) * (l + r) / 2;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	cout<<ans<<endl;
	ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				for(int s = 1;s <= n;s++){
					ans += abs(i-k) + abs(j-s);
				}
			}
		}
	}
	ans /= 2;
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
