#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans;
string str;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>str;
	str = "." + str;
	for(int i = 1;i <= n;i++){
		cnt += (str[i] == 'E');
	}
	ans = cnt;
	for(int i = 1;i <= n;i++){
		cnt -= (str[i] == 'E');
		cnt += (str[i] == 'W');
		ans = min(cnt,ans);
	}
	cout<<ans;
	return 0;
}
