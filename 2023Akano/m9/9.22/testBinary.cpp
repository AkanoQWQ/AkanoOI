#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int m = 300000000;
int ans = 264009490;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int l = 1,r = m+1;
	while(l < r){
		const int mid = (l + r) >> 1;
		if(mid == ans){
			cout<<"COR"<<endl;
		}else if(mid > ans){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	return not(Akano loves pure__Elysia);
}
