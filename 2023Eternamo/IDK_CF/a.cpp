#include<bits/stdc++.h>
using namespace std;
const int MAXN = 106;
int t,n,a[MAXN];
map<int,int> use,cnt;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int tot = 0;
		cnt.clear();
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			cnt[a[i]]++;
			tot += a[i] * 2;
		}
		bool OK = false;
		for(int x = 1;x <= n;x++){
			for(int y = x+1;y <= n;y++){
				int sum = tot - a[x] - a[y];
				if(sum % (n-1) != 0)continue;
				use.clear();
				int now = a[x];
				use[now]++;
				bool thisOK = true;
				for(int i = 2;i <= n;i++){
					now = sum / (n-1) - now;
					use[now]++;
					if(use[now] > cnt[now]){
						thisOK = false;
						break;
					}
				}
				OK |= thisOK;
			}
		}
		if(OK){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
