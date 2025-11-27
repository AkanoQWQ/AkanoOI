#include<bits/stdc++.h>
using namespace std;
int t,n,ans[200006];
const int INF = 2147487;
string s;
char c;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>c>>s;
		int stg = -1,cnt = -INF,nerg = -1,out = -1;
		if(c == 'g'){
			cout<<0<<endl;
			continue;
		}
		for(int i = 0;i < n;i++){
			ans[i] = -1;
		}
		for(int i = n-1;i >= 0;i--){
			if(s[i] == 'g'){
				if(stg == -1)stg = i;
				cnt = 0;
				nerg = i;
			}
			if(cnt >= 0){
				ans[i] = cnt;
			}
			cnt++;
		}
		for(int i = n-1;i >= 0;i--){
			if(ans[i] != -1)break;
			ans[i] = nerg + n - i; 
		}
		for(int i = 0;i < n;i++){
			if(s[i] == c){
				out = max(out,ans[i]);
			}
		}
		cout<<out<<endl;
	}
	return 0;
}
