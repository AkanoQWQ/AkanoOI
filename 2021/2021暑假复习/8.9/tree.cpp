#include<bits/stdc++.h>
using namespace std;
const int maxn = 198964;
long long n,i,ans,j,maxh[maxn],th[maxn],a,b,cache,maxpos,zero = 0;//tree_hight
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>a>>b;
		th[a] += b;
		maxpos = max(maxpos,a);
	}
	for(i = 0;i < n;i++){
		if(th[i] == 0)continue;
		for(j = i-1;j >= 0;j--){
			cache = i - j;
			if(maxh[j] <= cache&&maxh[j] != 0){
				break;
			}else{
				maxh[j] = cache;
			}
		}
		for(j = i+1;j <= maxpos;j++){
			cache = j - i;
			if(maxh[j] <= cache&&maxh[j] != 0){
				break;
			}else{
				maxh[j] = cache;
			}
		}
	}
	for(i = 0;i <= maxpos;i++){
		if(th[i] > maxh[i]){
			ans += max(th[i] - maxh[i],zero);
		}
	}
	cout<<ans;
	return 0;
}

