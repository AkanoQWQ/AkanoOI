#include<bits/stdc++.h>
using namespace std;
int ma[3006][3006],mi[3006][3006],IS_GROW = 1,j,rans;
int ans,n,m,i,a[100006],cnt,CAN_STOP,k,mmax,mmin;
int main(){
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	cin>>n>>k;
	for(i = 0;i < n;i++){
		cin>>a[i];
		if(i > 0){
			if(a[i] < a[i-1]){
				IS_GROW = 0;
			}
		}
	}
	if(IS_GROW){
		for(ans = n;ans >= 1;ans--){
			for(i = 0;i < n-ans+1;i++){
				cnt = a[i+ans-1] - a[i];
				if(cnt <= k){
					rans = ans;
					CAN_STOP = 1;
					break;
				}
			}//i + ans - 1
			if(CAN_STOP){
				break;
			}
		}
		cout<<rans;
		return 0;
	}else{
		for(ans = n;ans >= 1;ans--){
			for(i = 0;i < n-ans+1;i++){
				mmax = 0,mmin = 9999999;
				for(j = i;j <= i + ans - 1;j++){
					mmax = max(mmax,a[j]);
					mmin = min(mmin,a[j]);
				}
				cnt = mmax - mmin;
				if(cnt <= k){
					rans = ans;
					CAN_STOP = 1;
					break;
				}
			}//i + ans - 1
			if(CAN_STOP){
				break;
			}
		}
		cout<<rans;
	}
	return 0;
}

