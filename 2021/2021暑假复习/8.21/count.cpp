#include<bits/stdc++.h>
using namespace std;//6000000
int n,q,x,y,a[4000006],k,ns[4000006],ts[4000006],tail,i,j,Q,ans,L,R,mid;
bool FOUND;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>Q;
	for(i = 1;i <= n;i++){
		cin>>a[i];
		FOUND = 0;
		for(j = 0;j < tail;j++){
			if(ns[j] == a[i]){
				FOUND = 1;
				break;
			}
		}
		if(!FOUND){
			ns[tail] = a[i];
			tail++;
		}
	}
	sort(ns,ns+tail);
	Q = 100;
	for(i = 0;i < Q;i++){
		cin>>x>>y;
		ans = 0;
		memset(ts,0,sizeof(ts));
		for(j = x;j <= y;j++){
			L = 0,R = tail-1;
			while(L < R){
				mid = ((L+R)>>1);//1 2 1
				//cout<<L<<" "<<R<<" "<<mid<<endl;
				//cout<<ns[mid]<<","<<a[j]<<endl; 
				if(ns[mid] == a[j]){
					//cout<<"ts["<<mid<<"]++"<<endl;
					ts[mid]++;
					break;
				}//1 3 5 6 7 8 9       5
				if(ns[mid] > a[j]){
					if(R == mid){
						R = mid-1;
					}else{
						R = mid; 
					}
				}else{
					if(L == mid){
						L = mid+1;
					}else{
						L = mid;
					}
				}
			}
			
		}
		for(j = 0;j < tail;j++){
			if(ts[j] == ns[j])ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

