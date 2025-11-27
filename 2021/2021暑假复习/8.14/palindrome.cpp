#include<bits/stdc++.h>
using namespace std;
int n,a[202006],st/*stail*/,i,j,bi,sm,BE_HAVED/*已经有了*/,tong[202606],ans;
int main(){
	freopen("palindrome.in","r",stdin);
	freopen("palindrome.out","w",stdout);
	cin>>n;
	for(i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(n == 1){
		cout<<0;
		return 0;
	}
	for(i = 1;i <= n/2;i++){
		if(a[i] != a[n+1-i]){
			bi = max(a[i],a[n+1-i]),sm = min(a[i],a[n+1-i]);
			tong[bi] = 1,tong[sm] = 1;
		}
	}
	for(i = 0;i < 200206;i++){
		if(tong[i] > 0)ans++;
	}
	ans--;
	ans = max(ans,0);
	cout<<ans;
	return 0;
}
//1 5 3 2 5 2 3 1
//5,3 2,3 2,5
//2,3,5  1>2>3>1,1>4>5>1,1>6>7>1;
//1:6   2:2  3:2  4:2 5: 2 6:2 7:2
//
//1 2 1 3 1 5 1 4 1 6 1 7 1 6 7 7 6 5 5 1 4 1 3 3 2
