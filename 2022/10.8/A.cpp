#include<bits/stdc++.h>
using namespace std;
const int MAXN = 106;
int t,n;
int a[MAXN],b[MAXN];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int a1 = 0,b1 = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		for(int i = 1;i <= n;i++){
			cin>>b[i];
		}
		for(int i = 1;i <= n;i++){
			if(a[i] == 1 && b[i] == 0){
				a1++;
			}
			if(a[i] == 0 && b[i] == 1){
				b1++;
			}
		}
		cout<<min(abs(a1-b1)+1,a1+b1)<<endl;
	}
	return 0;
}
