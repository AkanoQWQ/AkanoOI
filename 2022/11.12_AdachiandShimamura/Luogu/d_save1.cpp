#include<bits/stdc++.h>
using namespace std;
int t,n,ret,gr,apple1,apple2,ans1,ans2,onl,firmid = -1;
int main(){
	cin>>t;
	while(t--){
		apple1 = -1,apple2 = -1,firmid = -1;
		cin>>n;
		int l = 1,r = n;
		while(l < r){
			int mid = (l + r) >> 1;
			cout<<"? "<<mid-l+1<<" ";
			for(int i = l;i <= mid;i++){
				cout<<i<<" ";
			}
			cout<<flush;
			cin>>ret;
			if(ret == 1){
				if(firmid == -1)firmid = mid;
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		apple1 = r;
		/*if(apple1 >= 2){
			cout<<"? "<<r-1<<" ";
			for(int i = 1;i < r;i++){
				cout<<i<<" ";
			}
			cout<<flush;
			cin>>ret;
		}else{
			ret = 1;
		}
		if(ret == 0){//ÔÚ×ó±ß 
			l = 1,r = apple1;
			onl = 1;
		}else{
			l = apple1 + 1,r = n;
			onl = 0;
		}*/
		l = firmid,r = r;
		while(l < r){
			int mid = (l + r) >> 1;
			cout<<"? "<<mid-l+1<<" ";
			for(int i = l;i <= mid;i++){
				cout<<i<<" ";
			}
			cout<<flush;
			cin>>ret;
			if(ret == 1){
				r = mid;
			}else{
				l = mid + 1;
			}
		}																
		apple2 = l;														
		cout<<"! "<<min(apple1,apple2)<<" "<<max(apple1,apple2)<<endl;	
		cout<<flush;
	}
	return 0;
}
