#include<bits/stdc++.h>
using namespace std;
const long long maxn = 1008964;
long long r[maxn],l[maxn],n,h[maxn],t,c,i,ans;
int main(){
	freopen("board.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>h[i];
	}
	for(i = 0;i < n;i++){
		t = i;
		while(t > 0){
			if(h[t-1] >= h[i]){
				t--;
			}else{
				break;
			}
		}
		l[i] = t;
		t = i;
		while(t < n-1){
			if(h[t+1] >= h[i]){
				t++;
			}else{
				break;
			}
		}
		r[i] = t;
	}
	for(i = 0;i < n;i++){
		ans = max((r[i] - l[i] + 1) * h[i],ans);
	}
	cout<<ans;
	return 0;
}


