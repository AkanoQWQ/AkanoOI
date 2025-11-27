#include<bits/stdc++.h>
using namespace std;
int head,tail,k,km,houses[20006],ans = 99999999,n,i;
struct gone{
	int pos,len,went[20006],ws;
}gont[20006];
int main(){
	freopen("census.in","r",stdin);
	freopen("census.out","w",stdout);
	cin>>k>>n;
	for(km = 0;km < n;km++){
		cin>>houses[km];
	}
	tail = 1;
	ans = min((houses[n-1] - houses[0]),(houses[0] + k - houses[n-1]));
	/*while(tail > head){
		int L,R,length  = 0;
		if(gont[head].len > ans){
			head++;
			continue;
		}
		if(gont[head].ws >= n){
			ans = gont[head].ws;
			continue;
		}
		for(i = 0;i < n;i++){
			gont[tail].went[i] = gont[head].went[i];
		}
		L = gont[head].pos-1;
		R = gont[head].pos+1;
		if(L < 0){
			L = n - 1; 
		}
		R = gont[head].pos+1;
		if(R >= n){
			R = 0;
		}
		if(L == n - 1){
			length += houses[0];
			length += (k-houses[n-1]);
			gont[tail].pos = L;
			gont[tail].len = gont[head].len + length;
			if(gont[tail].went[L] != 1){
				gont[tail].ws++;
			}
			gont[tail].went[L] = 1;
			tail++;
		}else{
			length += (houses[L+1] - houses[L]);
			gont[tail].pos = L;
			gont[tail].len = gont[head].len + length;
			if(gont[tail].went[L] != 1){
				gont[tail].ws++;
			}
			gont[tail].went[L] = 1;
			tail++;
		}
		if(R == 0){
			length += houses[0];
			length += (k-houses[n-1]);
			gont[tail].pos = R;
			gont[tail].len = gont[head].len + length;
			if(gont[tail].went[L] != 1){
				gont[tail].ws++;
			}
			gont[tail].went[L] = 1;
			tail++;
		}else{
			length += (houses[R] - houses[R-1]);
			gont[tail].pos = R;
			gont[tail].len = gont[head].len + length;
			if(gont[tail].went[L] != 1){
				gont[tail].ws++;
			}
			gont[tail].went[L] = 1;
			tail++;
		}
		head++;
	}
	*/
	cout<<ans;
	return 0;
}

