#include<bits/stdc++.h>
using namespace std;
int i,j,n,k,t[1000],DOSTH,cnn,c,sum;
int m[2006110],mtail,cha,a[1000],b[1000],ans = 99999,rans;
bool comp(int a,int b){
	return a > b;
}
int search(int k){
	int i,c;
		for(i = 0;i < n;i++){
			if(!b[i]){//数字未被使用过（条件） 
			b[i] = 1;
			a[k] = t[i];
			c = 0;
			for(j = 0;j < k;j++){
				c += a[j];
			}
			if(sum%2 == 0){
				if(abs(c - (sum - c)) < ans)ans = abs(c - (sum - c));
			}else{
				if(abs(c - (sum - c) ) < ans)ans = max(abs(c - (sum - c)),1);
			}
			
			//cout<<c<<":"<<ans<<endl;
			if(k < n && c - (sum - c) <= 0){
				search(k+1);
			}	
			b[i] = 0;
		}
	}
}
int main(){
	freopen("cook.in","r",stdin);
	freopen("cook.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>t[i];
		sum += t[i];
	}
	//cout<<sum<<endl; 
	sort(t,t+n);
	search(0);
	rans = (sum+ans) / 2;
	//cout<<ans<<endl;
	cout<<rans;
	return 0;
}
