#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5+6;
ll n,h,t,a[MAXN],b[5]; 
int main(){
	cin>>t;
	while(t--){
		cin>>n>>h;
		ll orgh = h,ans = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		b[1] = 1,b[2] = 2,b[3] = 3;//green green blue
		do{
			b[0] = 0;
			h = orgh;
			ll pos = 1;
			for(int i = 0;i <= 3;i++){
				if(b[i] == 1 || b[i] == 2){
					h *= 2;
				}else if(b[i] == 3){
					h *= 3;
				}
				while(a[pos] < h && pos <= n){
					h += a[pos] / 2;
					pos++;
				}
				ans = max(ans,pos-1);
			}
		}while(next_permutation(b+1,b+4));
		cout<<ans<<endl;
	}
	return 0;
}
