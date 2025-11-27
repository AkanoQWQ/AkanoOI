#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
int t,n,k;
int nowf[MAXN];
bool Judge(int pos){
	for(int i = pos;i >= 2;i--){
		if(nowf[i] < 0)return false;
		nowf[i-1] = nowf[i+1] - nowf[i];
		if(nowf[i-1] > nowf[i])return false;
	}
	return nowf[1] >= 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k;
		if(k > n + 10){
			cout<<0<<endl;
		}else{
			int cnt = 0;
			nowf[k] = n;
			for(int i = 0;i <= n;i++){
				nowf[k-1] = i;
				cnt += Judge(k-1);
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}

