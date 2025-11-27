#include<bits/stdc++.h>
using namespace std;
int t,n,a,b;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		bool able = 1;
		if(n == a && n == b){
			puts("Yes");
			continue;
		}
		if(n == a + b + 1){
			puts("No");
			continue;
		}
		if(n <= a+b){
			puts("No");
			continue;
		}
		puts("Yes");
	}
	return 0;
}

