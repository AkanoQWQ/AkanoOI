#include<bits/stdc++.h>
using namespace std;
int t,n,ret,gr,apple1,apple2,ans1,ans2,onl,firmid = -1,l,r,lastl,lastr,lastmid,qry;
int test[1];
int find(int l,int r){
	if(l == r)return l;
	while(l < r){
		int mid = (l + r) >> 1;
		++qry;
		cout<<"? "<<mid - l + 1<<" ";
		for(int i = l;i <= mid;i++){
			cout<<i<<" ";
		}
		cout<<endl;
		cin>>ret;
		cout<<flush;
		if(ret == 1){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	return l;
}
int main(){
	cin>>t;
	while(t--){
		apple1 = -1,apple2 = -1,firmid = -1,lastl = -1,lastr,lastmid,qry = 0;
		cin>>n;
		l = 1,r = n;
		while(l < r){//going left
			int mid = (l + r) >> 1;
			++qry;
			cout<<"? "<<mid<<" ";
			for(int i = 1;i <= mid;i++){
				cout<<i<<" ";
			}
			cout<<endl;
			cin>>ret;
			cout<<flush; 
			if(ret == 1){
				lastl = l,lastr = r,lastmid = mid;
				break;
			}else{
				r = mid;
			}
		}
		if(lastl == -1){
			l = (l + r) >> 1;
			r = n;
			while(l < r){//going right
				int mid = (l + r) >> 1;
				++qry;
				cout<<"? "<<r-mid+1<<" ";
				for(int i = mid;i <= r;i++){
					cout<<i<<" ";
				}
				cout<<endl;
				cin>>ret;
				cout<<flush; 
				if(ret == 1){
					lastl = l,lastr = r,lastmid = mid;
					break;
				}else{
					l = mid + 1;
				}
			}
		}
		int apple1 = find(lastl,lastmid);
		int apple2 = find(lastmid+1,lastr);
		if(qry > 19 && n != 1000){
			cout<<test[123123123]<<endl;
		}
		cout<<"! "<<apple1<<" "<<apple2<<endl;	
		cout<<flush;
	}
	return 0;
}
