#include<bits/stdc++.h>
using namespace std;
int i,j,ans,cache,n,m,k,s,l,r,ji;
long long mrs[1000006];
int main(){
	freopen("mrs.in","r",stdin);
	cin>>n>>m;
	for(i = 0;i < n;i++){
		cin>>mrs[i];
	}
	n--;
	for(i = 0;i < m;i++){
		cin>>k;
		s = n/2;
		l = 0,r = n;
		ji = -1;
		ans = 0;
		while(s >= 0 && s <= n && l != r){
			if(mrs[s] == k){
				ji = k;
				break;
			}
			if(mrs[s] < k){//3  5             3 4 5
				l = s;
				s = (l+r) / 2;
			}
			if(mrs[s] > k){
				r = s;
				s = r / 2;
			}
			if(s == 0 || s == n){
				if(mrs[s] == k){
					ji = k;
				}
				break;
			}
			
		}
		if(ji != 0){
			ji--;
		}
		if(ji == -1){
			cout<<0<<" ";
		}else{
			cout<<ji;
			l = ji,r = ji+1;
			while(mrs[l] == k){
				ans++;
				if(l == 0){
					break;
				}
				l--;
			}
			while(mrs[r] == k){
				ans++;
				if(r == n){
					break;
				}
				r++;
			}
			cout<<ans<<" ";
		}
	}
	return 0;
}
