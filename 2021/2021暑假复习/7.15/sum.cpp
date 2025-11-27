#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int t,n,m,i,a[100006],l,r;
int main(){
	freopen("sum.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){//1 2 3 4 5    1 3 6 10 15
								//1 5 4 -0   
		cin>>n>>m>>a[0];
		for(i = 1;i < n;i++){
			cin>>a[i];
			a[i] += a[i-1];
		}
		for(i = 0;i < m;i++){
			cin>>l>>r;
			if(l >= 2){
				cout<<a[r-1]-a[l-2]<<endl;
			}else{
				cout<<a[r-1]<<endl;
			}
		}
	}
	return 0;
}

